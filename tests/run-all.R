require("RhpcBLASctl"); omp_set_num_threads(1)
# to address:
# * checking tests ... [10s/1s] NOTE
#   Running ‘run-all.R’ [10s/1s]
#   Running R code in ‘run-all.R’ had CPU time 10.5 times elapsed time

library(testthat)
test_check('dotCall64')
