#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int size, rank;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    printf("\nNode :%d, (number of nodes=%d): Hello World!\n\n", rank, size);
    if (rank==0) {
        printf("\n\ni am the master!!!!\n\n\n");
    } else {
        printf("\ni am just a worker.... %d", rank);
    }
    MPI_Finalize();

    return 0;
}