CFLAGS = -std=gnu11 -Wall -Werror -Wextra -O2 -fopenmp

.PHONY: all
all: matrix montecarlo_critical montecarlo_atomic montecarlo_reduction

.PHONY: clean
clean:
	$(RM) matrix montecarlo_atomic montecarlo_critical montecarlo_reduction

matrix: matrix.c
monte_atomic: montecarlo_atomic.c
monte_critical: montecarlo_critical.c
monte_reduction: montecarlo_reduction.c