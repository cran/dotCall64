#' Allocate vectors in .C64()
#'
#' Helper functions to be used in calls to \code{\link{.C64}}.
#' The function \code{vector_dc} and its shortcuts \code{numeric_dc} and
#' \code{integer_dc} return a R object of class \code{c("vector_dc", "list")}
#' containing the necessary information (type and length) to allocate the
#' vector (initialized with 0) inside the call to \code{\link{.C64}}.
#' Using \code{vector_dc} together with \code{INTENT = "w"} argument of \code{\link{.C64}}
#' leads to performance gains by avoiding unnecessary castings and copies. 
#'
#' @param mode Character vector of length 1. Storage mode of the vector to allocate.  
#' @param length Numeric vector of length 1. Length of the vector to allocate.
#' @return Object of class \code{vector_dc} and \code{list}.
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
