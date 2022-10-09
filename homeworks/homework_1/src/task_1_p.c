#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int size, rank;
    int prime_counter_local, prime_counter;
    int is_prime;                   // flag
    int divisor;
    double t_start, t_end;
    int x;                          // iterator
    int N;                          // num of operations
    int part;                       // part for each node

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        printf("\nInput N: \n");
        scanf("%d", &N);
        t_start = MPI_Wtime();
    }

    MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);

    part = N/size;

    prime_counter_local = 0;
    for (x = rank*part + 1; x <= (rank + 1) * part; x++) {
        is_prime = 1;
        for (divisor = 2; divisor <= x/2; divisor++) {
            if (x % divisor == 0){
                is_prime = 0;
            }
        }
        if (is_prime == 1) {
            prime_counter_local++;
        }
    }

    MPI_Reduce(&prime_counter_local, &prime_counter, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        for (x = (N / size) * size + 1; x <= N; x++) {           // extra job
            is_prime = 1;
            for (divisor = 2; divisor <= x / 2; divisor++) {
                if (x % divisor == 0) {
                    is_prime = 0;
                }
            }
            if (is_prime == 1) {
                prime_counter++;
            }
        }

        t_end = MPI_Wtime();
        printf("\nthe number of primes in the interval [1, N]: %d, time = %.5f seconds\n", prime_counter, t_end-t_start);
    }
    MPI_Finalize();
    return 0;
}
