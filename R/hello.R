#' @useDynLib dllreprex, .registration = TRUE
NULL

#' @export
hello <- function() {
  .Call(c_hello)
}
