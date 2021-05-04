#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void)
{
    double start;
    double end;
    int x = 0;
    int iterations = 50000000;

    start = omp_get_wtime();
#pragma omp parallel proc_bind(close) num_threads(4)
    {
#pragma omp parallel for
        for (int i = 0; i < iterations; ++i)
        {
#pragma omp atomic
            ++x;
        }
    }
    end = omp_get_wtime();
    printf("work took %f seconds\n", end - start);
    return EXIT_SUCCESS;
}