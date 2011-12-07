CFLAGS=-std=gnu99 -g -Wall -Wextra -pedantic
LDFLAGS=-lreadline

chell: chell.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ chell.c

clean:
	rm -fv chell
