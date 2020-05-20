CC=gcc
CFLAGS= -ggdb -Wall -pedantic -std=c11

make:
	$(CC) $(CFLAGS) -o t0 t0.c -lm
	$(CC) $(CFLAGS) -o t1 t1.c -lm
	$(CC) $(CFLAGS) -o t2 t2.c -lm
	$(CC) $(CFLAGS) -o t3 t3.c -lm

test:
	./t0
	./t1
	./t2
	./t3

clean:
	rm t0