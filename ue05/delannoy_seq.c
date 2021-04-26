#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long delannoyNumber(int m, int n) {

	if(m == 0 || n == 0) {
		return 1;
	} else {
		return delannoyNumber(m - 1, n) + delannoyNumber(m - 1, n - 1) + delannoyNumber(m, n - 1);
	}
}

int main(int argc, char** argv) {
	int N;
	long result;
	double start, end;

	if(argc < 2) {
		printf("usage: %s <N>\n", argv[0]);
		return EXIT_FAILURE;
	}

	N = atoi(argv[1]);

	if(N < 1) {
		printf("N needs to be integer > 0\n");
		return EXIT_FAILURE;
	}

	start = omp_get_wtime();
	result = delannoyNumber(N, N);
	end = omp_get_wtime();

	printf("result = %ld\ntime = %2.6f\n", result, end - start);

	return EXIT_SUCCESS;
}