//code base modified from https://stackoverflow.com/questions/51646963/need-to-implement-a-recursive-mergesort-code-in-c-using-array-pointer-its-lengt

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_MAX 10000000

void merge_sort(int *a, int *w, int n)
{
    if (n < 2)
    {
        return;
    }
    else
    {
        int i, j, k;
        int n1 = n / 2;
        int *b = a + n1;
        int n2 = n - n1;

        /* sort the left half */
        merge_sort(a, w, n1);
        /* sort the right half */
        merge_sort(b, w, n2);

        /* merge the halves into w */
        for (i = j = k = 0; i < n1 && j < n2;)
        {
            if (a[i] <= b[j])
            {
                /* get smallest value from a */
                w[k++] = a[i++];
            }
            else
            {
                /* get smallest value from b */
                w[k++] = b[j++];
            }
        }
        /* copy remaining elements from a */
        while (i < n1)
        {
            w[k++] = a[i++];
        }
        /* copy remaining elements from b */
        while (j < n2)
        {
            w[k++] = b[j++];
        }
        /* copy sorted elements back to a */
        for (i = 0; i < n; i++)
        {
            a[i] = w[i];
        }
    }
}

int main(void)
{
    int my_array[ARRAY_MAX] = (int *)malloc(ARRAY_MAX * sizeof(int));
    int work_space[ARRAY_MAX] = (int *)malloc(ARRAY_MAX * sizeof(int));
    int i;
    clock_t start, end;

    srand(time(NULL));

    for (i = 0; i < ARRAY_MAX; ++i)
    {
        my_array[i] = rand_r(NULL);
    }

    start = clock();
    merge_sort(my_array, work_space, ARRAY_MAX);
    end = clock();

    for (i = 0; i < ARRAY_MAX; i++)
    {
        printf("%d\n", my_array[i]);
    }

    fprintf(stderr, "%d %f\n", ARRAY_MAX, (end - start) / (double)CLOCKS_PER_SEC);

    return EXIT_SUCCESS;
}