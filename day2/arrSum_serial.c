#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>


int main() {
    MPI_Init(NULL, NULL);

    const long long N = 10000000000;
    long long* global_arr = NULL;

        global_arr = (long long*)malloc(N * sizeof(long long));
        for (int i = 0; i < N; i++) {
            global_arr[i] = i + 1;
        }
        double startTime, endTime;

    startTime = MPI_Wtime();

        long long total_sum = 0;
    for (long long i = 0; i < N; i++) {
        total_sum += global_arr[i];
    }




        endTime = MPI_Wtime();
        printf("timing %lf\n", endTime - startTime);
        printf("\nTotal sum = %lld\n", total_sum);
        free(global_arr);

    MPI_Finalize();
    return 0;
}

