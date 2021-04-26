#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long serialDelannoyNumber(int m, int n) {

	if(m == 0 || n == 0) {
		return 1;
	} else {
		return serialDelannoyNumber(m - 1, n) + serialDelannoyNumber(m - 1, n - 1) +
		       serialDelannoyNumber(m, n - 1);
	}
}

long delannoyNumber(int m, int n) {

	if(m == 0 || n == 0) {
		return 1;
	}
	if(m < 4 || n < 4) {
		return serialDelannoyNumber(m, n);
	}

	int x, y, z;

	x = delannoyNumber(m - 1, n);

#pragma omp task shared(y)
	y = delannoyNumber(m - 1, n - 1);

#pragma omp task shared(z)
	z = delannoyNumber(m, n - 1);

#pragma omp taskwait
	return x + y + z;
}

int main(int argc, char** argv) {
	int N;
	long result = 0;
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
#pragma omp parallel reduction(+ : result)
#pragma omp single
	result += delannoyNumber(N, N);

	end = omp_get_wtime();

	printf("result = %ld\ntime = %2.6f\n", result, end - start);

	return EXIT_SUCCESS;
}
