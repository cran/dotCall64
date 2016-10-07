.onLoad <- function(libname, pkgname)
{
    if(is.null(getOption("dotCall64.verbose", NULL)))
        options("dotCall64.verbose" = 0L)
}
