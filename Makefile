CFLAGS = -std=gnu11 -Wall -Werror -Wextra -O2 -fopenmp

.PHONY: all
all: matrix monte_critical monte_atomic monte_reduction

.PHONY: clean
clean:
	$(RM) matrix monte_atomic monte_critical monte_reduction

matrix: matrix.c
monte_atomic: monte_atomic.c
monte_critical: monte_critical.c
monte_reduction: monte_reduction.c