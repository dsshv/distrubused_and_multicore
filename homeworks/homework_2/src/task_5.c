#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int size, rank;
    int proc_power;
    int i;
    int total_capacity; 
    int *capacity;
    double *relative_capacity;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    // Part A
    srand(rank);
    proc_power = rand() % 10 + 1;
    if (rank > 0) {
        MPI_Send(&proc_power, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    
    if (rank == 0) {
        capacity = malloc(size*sizeof(int));
        relative_capacity = malloc(size*sizeof(int));

        capacity[0] = proc_power;
        total_capacity = proc_power;

        for (i = 1; i < size; i++) {
            MPI_Recv(&capacity[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_capacity  = total_capacity + capacity[i];
        }

        for (i = 0; i<size; i++) {
            relative_capacity[i] = (capacity[i] + 0.0) / total_capacity;
        }

        for (i = 0; i < size; i++) {
            printf("\nNode [%d]: capacity = %d, revative power = %d", i, capacity[i], relative_capacity[i]);
        }
        printf("\nTotal capacity: %d\n", total_capacity);
    }

    // Part
    MPI_Finalize();
    return 0;
}
