#include<stdio.h>
#include<omp.h>
int main(){
    #pragma omp parallel num_threads(4)
    {
        #pragma omp for
        for(int i = 0; i < 5; i++){
            printf("thread = %d : hello %d\n", omp_get_thread_num() ,i);
        }
    }

    return 0;
}

