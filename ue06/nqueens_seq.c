#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int check(int* chessboard[], int N);
void printBoard(int* chessboard[], int N);

int main(int argc, char** argv) {

	if(argc != 2) {
		printf("Usage: %s <N>\n<N> needs to be a positive integer!\n", argv[0]);
		return EXIT_FAILURE;
	}

	int N = atoi(argv[1]);

	if(N < 1) {
		printf("Usage: %s <N>\n<N> needs to be a positive integer!\n", argv[0]);
		return EXIT_FAILURE;
	}

	int* chessboard[N];
	for(int i = 0; i < N; i++) {
		chessboard[i] = malloc(N * sizeof(int));
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			chessboard[i][j] = 0;
		}
	}

	chessboard[0][0] = 1;
	chessboard[1][3] = 1;
	chessboard[3][2] = 1;
	chessboard[4][1] = 1;
	chessboard[4][0] = 1;
    
	printBoard(chessboard, N);
	int c = check(chessboard, N);
	printf("solutions = %d\n", c);

	for(int i = 0; i < N; i++) {
		free(chessboard[i]);
	}

	return EXIT_SUCCESS;
}

void printBoard(int* chessboard[], int N) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			printf("%d ", chessboard[i][j]);
		}
		printf("\n");
	}
}

int check(int* chessboard[], int N) {

	int counter_x = 0;
	int counter_y = 0;
	int counter_d1 = 0;
	int counter_d2 = 0;

	for(int i = 0; i < N; ++i) {

		counter_x = 0;
		counter_y = 0;

		for(int j = 0; j < N; ++j) {

			counter_x += chessboard[i][j];
			counter_y += chessboard[j][i];
		}
		if(counter_x > 1 || counter_y > 1) {
			return 0;
		}
	}

	return 1;
}