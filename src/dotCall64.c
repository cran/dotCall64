#include "dotCall64.h"

// MAYBE_SHARED is not available in R 3.0.1
#ifndef MAYBE_SHARED
#define MAYBE_SHARED(x) (NAMED(x) > 1)
#define NO_REFERENCES(x) (NAMED(x) == 0)
#define MAYBE_REFERENCED(x) (! NO_REFERENCES(x))
#endif

/* See http://cran.r-project.org/doc/manuals/R-exts.html#C_002dlevel-messages */
#ifdef ENABLE_NLS
#include <libintl.h>
#define _(String) dgettext ("dotCall64", String)
#else
#define _(String) (String)
#endif







/* Maximum length of entry-point name, including null terminator */
// copied from dotcode.c:69
#define MaxSymbolBytes 1024

/* Define PATH_MAX for GNU/Hurd */
#ifndef PATH_MAX
#define PATH_MAX 4096
#endif


/* Attributes like PACKAGE have to be prefixed in order to not get interpreted by .External(...) */
#define SYMBOL_PREFIX "dotCall64"


extern void dotCall64_callFunction(DL_FUNC fun, int nargs, void **cargs);
static void argsfind(SEXP args_in, SEXP *args, SEXP *names,int *len, char *packageName, SEXP *signature, SEXP *intent, SEXP *naok, SEXP *verbose);
static void prepareArguments(DL_FUNC fun, int nargs, SEXP *args,
		SEXPTYPE *do_type, int *do_alloc, int *do_coerce,
			     int *do_duplicate, int *do_cast_in, int *do_cast_back, int* flag_naok);

static SEXP getListElement(SEXP list, const char *str);
static int dotCall64str2type(SEXP s);

static SEXP allocInitializedVector(int type, R_xlen_t length);

/* These are set during the first call to do_dotCode() below. */

static SEXP PkgSymbol = NULL;
static SEXP SignatureSymbol = NULL;
static SEXP IntentSymbol = NULL;
static SEXP NaokSymbol = NULL;
static SEXP VerboseSymbol = NULL;


int str2intent(SEXP str) {

	const char *p = CHAR(str);

	int x = 0; // Clear any bits
	for(int i=0; i<strlen(p); i++) {
		switch(p[i]) {
		case('r'): x |= INTENT_READ; break;
		case('w'): x |= INTENT_WRITE; break;
//		case('c'): x |= INTENT_COPY; break;      // disabled
//		case('s'): x |= INTENT_SPEED; break;
		default: error(_("unknown intent '%c'"), p[i]);
		}
	}
	return x;
}




SEXP dC64(SEXP args_in) {

	SEXP s, signature, intent, naok, verbose, answer;
        int na, flag_naok, flag_verbose;
	const char *p;

	DL_FUNC fun = NULL;
	
	// Contains the number of arguments to be passed.
	int nargs;
	// Contains the name of the function
	char symName[MaxSymbolBytes];
	// Contains the name of the package defining the function
	char packageName[PATH_MAX];

	SEXP args[MAX_ARGS];
	SEXP args_names[MAX_ARGS];

	int n_protect = 0; // counts how many times PROTECT has been called.

	// The first argument contains the value "dotCall64", as it is the first argument given to .External(...).
	args_in = CDR(args_in);

	// Check if the required first argument .NAME is available:
	if (length(args_in) < 1)
		error(_("argument '.NAME' is missing (dotCall64)"));
	if (TAG(args_in) != R_NilValue) {
		if(TAG(args_in) != install("name")) {
			error(_("the argument '.NAME' should have name \"name\" or should not be named (dotCall64)"));
		}
	}

	// Copy the symbol name:
	p = translateChar(STRING_ELT(CAR(args_in), 0));
	if(strlen(p) > MaxSymbolBytes - 1)
		error(_("argument '.NAME' is too long (dotCall64)"));
	strcpy(symName, p);

	// Move to the next argument:
	args_in = CDR(args_in);

	// Get the effective arguments:
	argsfind(args_in, args, args_names, &nargs, packageName, &signature, &intent, &naok, &verbose);
	// We do not need to PROTECT args and args_names, because they are protected by being a subobject of args_in.

	// Check the NAOK argument
	if(!naok || LENGTH(naok) != 1)
		error(_("argument 'NAOK' has to be of length 1 (dotCall64)"));
	flag_naok = asInteger(naok);
 

	// Check the VERBOSE argument
	if(!verbose || LENGTH(verbose) != 1)
		error(_("argument 'VERBOSE' has to be of length 1 (dotCall64)"));
	flag_verbose = asInteger(verbose);
        if(!(flag_verbose == 0 || flag_verbose == 1 || flag_verbose == 2))
		  error(_("agrument 'VERBOSE' has to be one of 0, 1, or 2 (dotCall64)"));

	// Find the function
	fun = R_FindSymbol(symName, packageName, NULL);
	if(!fun) {
		// Check if we find the symbol with an appended '_' for Fortran:
		int symlength = strlen(symName);
		symName[symlength] = '_';
		symName[symlength+1] = 0;

		fun = R_FindSymbol(symName, packageName, NULL);
		if(!fun)
			error(_("symbol '%s' not found in package '%s' (dotCall64)"), symName, packageName);
	}

	// We cannot check if the number of given arguments equals to the number of expected arguments because
	// R_RegisteredNativeSymbol is declared as private API.


	// Any argument of class "vector_dc" must be expanded to the correct type
	for(na = 0; na < nargs; na++) {
		s = args[na];
		if(Rf_inherits(s, "vector_dc")) {
			R_xlen_t len = 0;
			int type = dotCall64str2type(STRING_ELT(getListElement(s, "mode"), 0));
			len = asReal(getListElement(s, "length"));
			if(flag_verbose == 2)
			   warning(_("[dotCall64|vector_dc] argument %d; allocate vector of type %s (%d); length %d"), na+1,  
                                            CHAR(STRING_ELT(getListElement(s, "mode"), 0)), type, len);
			args[na] = PROTECT(allocInitializedVector(type, len));
			n_protect++;
		}
	}


	// First we determine the current types of the vectors, as they represent the default types:
	int args_type[MAX_ARGS];
	int args_intent[MAX_ARGS];
	SEXP sexpargs[MAX_ARGS];
	for(na = 0; na < nargs; na++) {
		s = args[na];
		args_type[na] = TYPEOF(s);
		args_intent[na] = INTENT_READ | INTENT_WRITE; // Default intent is {write, read}
		sexpargs[na] = s;
	}

	// Second, adjust the arguments that are overwritten by SIGNATURE
	if(!signature) {
	  error(_("argument 'SIGNATURE' is missing (dotCall64)"));
	}
	if(LENGTH(signature) != nargs)
		error(_("length of argument 'SIGNATURE' does not equal to the number of arguments (dotCall64)"));

	for(na = 0; na < LENGTH(signature); na++) {
		int type = dotCall64str2type(STRING_ELT(signature, na));
		if(type < 0)
			error(_("signature of argument %d not recognized (%s) (dotCall64)"), na+1, CHAR(STRING_ELT(signature, na)));
		args_type[na] = type;
	}

	// Third, adjust the intents that are overwritten by INTENT:
	if(intent) {
		if(LENGTH(intent) != nargs)
			error(_("length of argument 'INTENT' does not equal to the number of arguments (dotCall64)"));

		for(na = 0; na < LENGTH(intent); na++) {
			switch(TYPEOF(intent)) {

			case STRSXP:
				{
				args_intent[na] = str2intent(STRING_ELT(intent, na));
				}
				break;
			}
		}
	}


	// Determine if the arguments are named and keep the names if true.
	SEXP names = NULL;
	Rboolean havenames = FALSE;
	for(na = 0; na < nargs; na++) {
		if (args_names[na] != R_NilValue) havenames = TRUE;
	}
	if (havenames) {
		PROTECT(names = allocVector(STRSXP, nargs));
		n_protect++;
		for (na = 0; na < nargs; na++) {
			if (args_names[na] == R_NilValue)
				SET_STRING_ELT(names, na, R_BlankString);
			else
				SET_STRING_ELT(names, na, PRINTNAME(args_names[na]));
		}
	}


	// Call the function.
	dotCall64(fun, nargs, sexpargs, args_type, args_intent, flag_naok, flag_verbose);


	// Protect every 'write' argument returned by dotCall64.
	for (na = 0 ; na < nargs; na++) {
		if(!HAS_INTENT_WRITE(args_intent[na]))
			continue;

		PROTECT(sexpargs[na]);
		n_protect++;
	}

	PROTECT(answer = allocVector(VECSXP, nargs));
	n_protect++;

	// Add the argument names, if available.
	if (names) {
		setAttrib(answer, R_NamesSymbol, names);
	}
	// Add the arguments to the answer
	// Only the arguments that have INTENT_WRITE will be added to the answer environment.
	for(na = 0; na<nargs; na++) {
		if(!HAS_INTENT_WRITE(args_intent[na])) {
			// Only write-arguments are returned
			SET_VECTOR_ELT(answer, na, R_NilValue);
			continue;
		}
		SET_VECTOR_ELT(answer, na,  sexpargs[na]);
	}

	UNPROTECT(n_protect);
	return(answer);
}


void dotCall64(DL_FUNC fun, int nargs, SEXP *args, int *args_type, int *args_intent_in, int flag_naok, int flag_verbose) {

	int na;
	// The do_ variables contain the instructions for the 'prepareArguments(...)' function.
	SEXPTYPE do_type[MAX_ARGS]; //
	int do_alloc[MAX_ARGS]; //
	int do_coerce[MAX_ARGS];
	int do_duplicate[MAX_ARGS];
	int do_cast_in[MAX_ARGS];
	int do_cast_back[MAX_ARGS];
	int args_intent[MAX_ARGS]; // We duplicate args_intent_in, as we have to modify it if an argument is given multiple times

	if(nargs > MAX_ARGS)
		error(_("dotCall64 only supports up to 64 arguments (dotCall64)"));

	// When an object is given multiple times as an argument, we have to be careful. 
	// To exclude any side effects, we duplicate every object when its INTENT is write. 
	// If the type is int64, we duplicate it in every case.
	for(na = 0; na < nargs; na++) {
		args_intent[na] = args_intent_in[na];
	}
	for(na = 0; na < nargs; na++) {
		for(int nb = na+1; nb < nargs; nb++) {
			if(args[na] == args[nb]) {
				args_intent[na] |= INTENT_SPEED | INTENT_COPY;
				args_intent[nb] |= INTENT_SPEED | INTENT_COPY;
				break;
			}
		}
	}



	// Populate the do_<XXX> variables by the rules defined in the flowchart:
	for(na = 0; na < nargs; na++) {
		SEXP s = args[na];

		// Initialize the do_ variables:
		do_type[na] = -1;
		do_alloc[na] = 0;
		do_coerce[na] = 0;
		do_duplicate[na] = 0;
		do_cast_in[na] = 0;
		do_cast_back[na] = 0;


		int maybe_referenced = MAYBE_REFERENCED(s);
		int maybe_shared = MAYBE_SHARED(s);  // Unused


		// Determine the expected R type of the object.
		if(args_type[na] == INT64_TYPE) {
			// int64 is based on the double type.
			do_type[na] = REALSXP;
		}else{
			do_type[na] = args_type[na];
		}

		// Check if a warning should be raised in case the provided argument type dose not match the expected type.
		if(flag_verbose >= 1 && TYPEOF(s)!=do_type[na]) {
			warning(_("[dotCall64|wrong R object type] argument %d; expected type '%s'; got type '%s'; argument coerced"),
					na+1, type2char(do_type[na]), CHAR(type2str(TYPEOF(s))));
		}

		// Start flowchart.
		if(HAS_INTENT_WRITE(args_intent[na]) && !HAS_INTENT_READ(args_intent[na])) {
			// Right part of the flowchart.
			// Intent = w
			if(TYPEOF(s) == do_type[na] && !maybe_referenced) {
				// We can just pass the object as argument.
			}else{
				// We need a new object for the return value.
			         if(flag_verbose >= 1 && maybe_referenced) {
				     warning(_("[dotCall64|referenced 'w' argument] argument %d has 'INTENT' 'w' and is referenced.\nConsider using vector_dc() to avoid copying."),
                                             na+1);
				 }
			        do_alloc[na] = 1;
			}

			// Check if we have to cast back.
			if(args_type[na] == INT64_TYPE) {
				do_cast_back[na] = 1;
			}

		}else if(args_type[na] == INT64_TYPE) {
			// Left part of the flowchart.
			// Argument of type int_64 with intents r, rw.

			if(TYPEOF(s) == INTSXP || TYPEOF(s) == REALSXP) {
				do_alloc[na] = 1;
			}else{
				do_coerce[na] = 1;
			}

			// As the argument is read, we have to cast from double->int64.
			do_cast_in[na] = 1;

			if(HAS_INTENT_WRITE(args_intent[na])) {
				do_cast_back[na] = 1;
			}

		}else{
			// Center part of the flowchart
			// Argument of native type.
			if(TYPEOF(s)!=do_type[na]) {
				// wrong type.
				do_coerce[na] = 1;
			}else if(HAS_INTENT_WRITE(args_intent[na])) {
				// intent= rw.
				do_duplicate[na] = 1;
			}
		}

		if(flag_verbose == 2){
			warning(_("[dotCall64|flags] arg %d: type %s (%d); alloc %d; coerce %d; dup %d;\ncast.in %d; cast.back %d; named: %d, mb-ref %d; mb-shared %d\n"),
	                           na+1, type2char(do_type[na]), do_type[na], do_alloc[na],
				do_coerce[na], do_duplicate[na], do_cast_in[na], do_cast_back[na],
			           NAMED(s), maybe_referenced, maybe_shared);
		}
	}

	prepareArguments(fun, nargs, args,
			do_type, do_alloc, do_coerce,
			 do_duplicate, do_cast_in, do_cast_back, &flag_naok);

}

static void prepareArguments(DL_FUNC fun, int nargs, SEXP *args,
		SEXPTYPE *do_type, int *do_alloc, int *do_coerce,
			     int *do_duplicate, int *do_cast_in, int *do_cast_back, int *flag_naok) {

	int na;
	void **cargs[MAX_ARGS]; // pointers for the actual function.
	SEXP args_in[MAX_ARGS]; // contains a copy of the given arguments.

	int n_protect = 0; // counts how many times PROTECT has been called.

	// Copy the argument (for efficient int64 casting).
	for(na=0; na < nargs; na++)
		args_in[na] = args[na];

	for(na = 0; na < nargs; na++) {
		SEXP s = args[na];
		R_xlen_t len = (R_xlen_t) XLENGTH(s);

		if(do_alloc[na]) {
			args[na] = PROTECT(allocInitializedVector(do_type[na], len));
			n_protect++;
		}else if(do_coerce[na]) {
			args[na] = PROTECT(coerceVector(s, do_type[na]));
			n_protect++;
			args_in[na] = args[na]; // If coerce, pretend that this object was provided
		}else if(do_duplicate[na]) {
			args[na] = PROTECT(duplicate(s));
			n_protect++;
		}

		// We will now work on the new object.
		s = args[na];
		

			// NAOK
		if(*flag_naok == 0){
			if(TYPEOF(args_in[na]) == REALSXP) {
				double *rptr = REAL(args_in[na]);
				//#pragma omp parallel for default(none) shared(len, rptr) private(i)
				for(int i=0; i < len; i++) {
					if(!R_FINITE(rptr[i]))
						error(_("NAs in argument %d and 'NAOK = FALSE' (dotCall64)"), na + 1);
				}
			} else if(TYPEOF(args_in[na]) == INTSXP) {
				int *iptr = INTEGER(args_in[na]);
				//#pragma omp parallel for default(none) shared(len, iptr) private(i)
				for(int i=0; i < len; i++) {
					if(iptr[i] == NA_INTEGER)
						error(_("NAs in argument %d and 'NAOK = FALSE' (dotCall64)"), na + 1);
				}
			}
		}



		// prepare the pointers
		switch(TYPEOF(s)) {
		case REALSXP:
			cargs[na] = (void*) REAL(s);
			break;

		case LGLSXP:
		case INTSXP:
			cargs[na] = (void*) INTEGER(s);
			break;

		case RAWSXP:
			cargs[na] = (void*) RAW(s);
			break;

		default:
			error(_("cannot yet handle type '%s' (arg %d) (dotCall64)"), type2char(TYPEOF(s)), na + 1);
		}
	}


	// Coerce arguments of type int64 (from double -> int64_t).
	// We cannot do this earlier as the memory of the object might be overwritten, and hence, any call to 'error()' would
	// destroy the object.
	for(na = 0; na < nargs; na++) {
		SEXP s = args[na];


		// double -> int64_t
		if(do_cast_in[na]) {
			R_xlen_t i, len;
			len = XLENGTH(s);

			// We will cast into this pointer.
			int64_t *iptr = (int64_t*) REAL(s);

			// All other types have been coerced to REALSXP.
			// We handle INTSXP separately
			if(TYPEOF(args_in[na]) == REALSXP) {
				double *in_ptr = REAL(args_in[na]);

#pragma omp parallel for default(none) shared(len, iptr, in_ptr) private(i)
				for(i=0; i < len; i++) {
					// #1
					iptr[i] = (int64_t) in_ptr[i];
				}
			}else if(TYPEOF(args_in[na]) == INTSXP) {
				int *in_ptr = INTEGER(args_in[na]);

#pragma omp parallel for default(none) shared(len, iptr, in_ptr) private(i)
				for(i=0; i < len; i++) {
					// #1
					iptr[i] = (int64_t) in_ptr[i];
				}
			}else{
			        error(_("should not happen: internal error (do_cast_in) (dotCall64)"));
			}
		}
	}

	// Finally, call the function.
	dotCall64_callFunction(fun, nargs, (void**)cargs);


	// Back cast the values of all arguments of type int64.
	for(na = 0; na < nargs; na++) {
		SEXP s = args[na];

		if(do_cast_back[na]) {
			R_xlen_t i, len;
			len = XLENGTH(s);

			int64_t *iptr = (int64_t*) cargs[na];
			double *dptr = (double*) cargs[na];

#pragma omp parallel for default(none) shared(len, iptr, dptr) private(i)
			for(i=0; i < len; i++) {
// #2
				dptr[i] = (double) iptr[i];
			}
		}
	}

	UNPROTECT(n_protect);
}




// Inspired by static SEXP naokfind(SEXP args, int * len, int *naok, int *dup, DllReference *dll)
static void argsfind(SEXP args_in, SEXP *args, SEXP *names,int *len, char *packageName, SEXP *signature, SEXP *intent, SEXP *naok, SEXP *verbose)
{
	SEXP s;
	int nargs=0, pkgused=0, sigused=0, intused=0, naokused=0, verbused=0;
	const char *p;

	// Attribute containing the
	if (PkgSymbol == NULL || SignatureSymbol == NULL) {
		PkgSymbol = install("f.PACKAGE");
		SignatureSymbol = install("SIGNATURE");
		IntentSymbol = install("INTENT");
		NaokSymbol = install("NAOK");
		VerboseSymbol = install("VERBOSE");
	}

	// Initialize to an empty string
	strcpy(packageName, "");
	*signature = NULL;
	*intent = NULL;
	*naok = NULL;
	*verbose = NULL;

	for(s = args_in; s != R_NilValue;) {

		if(TAG(s) == PkgSymbol) {
			if(TYPEOF(CAR(s)) == STRSXP) {
				p = translateChar(STRING_ELT(CAR(s), 0));
				if(strlen(p) > PATH_MAX - 1)
					error(_("DLL name is too long (dotCall64)"));
				strcpy(packageName, p);
				if(pkgused++ > 0)
					error(_("formal argument '%s' matched by multiple actual arguments (dotCall64)"), "PACKAGE");
			} else {
				error(_("formal argument 'PACKAGE' has wrong type (\"%s\"). Expected type: \"character\" (dotCall64)"),
						type2char(TYPEOF(CAR(s))));
			}
		} else if(TAG(s) == SignatureSymbol) {
			if(TYPEOF(CAR(s)) == STRSXP) {
				*signature = CAR(s);
				if(sigused++ > 0)
					error(_("formal argument '%s' matched by multiple actual arguments (dotCall64)"), "SIGNATURE");
			} else {
				error(_("formal argument 'SIGNATURE' has wrong type (\"%s\"). Expected type: \"character\" (dotCall64)"),
						type2char(TYPEOF(CAR(s))));
			}
		} else if(TAG(s) == IntentSymbol) {
			switch(TYPEOF(CAR(s))) {
			case STRSXP:
				*intent = CAR(s);
				if(intused++ > 0)
					error(_("formal argument '%s' matched by multiple actual arguments (dotCall64)"), "INTENT");
				break;
			case NILSXP:
				// behave as if no argument was given
				break;

			default:
				error(_("formal argument 'INTENT' has wrong type ('%s'). Expected type: \"character\" (dotCall64)"),
						type2char(TYPEOF(CAR(s))));
			}
		} else if(TAG(s) == NaokSymbol) {
			if(TYPEOF(CAR(s)) == LGLSXP) {
				*naok = CAR(s);
				if(naokused++ > 0)
					error(_("formal argument '%s' matched by multiple actual arguments (dotCall64)"), "VERBOSE");
			} else {
			  error(_("formal argument 'NAOK' has wrong type (\"%s\"). Expected type: \"logical\" (dotCall64)"),
						type2char(TYPEOF(CAR(s))));
			}
		} else if(TAG(s) == VerboseSymbol) {
			if(TYPEOF(CAR(s)) == INTSXP || TYPEOF(CAR(s)) == REALSXP) {
				*verbose = CAR(s);
				if(verbused++ > 0)
					error(_("formal argument '%s' matched by multiple actual arguments (dotCall64)"), "VERBOSE");
			} else {
			  error(_("formal argument 'VERBOSE' has wrong type (\"%s\"). Expected type: \"numeric\" or \"integer\" (dotCall64)"),
						type2char(TYPEOF(CAR(s))));
			}
		} else {
			args[nargs] = CAR(s);
			names[nargs] = TAG(s);
			nargs++;
		}
		s = CDR(s);
	}
	*len = nargs;
}


static SEXP getListElement(SEXP list, const char *str)
{
    SEXP elmt = R_NilValue, names = getAttrib(list, R_NamesSymbol);

    for (int i = 0; i < length(list); i++) {
		if(strcmp(CHAR(STRING_ELT(names, i)), str) == 0) {
		    elmt = VECTOR_ELT(list, i);
		    break;
		}
	}
    return elmt;
}


static int dotCall64str2type(SEXP s) {
	const char *str = CHAR(s);

	if(strcmp(str, INT64_STRING) == 0) {
		return INT64_TYPE;
	}else if(strcmp(str, "int") == 0) {
		return INTSXP;
	}else if(strcmp(str, "int32") == 0) {
		return INTSXP;
	}

	return str2type(str);
}




static SEXP allocInitializedVector(int type, R_xlen_t length) {
	SEXP s = PROTECT(allocVector(type, length));

	switch(TYPEOF(s)) {
		case REALSXP:
			Memzero(REAL(s), length);
			break;
		case INTSXP:
			Memzero(INTEGER(s), length);
			break;
		default:
			error("type \"%s\" not yet supported by allocInitializedVector (dotCall64)", type2char(TYPEOF(s)));
	}
	UNPROTECT(1);
	return s;
}
