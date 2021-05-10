#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <xmmintrin.h>

#define factorB 1.1f
#define factorC 0.919f

#define SIZE 2048

int main(void)
{

    int repetitions = 1000000;

    int size = 2048;
    __attribute__((aligned(16))) float a[SIZE] = {[0 ... 2047] = 0};
    __attribute__((aligned(16))) float b[SIZE] = {[0 ... 2047] = factorB};
    __attribute__((aligned(16))) float c[SIZE] = {[0 ... 2047] = factorC};

    __m128 w, x, y, z, result;

    for (int i = 0; i < size; i++)
    {

        b[i] = factorB;
        c[i] = factorC;
    }

    double startTime = omp_get_wtime();
#pragma omp simd
    for (int run = 0; run < repetitions; run++)
    {
        for (int i = 0; i < size; i += 4)
        {
            x = _mm_load_ps(&a[i]);
            y = _mm_load_ps(&b[i]);
            z = _mm_load_ps(&c[i]);
            w = _mm_mul_ps(y, z);
            result = _mm_add_ps(x, w);
            _mm_store_ps(&a[i], result);
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
