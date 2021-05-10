#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define factorB 1.1f
#define factorC 0.919f

int main(void)
{

    int repetitions = 1000000;

    //exc 1a ; initialize vectors with constant values
    int size = 2048;
    float a[size];
    float b[size];
    float c[size];

    for (int i = 0; i < size; i++)
    {

        b[i] = factorB;
        c[i] = factorC;
    }

    double startTime = omp_get_wtime();
#pragma omp simd
    for (int run = 0; run < repetitions; run++)
    {
        for (int i = 0; i < size; i++)
        {
            a[i] += b[i] * c[i];
        }
    }
    double endTime = omp_get_wtime();

    for (int i = 0; i < size; i++)
    {
        printf("%1.8f\n", a[i]);
    }

    printf(" time: %2.4f seconds\n", endTime - startTime);
    return EXIT_SUCCESS;
}
