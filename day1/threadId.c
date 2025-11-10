#include<stdio.h>
#include<omp.h>
int main(){
    //omp_set_num_threads(2);
    #pragma omp parallel num_threads(7)
    {
        int tid = omp_get_thread_num();
        printf("Hello, World from thread %d\n", tid);
    }
    return 0;
}

