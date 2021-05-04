#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

	if(argc != 2) {
		printf("Usage: %s <N>\n<N> needs to be a positive integer!\n", argv[0]);
		return EXIT_FAILURE;
	}

	int N = atoi(argv[1]);

	if(N < 0) {
		printf("Usage: %s <N>\n<N> needs to be a positive integer!\n", argv[0]);
		return EXIT_FAILURE;
	}

	int* b = malloc(N * sizeof(int));
	int* a = malloc(N * sizeof(int));
	double start, end;

	for(int i = 0; i < N; ++i) {
		a[i] = 1;
	}

	start = omp_get_wtime();
	b[0] = 0;

	for(int i = 1; i < N; i++) {

		b[i] = b[i - 1] + a[i - 1];
	}
	end = omp_get_wtime();

	printf("value: %9d\ttime: %1.6f\n", b[N - 1], end - start);

	free(a);
	free(b);

	return EXIT_SUCCESS;
}