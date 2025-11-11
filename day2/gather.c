#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int send_val;
    int recv_data[4];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    send_val = rank + 1;

    MPI_Gather(&send_val, 1, MPI_INT, recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("Root process collected: ");
        for (int i = 0; i < size; i++)
            printf("%d ", recv_data[i]);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
