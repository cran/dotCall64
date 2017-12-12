#include <R_ext/RS.h> 
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* to get all functions:

   nm -g lib/dotCall64/libs/dotCall64.so | grep " T "

*/

// C
extern void BENCHMARK          ( void *);
extern void dC64               ( void *);
extern void get64_c            ( void *, void *, void *);
extern void get_c              ( void *, void *, void *);
extern void TEST_prod_double   ( void *, void *);
extern void TEST_prod_int      ( void *, void *);
extern void TEST_prod_int64    ( void *, void *);
extern void TEST_times2_double ( void *, void *);
extern void TEST_times2_int    ( void *, void *);
extern void TEST_times2_int64  ( void *, void *);

// Fortran
extern void F77_NAME(get_f)    ( void *, void *, void *);
extern void F77_NAME(get64_f)  ( void *, void *, void *);


		       
static const R_CallMethodDef CEntries[] = {
  {"BENCHMARK",          (DL_FUNC)&BENCHMARK,          1},
  {"dC64",               (DL_FUNC)&dC64,               1},
  {"get64_c",            (DL_FUNC)&get64_c,            3},
  {"get_c",              (DL_FUNC)&get_c,              3},
  {"TEST_prod_double",   (DL_FUNC)&TEST_prod_double,   2},
  {"TEST_prod_int",      (DL_FUNC)&TEST_prod_int,      2},
  {"TEST_prod_int64",    (DL_FUNC)&TEST_prod_int64,    2},
  {"TEST_times2_double", (DL_FUNC)&TEST_times2_double, 2},
  {"TEST_prod_int",      (DL_FUNC)&TEST_prod_int,      2},
  {"TEST_prod_int64",    (DL_FUNC)&TEST_prod_int64,    2},
  {NULL,                  NULL,                        0}
};

				       
static const R_FortranMethodDef FortranEntries[] = {
    {"get_f",            (DL_FUNC)&F77_NAME(get_f  ), 3},
    {"get64_f",          (DL_FUNC)&F77_NAME(get64_f), 3},
    {NULL,                NULL, 0}
};

void R_init_spam(DllInfo *dll)
{
  R_registerRoutines(dll, NULL, NULL, FortranEntries, NULL);
  R_registerRoutines(dll, NULL, CEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}

