#include<stdio.h>
#include<omp.h>
int main(){
    omp_set_num_threads(2);
    #pragma omp parallel 
    {
        int tid = omp_get_thread_num();
        printf("1. Hello, World from thread %d\n", tid);
    }

    #pragma omp parallel num_threads(6)
    {
        int tid = omp_get_thread_num();
        printf("2. Hello, World from thread %d\n", tid);
    }

    #pragma omp parallel num_threads(4)
    {
        int tid = omp_get_thread_num();
        printf("3. Hello, World from thread %d\n", tid);
    }
    return 0;
}

