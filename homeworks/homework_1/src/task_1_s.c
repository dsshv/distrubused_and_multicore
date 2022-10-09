#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
    int prime_counter;
    int is_prime;                   // flag
    int divisor;
    double t_start, t_end;
    int x;                          // iterator
    int N;                          // num of operations

    MPI_Init(&argc, &argv);
    printf("\nInput N: \n");
    scanf("%d", &N);
    t_start = MPI_Wtime();
    prime_counter = 0;
    for (x = 1; x <= N; x++) {
        is_prime = 1;
        for (divisor = 2; divisor <= x/2; divisor++) {
            if (x % divisor == 0){
                is_prime = 0;
            }
        }
        if (is_prime == 1) {
            prime_counter++;
        }
    }

    t_end = MPI_Wtime();
    printf("\nthe number of primes in the interval [1, N]: %d, time = %.5f seconds\n", prime_counter, t_end-t_start);
    MPI_Finalize();

    return 0;
}





