#include <R.h>
#include <R_ext/Rdynload.h>
#include <Rinternals.h>
#include <Rversion.h>

SEXP hello(void) {
  const char *string = "hello";
  SEXP out = PROTECT(mkString(string));
  UNPROTECT(1);
  return out;
}

static const R_CallMethodDef call_methods[] = {
  {"c_hello", (DL_FUNC) &hello, 0},
  {NULL, NULL, 0}
};

void R_init_dllreprex(DllInfo *dll) {
  R_registerRoutines(dll, NULL, call_methods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE); // "DLL requires the use of native symbols"
}
