# include <stdint.h>

void TEST_times2_double ( double* a, double* r ) {
    *r = *a * 2.0 ;
}

void TEST_times2_int ( int* a, int* r ) {
    *r = *a * 2 ;
}

void TEST_times2_int64 ( int64_t* a, int64_t* r ) {
    *r = *a * 2 ;
}

void TEST_prod_double ( double* a, double* b) { 
    *a = *a * *b ;
}

void TEST_prod_int ( int* a, int* b) { 
    *a = *a * *b ;
}

void TEST_prod_int64 ( int64_t* a, int64_t* b) { 
    *a = *a * *b ;
}

void BENCHMARK (void *x) { }

void get_c(double *input, int *index, double *output) {
    output[0] = input[index[0] - 1];
}

void get64_c(double *input, int64_t *index, double *output) {
    output[0] = input[index[0] - 1];
}



