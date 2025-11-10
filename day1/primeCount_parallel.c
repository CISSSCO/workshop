#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<sys/time.h>
#include<omp.h>

#define N 1000000

int main()
{
    int i, j;
    int count, flag;
    double exe_time;
    struct timeval stop_time, start_time;

    count = 1; // Counting '2' as prime

    gettimeofday(&start_time, NULL);

    #pragma omp parallel for private(j, flag) reduction(+:count) schedule(dynamic, 100)
    for(i = 3; i < N; i++)
    {
        flag = 0;
        for(j = 2; j*j <= i; j++)   // <-- Small optimization: Only check till sqrt(i)
        {
            if(i % j == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            count++;
        }
    }

    gettimeofday(&stop_time, NULL);

    exe_time = (stop_time.tv_sec + (stop_time.tv_usec/1000000.0)) -
               (start_time.tv_sec + (start_time.tv_usec/1000000.0));

    printf("\n Number of prime numbers = %d", count);
    printf("\n Execution time is = %lf seconds\n", exe_time);

    return 0;
}
