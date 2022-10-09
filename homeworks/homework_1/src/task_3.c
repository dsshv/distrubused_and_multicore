//
// Created by dsshv on 07.10.22.
//
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    int size, rank;
    int N;                          // Size of vector
    int i;                          // iterator
    int *A;
    int local_sum, sum;
    int part;
    double t_start, t_end;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("\nInput size of the vector (N): \n\n");
        scanf("\n%d", &N);
    }
    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    A = malloc(N*sizeof(int));
    for (i = 0; i < N; i++)
        A[i] = rand() % 10;

    if (rank == 0)
        t_start = MPI_Wtime();

    part = N / size;
    local_sum = 0;
    for (i = rank * part; i <= (rank + 1) * part - 1; i++) {
        local_sum += A[i];
    }
    MPI_Reduce(&local_sum, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    t_end = MPI_Wtime();
    if (rank == 0)
        printf("Sum: %d. Time: %f\n", sum, t_end-t_start);

    MPI_Finalize();
    return 0;
}

