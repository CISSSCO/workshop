#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<sys/time.h>
#include<omp.h>

//#define N 9999999999

int main()
{
    long long i, N = 9999999999;
    double area, pi;
    double dx, y, x;
    double exe_time;
    struct timeval stop_time, start_time;

    dx = 1.0 / N;
    area = 0.0;

    gettimeofday(&start_time, NULL);

    //#pragma omp parallel for private(x, y) reduction(+:area) num_threads(20)
    for(i = 0; i < N; i++){
        x = i * dx;
        y = sqrt(1 - x*x);
        area += y * dx;
    }

    gettimeofday(&stop_time, NULL);

    exe_time = (stop_time.tv_sec + (stop_time.tv_usec / 1000000.0)) -
               (start_time.tv_sec + (start_time.tv_usec / 1000000.0));

    pi = 4.0 * area;

    printf("\n Value of pi is = %.16lf\n Execution time is = %lf seconds\n", pi, exe_time);

    return 0;
}
