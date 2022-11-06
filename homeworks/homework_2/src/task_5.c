#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int size, rank;
    int i, j;
    // for part A
    int proc_power;
    int total_capacity; 
    int *capacity;
    float *relative_capacity;
    // for part B
    int part, n;
    int *A;
    int *splited_vector;
    int last_point;

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

        for (i = 0; i < size; i++) {
            relative_capacity[i] = (float) capacity[i] / (float) total_capacity;
            printf("\nNode [%d]: capacity = %d, revative power = %.5f", i, capacity[i], relative_capacity[i]);
        }

        printf("\nTotal capacity: %d", total_capacity);
    }

    // Part B

    if ( rank == 0 ){
        printf("\n\nInput the size of vector n=");
        scanf("%d",&n);
        A = malloc ( n * sizeof(int));
        for (i=0; i<n; i++) {
            A[i] = rand() % 100;
            printf("%5d", A[i]);
        }

        part = n * (relative_capacity[0]);
        // printf("\npart = %d", part);
        splited_vector = malloc(part*sizeof(int));
        for (i = 0; i < part; i++) {
            splited_vector[i] = A[i];
        }
        last_point = part;
        for (i = 1; i < size; i++) {
            //printf("\npart = %d", part);
            part = n * (relative_capacity[i]);

            printf("%2d --> %3d\n", i, part);
            MPI_Send(&part, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
            MPI_Send(&A[last_point], part, MPI_INT, i, 0, MPI_COMM_WORLD);
            last_point = last_point + part;
        }

        part = n * relative_capacity[0];
    }

    if (rank > 0) {
        MPI_Recv(&part, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        // printf("rank[%d], part:%3d\n", rank, part);
        splited_vector = malloc(part*sizeof(int));
        MPI_Recv(splited_vector, part, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    printf("\nnode[%d]: part = %d\n", rank, part);
    

    MPI_Finalize();
    return 0;
}
