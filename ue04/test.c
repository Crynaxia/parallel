#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int *start = malloc(10 * sizeof(int *));
    int *arr[10];

    srand(NULL);

    for (int i = 0; i < 10; ++i)
    {
        *pointer = rand() % 5000;
        printf("value: %d address: %p\n", *pointer, pointer);
        ++pointer;
    }

    return EXIT_SUCCESS;
}