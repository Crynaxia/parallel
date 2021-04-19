CFLAGS = -std=gnu11 -Wall -Werror -Wextra -O3 -fopenmp

.PHONY: all
all: merge_seq merge_par

.PHONY: clean
clean:
	$(RM) merge_seq merge_par

merge_par: merge_par.c
merge_seq: merge_seq.c