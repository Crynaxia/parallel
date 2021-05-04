CFLAGS = -std=gnu11 -Wall -Werror -Wextra -Ofast -fopenmp

.PHONY: all
all: prefix_seq prefix_par 

.PHONY: clean
clean:
	$(RM) prefix_seq prefix_par 

prefix_seq: prefix_seq.c
prefix_par: prefix_par.c
