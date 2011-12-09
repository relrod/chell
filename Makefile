CFLAGS=-std=c99 -g -Wall -Wextra -pedantic
LDFLAGS=-lreadline

chell: chell.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f chell *.o

