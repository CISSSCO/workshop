#include<stdio.h>
#include<omp.h>
int main(){
    int x = 10;
    int y = 20;
    #pragma omp parallel private(x,y)
    {
        printf("Thread %d: x = %d and y = %d\n", omp_get_thread_num(), x, y);
    }
    return 0;
}

