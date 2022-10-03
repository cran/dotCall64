#include<R.h>
#include<Rinternals.h>
#include<R_ext/Rdynload.h>
#include<stdio.h>


/* See http://cran.r-project.org/doc/manuals/R-exts.html#C_002dlevel-messages */
#ifdef ENABLE_NLS
#include <libintl.h>
#define _(String) dgettext ("pkg", String)
/* replace pkg as appropriate */
#else
#define _(String) (String)
#endif



/*

The following lines are copied from R source:
  src/main/dotcode.c:585-858
  src/main/dotcode.c:2063-2654

*/

typedef SEXP (*FUNS1)(SEXP);
typedef SEXP (*FUNS2)(SEXP, SEXP);
typedef SEXP (*FUNS3)(SEXP, SEXP, SEXP);
typedef SEXP (*FUNS4)(SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS5)(SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS6)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS7)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS8)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS9)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS10)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS11)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP);
typedef SEXP (*FUNS12)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP);
typedef SEXP (*FUNS13)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS14)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS15)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS16)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS17)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS18)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS19)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS20)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP);
typedef SEXP (*FUNS21)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP);
typedef SEXP (*FUNS22)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS23)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS24)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS25)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS26)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS27)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS28)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS29)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP);
typedef SEXP (*FUNS30)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP);
typedef SEXP (*FUNS31)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS32)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS33)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS34)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS35)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS36)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS37)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS38)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP);
typedef SEXP (*FUNS39)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP);
typedef SEXP (*FUNS40)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS41)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS42)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS43)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS44)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS45)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS46)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS47)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP);
typedef SEXP (*FUNS48)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP);
typedef SEXP (*FUNS49)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS50)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS51)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS52)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS53)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS54)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS55)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS56)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP);
typedef SEXP (*FUNS57)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP);
typedef SEXP (*FUNS58)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS59)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS60)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS61)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS62)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP);
typedef SEXP (*FUNS63)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS64)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP);
typedef SEXP (*FUNS65)(SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP, SEXP,
                       SEXP, SEXP);


void dotCall64_callFunction(DL_FUNC fun, int nargs, void **cargs) {
    switch (nargs) {
    case 0:
	fun();
	break;
    case 1:
	((FUNS1)fun)(cargs[0]);
	break;
    case 2:
	((FUNS2)fun)(cargs[0], cargs[1]);
	break;
    case 3:
	((FUNS3)fun)(cargs[0], cargs[1], cargs[2]);
	break;
    case 4:
	((FUNS4)fun)(cargs[0], cargs[1], cargs[2], cargs[3]);
	break;
    case 5:
	((FUNS5)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4]);
	break;
    case 6:
	((FUNS6)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5]);
	break;
    case 7:
	((FUNS7)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6]);
	break;
    case 8:
	((FUNS8)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7]);
	break;
    case 9:
	((FUNS9)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8]);
	break;
    case 10:
	((FUNS10)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9]);
	break;
    case 11:
	((FUNS11)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10]);
	break;
    case 12:
	((FUNS12)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11]);
	break;
    case 13:
	((FUNS13)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12]);
	break;
    case 14:
	((FUNS14)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13]);
	break;
    case 15:
	((FUNS15)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14]);
	break;
    case 16:
	((FUNS16)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15]);
	break;
    case 17:
	((FUNS17)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16]);
	break;
    case 18:
	((FUNS18)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17]);
	break;
    case 19:
	((FUNS19)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18]);
	break;
    case 20:
	((FUNS20)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19]);
	break;
    case 21:
	((FUNS21)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20]);
	break;
    case 22:
	((FUNS22)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21]);
	break;
    case 23:
	((FUNS23)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22]);
	break;
    case 24:
	((FUNS24)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23]);
	break;
    case 25:
	((FUNS25)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24]);
	break;
    case 26:
	((FUNS26)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25]);
	break;
    case 27:
	((FUNS27)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26]);
	break;
    case 28:
	((FUNS28)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27]);
	break;
    case 29:
	((FUNS29)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28]);
	break;
    case 30:
	((FUNS30)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29]);
	break;
    case 31:
	((FUNS31)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30]);
	break;
    case 32:
	((FUNS32)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31]);
	break;
    case 33:
	((FUNS33)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32]);
	break;
    case 34:
	((FUNS34)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33]);
	break;
    case 35:
	((FUNS35)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34]);
	break;
    case 36:
	((FUNS36)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35]);
	break;
    case 37:
	((FUNS37)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36]);
	break;
    case 38:
	((FUNS38)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37]);
	break;
    case 39:
	((FUNS39)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38]);
	break;
    case 40:
	((FUNS40)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39]);
	break;
    case 41:
	((FUNS41)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40]);
	break;
    case 42:
	((FUNS42)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41]);
	break;
    case 43:
	((FUNS43)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42]);
	break;
    case 44:
	((FUNS44)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43]);
	break;
    case 45:
	((FUNS45)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44]);
	break;
    case 46:
	((FUNS46)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45]);
	break;
    case 47:
	((FUNS47)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46]);
	break;
    case 48:
	((FUNS48)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47]);
	break;
    case 49:
	((FUNS49)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48]);
	break;
    case 50:
	((FUNS50)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49]);
	break;
    case 51:
	((FUNS51)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50]);
	break;
    case 52:
	((FUNS52)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51]);
	break;
    case 53:
	((FUNS53)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52]);
	break;
    case 54:
	((FUNS54)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53]);
	break;
    case 55:
	((FUNS55)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54]);
	break;
    case 56:
	((FUNS56)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55]);
	break;
    case 57:
	((FUNS57)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56]);
	break;
    case 58:
	((FUNS58)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56], cargs[57]);
	break;
    case 59:
	((FUNS59)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56], cargs[57], cargs[58]);
	break;
    case 60:
	((FUNS60)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56], cargs[57], cargs[58], cargs[59]);
	break;
    case 61:
	((FUNS61)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
	    cargs[60]);
	break;
    case 62:
	((FUNS62)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
	    cargs[60], cargs[61]);
	break;
    case 63:
	((FUNS63)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
	    cargs[60], cargs[61], cargs[62]);
	break;
    case 64:
	((FUNS64)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
	    cargs[60], cargs[61], cargs[62], cargs[63]);
	break;
    case 65:
	((FUNS65)fun)(cargs[0],  cargs[1],  cargs[2],  cargs[3],  cargs[4],
	    cargs[5],  cargs[6],  cargs[7],  cargs[8],  cargs[9],
	    cargs[10], cargs[11], cargs[12], cargs[13], cargs[14],
	    cargs[15], cargs[16], cargs[17], cargs[18], cargs[19],
	    cargs[20], cargs[21], cargs[22], cargs[23], cargs[24],
	    cargs[25], cargs[26], cargs[27], cargs[28], cargs[29],
	    cargs[30], cargs[31], cargs[32], cargs[33], cargs[34],
	    cargs[35], cargs[36], cargs[37], cargs[38], cargs[39],
	    cargs[40], cargs[41], cargs[42], cargs[43], cargs[44],
	    cargs[45], cargs[46], cargs[47], cargs[48], cargs[49],
	    cargs[50], cargs[51], cargs[52], cargs[53], cargs[54],
	    cargs[55], cargs[56], cargs[57], cargs[58], cargs[59],
	    cargs[60], cargs[61], cargs[62], cargs[63], cargs[64]);
	break;
    default:
	error(_("too many arguments, sorry"));
    }
}
