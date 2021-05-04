//code base modified from https://stackoverflow.com/questions/51646963/need-to-implement-a-recursive-mergesort-code-in-c-using-array-pointer-its-lengt
// help in sequential version from Julian Hotter
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ARRAY_MAX 100

void merge(int *arr, int *buff, int n)
{

    int i = 0;
    int j = n / 2;
    int ti = 0;

    while (i < n / 2 && j < n)
    {
        if (arr[i] < arr[j])
        {
            buff[ti] = arr[i];
            ti++;
            i++;
        }
        else
        {
            buff[ti] = arr[j];
            ti++;
            j++;
        }
    }
    while (i < n / 2)
    {
        buff[ti] = arr[i];
        ti++;
        i++;
    }
    while (j < n)
    {
        buff[ti] = arr[j];
        ti++;
        j++;
    }
    for (int a = 0; a < n; a++)
    {
        arr[a] = buff[a];
    }
}
void merge_sort(int *arr, int *buff, int n)
{
    if (n < 2)
    {
        return;
    }

    /* sort the left half */
    merge_sort(arr, buff, n / 2);
    /* sort the right half */
    merge_sort(arr + (n / 2), buff + n / 2, n - (n / 2));

    merge(arr, buff, n);

    return;
}

int main(void)
{
    int *startArray = (int *)malloc(ARRAY_MAX * sizeof(int));
    int *buffArray = (int *)malloc(ARRAY_MAX * sizeof(int));
    int size = ARRAY_MAX;
    unsigned seed = 2513;
    int randMax = 20000;
    double start, end;

    srand(0);

    for (int i = 0; i < size; ++i)
    {
        startArray[i] = rand_r(&seed) % randMax;
        printf("%d\n", startArray[i]);
    }

    start = omp_get_wtime();
    merge_sort(startArray, buffArray, ARRAY_MAX);
    end = omp_get_wtime();

    printf("wtime: %f\n", end - start);

    free(startArray);
    free(buffArray);

    return EXIT_SUCCESS;
}