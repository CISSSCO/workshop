#include<stdio.h>
#include<omp.h>
#define N 100
int main(){
    int arr[N];
    #pragma omp parallel for num_threads(10)
    for(int i = 0; i < N; i++){
        arr[i] = i + 1;
    }
    for(int i = 0; i < N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

