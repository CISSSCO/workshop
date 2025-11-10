#include<stdio.h>
#include<omp.h>
#define T 13
int main(){
    long long N = 1000000000;
    long long sum = 0;
    double startTime = omp_get_wtime();
    for(long long i = 0; i < N; i++){
        sum += i + 1;
    }
    double endTime = omp_get_wtime();
    printf("Serial time = %lf\n", endTime - startTime);
    startTime = omp_get_wtime();
    sum = 0;
    #pragma omp parallel for reduction(+ : sum) num_threads(T)
    for(long long i = 0; i < N; i++){
        sum += i + 1;
    }
    endTime = omp_get_wtime();

    printf("Parallel time = %lf\n", endTime - startTime);
    printf("Calculated sum = %lld\n", sum);
    long long expectedSum = (N * ((N + 1)) / 2);
    printf("Expected sum = %lld\n", expectedSum);
    if(sum == expectedSum){
        printf("_____Passed_____\n");
    }
    else printf("_____Failed_____\n");

    return 0;
}
