GCC = gcc
CFLAGS = -g -std=c99 -pedantic -Wall -Wextra

puzzle: puzzle.o puzzle_funcs.o read_utils.o ppm_io.o
	$(GCC) -o puzzle puzzle.o puzzle_funcs.o ppm_io.o read_utils.o

puzzle.o: puzzle.c puzzle.h puzzle_funcs.h read_utils.h
	$(GCC) $(CFLAGS) -c puzzle.c -g

puzzle_funcs.o: puzzle_funcs.c puzzle_funcs.h puzzle.h
	$(GCC) $(CFLAGS) -c puzzle_funcs.c -g

ppm_io.o: ppm_io.c ppm_io.h
	$(GCC) $(CFLAGS) -c ppm_io.c -g

read_utils.o: read_utils.c read_utils.h ppm_io.h puzzle.h
	$(GCC) $(CFLAGS) -c read_utils.c -g

clean:
	rm -f *.o puzzle *~