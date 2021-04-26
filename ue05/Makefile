CFLAGS = -std=gnu11 -Wall -Werror -Wextra -O2 -fopenmp

.PHONY: all
all: delannoy_seq delannoy_par heat_stencil_2D

.PHONY: clean
clean:
	$(RM) delannoy_seq delannoy_par heat_stencil_2D

delannoy_seq: delannoy_seq.c
delannoy_par: delannoy_par.c
heat_stencil_2D: heat_stencil_2D.c