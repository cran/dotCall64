#' dotCall64 - Extended Foreign Function Interface
#' 
#' \code{.C64} can be used to call compiled and loaded C functions and Fortran subroutines.
#' It works similar to \code{\link{.C}} and \code{\link{.Fortran}}, and 
#' \enumerate{
#'    \item supports long vectors, i.e., vectors with more than \code{2^31-1} elements,
#'    \item does the necessary castings to expose the R representation of "64-bit integers" (numeric vectors)
#' to 64-bit integers arguments of the compiled function; int64_t types in C and integer (kind = 8) in Fortran,
#'    \item provides a mechanism the control the duplication of the R objects exposed to the compiled code,
#'    \item checks if the provided R objects are of the expected type and coerces the R object if necessary. 
#' }
#' Compared to \code{\link{.C}}, \code{.C64} has the additional arguments \code{SIGNATURE}, \code{INTENT} and \code{VERBOSE}.
#' \code{SIGNATURE} specifies the types of the arguments of the compiled function.
#' \code{INTENT} indicates whether the compiled function "reads", "writes", or "read and writes" the R objects passed
#' to the compiled function. This is then used to duplicates R objects if (and only if) necessary. 
#' 
#' @param .NAME a character vector of length 1. Specifies the name of the compiled function to be called. 
#' @param SIGNATURE a character vector of the same length as the number of arguments of the compiled function.
#' Accepted strings are \code{"double"}, \code{"integer"}, \code{"int64"} describing the signature
#' of each argument of the compiled function.
#' @param ... arguments passed to the compiled function. One R object for each argument. Up to 65 arguments are supported.
#' @param INTENT a character vector of the same length as the number of arguments of the compiled code.
#' Accepted strings are \code{"rw"}, \code{"r"} or \code{"w"} indicating
#' whether the intent of the argument is "read and write", "read", or "write", respectively.
#' If the INTENT of an argument is \code{"rw"}, the R object is copied and the
#' compiled function receives a pointer to that copy.
#' If the INTENT of an R object is \code{"r"}, the compiled
#' function receives a pointer to the R object itself.
#' While this avoids copying and hence is more efficient in terms of speed and memory usage,
#' it is absolutely necessary that the compiled function does not alter the object,
#' since this corrupts the R object in the current R session.
#' When the intent is \code{"w"}, the corresponding input argument can be specified
#' with the function \code{\link{vector_dc}} or its shortcuts \code{\link{integer_dc}} and \code{\link{numeric_dc}}.
#' This avoids copying the passed R objects and hence is more efficient in terms of speed and memory usage.
#' By default, all arguments have intent \code{"rw"}.
#' @param NAOK logical vector of length 1. If \code{FALSE} (default), the presence of \code{NA} or \code{NaN} or \code{Inf}
#' in the R objects passed through \code{...} results in an error.
#' If \code{TRUE}, any \code{NA} or \code{NaN} or \code{Inf} values in the
#' arguments are passed on to the compiled function.
#' The used time to check arguments (if \code{FALSE}) maybe considerable for large vectors. 
#' @param PACKAGE character vector of length 1. Specifies where to search for the function given in \code{.NAME}. 
#' This is intended to add safety for packages,
#' which can use this argument to ensure that no other package can override their external symbols,
#' and also speeds up the search.
#' @param VERBOSE Numeric vector of length 1. If \code{0}, no warnings are printed.
#' If \code{1} warnings are printed (which may help to improve the performance of the call),
#' If \code{2} additional debug information is given as warnings.
#' The default value can be changed via the \code{dotCall64.verbose} option, which is set to \code{0} by default. 
#'  
#' @return  A list similar to the \code{...} list of arguments passed in (including
#' any names given to the arguments), but reflecting any changes made
#' by the compiled C or Fortran code.
#'  
#' @references
#' F. Gerber, K. Moesinger, and R. Furrer (2017),
#' Extending R packages to support 64-bit compiled code: An illustration with spam64 and GIMMS NDVI3g data,
#' Computer & Geoscience 104, 109-119,
#' https://doi.org/10.1016/j.cageo.2016.11.015.
#'
#' F. Gerber, K. Moesinger, and R. Furrer (2017),
#' dotCall64: An efficient interface to compiled C/C++ and Fortran code supporting long vectors,
#' https://arxiv.org/abs/1702.08188.
#' 
#' @examples
#' ## Consider the following C function, which is included
#' ## in the dotCall64 package:  
#' ## void get_c(double *input, int *index, double *output) {
#' ##     output[0] = input[index[0] - 1];
#' ## }
#' ##
#' ## We can use .C64() the call it from R:
#' .C64("get_c", SIGNATURE = c("double", "integer", "double"),
#'      input = 1:10, index = 9, output = double(1))$output
#'
#' \dontrun{
#' ## 'input' can be a long vector
#' x_long <- double(2^31) ## requires 16 GB RAM
#' x_long[9] <- 9; x_long[2^31] <- -1
#' .C64("get_c", SIGNATURE = c("double", "integer", "double"),
#'      input = x_long, index = 9, output = double(1))$output
#'
#' ## Since 'index' is of type 'signed int' resulting in a 32-bit integer,
#' ## it can only capture integers op to 2^31-1. To extend this,
#' ## we define the C function as follows:
#' ## #include <stdint.h>  // defines the int64_t type
#' ## void get64_c(double *input, int64_t *index, double *output) {
#' ##     output[0] = input[index[0] - 1];
#' ## }
#' 
#' ## We can use .C64() to call the function from R.
#' .C64("get64_c", SIGNATURE = c("double", "int64", "double"),
#'      input = x_long, index = 2^31, output = double(1))$output
#'
#' ## Note that .C64() takes 2^31 as double and casts it to int64_t
#' ## before calling the C function get64_c().
#'
#' ## The performance of the previous call can be improved with
#' ## additional options:
#' .C64("get64_c", SIGNATURE = c("double", "int64", "double"),
#'      x = x_long, i = 2^31, r = numeric_dc(1), INTENT = c("r", "r", "w"),
#'      NAOK = TRUE, PACKAGE = "dotCall64", VERBOSE = 0)$r
#' 
#'
#' ## Consider the same function defined in Fortran:
#' ##      subroutine get64_f(input, index, output)
#' ##      double precision :: input(*), output(*)
#' ##      integer (kind = 8) :: index  ! specific to GFortran
#' ##      output(1) = input(index)
#' ##      end
#' 
#' ## The function is provided in dotCall64 and can be called with
#' .C64("get64_f", SIGNATURE = c("double", "int64", "double"),
#'      input = x_long, index = 2^31, output = double(1))$output
#'
#' }
#' @useDynLib dotCall64, .registration = TRUE
#' @export
#' @name dotCall64
.C64 <- function(.NAME, SIGNATURE, ..., INTENT = NULL, NAOK = FALSE,
                 PACKAGE = "", VERBOSE = getOption("dotCall64.verbose")) {
  .External("dC64", name = .NAME, SIGNATURE = SIGNATURE, ..., INTENT = INTENT, NAOK = NAOK,
            f.PACKAGE = PACKAGE, VERBOSE = VERBOSE, PACKAGE = "dotCall64")
    }
