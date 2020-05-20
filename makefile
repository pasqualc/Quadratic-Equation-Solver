CC=gcc
CFLAGS= -ggdb -Wall -pedantic -std=c11

make:
	$(CC) $(CFLAGS) -o quadsolver main.c -lm

run:
	./quadsolver

clean:
	rm quadsolver qsolve.log