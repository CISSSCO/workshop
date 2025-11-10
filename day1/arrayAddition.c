#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
#define T 16

int main(){
    long long N = 10000000000;
    long long *a, *b, *c, *cs;
    a = (long long *) malloc(sizeof(long long) * N);
    b = (long long *) malloc(sizeof(long long) * N);
    c = (long long *) malloc(sizeof(long long) * N);
    cs = (long long *) malloc(sizeof(long long) * N);
    for(long long i = 0; i < N; i++){
        a[i] = i + 1;
        b[i] = i + 1;
        c[i] = 0;
        cs[i] = 0;
    }
    int chunk = N/T;
    double startTime = omp_get_wtime();
    #pragma omp parallel for num_threads(T) schedule(dynamic, chunk)
    for(long long i = 0; i < N; i++){
        c[i] = a[i] + b[i];
    }
    double endTime = omp_get_wtime();
    double parallelTime = endTime - startTime;

    startTime = omp_get_wtime();
    for(long long i = 0; i < N; i++){
        cs[i] = a[i] + b[i];
    }
    endTime = omp_get_wtime();
    double serialTime = endTime - startTime;
    for(long long i = N - 5; i < N; i++){
        printf("%lld ", c[i]);
    }
    printf("\nSerial time = %lf\n", serialTime);
    printf("\nParallel time = %lf\n", parallelTime);

    free(a);
    free(b);
    free(c);
    free(cs);

    return 0;
}
