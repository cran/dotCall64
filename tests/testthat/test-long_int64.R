library(dotCall64)
context("test-local-tests")

test_that("pass-long-int64_t", {
    skip_on_cran()

    # Ideally, the following should be tested with N <- 31. Blows my laptop...
    N <- 31
    N <- 21
    
    a <- numeric(2^N)
   
    expect_identical(.C64("BENCHMARK",
                          SIGNATURE = "int64",
                          a = a,
                          INTENT = "rw",
                          NAOK = TRUE,
                          VERBOSE = 1,
                          PACKAGE = "dotCall64")$a,
                     a)
})
