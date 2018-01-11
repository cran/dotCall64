#' Allocate vectors in .C64()
#'
#' \code{vector_dc} and its shortcuts \code{numeric_dc} and
#' \code{integer_dc} are helper functions used in calls to \code{\link{.C64}}.
#' They return an R object of class \code{c("vector_dc", "list")}, 
#' which contains information on the type and length of the vector to allocate.
#' Using \code{vector_dc} together with \code{INTENT = "w"} argument of \code{\link{.C64}}
#' leads to performance gains by avoiding unnecessary castings and copies. 
#'
#' @param mode character vector of length 1. Storage mode of the vector.
#' @param length numeric vector of length 1. Length of the vector.
#' @return object of class \code{vector_dc} and \code{list}.
#' @name vector_dc
#' @rdname vector_dc
#' @examples
#' vector_dc("integer", 20)
#' @export
vector_dc <- function(mode = "logical", length = 0L) {
	r <- list(mode = as.character(mode),
                  length = as.numeric(length))
        class(r) <- c("vector_dc", "list")
        r
    }

#' @name numeric_dc
#' @rdname vector_dc
#' @export
numeric_dc <- function(length = 0) vector_dc(mode = "numeric", length = length)

#' @name integer_dc
#' @rdname vector_dc
#' @export
integer_dc <- function(length = 0) vector_dc(mode = "integer", length = length)
