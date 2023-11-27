#' @useDynLib dllreprex, .registration = TRUE
NULL

#' @export
hello <- function() {
  .Call(.NAME = c_hello, .PACKAGE = "dllreprex")
}
