CC=gcc
CFLAGS=-lreadline

chell:
	$(CC) $(CFLAGS) -o chell chell.c

clean:
	rm -fv chell
