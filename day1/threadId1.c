#include<stdio.h>
#include<omp.h>
int main(){
    #pragma omp parallel 
    {
        int tid = 0;
        #ifdef _OPENMP
        tid = omp_get_thread_num();
        #endif
        printf("1. Hello, World from thread %d\n", tid);
    }

    return 0;
}
