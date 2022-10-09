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

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("\nInput size of the vector (N): \n\n");
        scanf("\n%d", &N);
        A = malloc(N * sizeof(int));
        for (i = 0; i < N; i++)
            A[i] = rand() % 10;
    }
    MPI_Bcast(&A, sizeof A, MPI_BYTE, 0, MPI_COMM_WORLD);

    if (rank != 0) {
        if (!A)
            printf("\nError\n\n");
    }

    MPI_Finalize();
    return 0;


}
