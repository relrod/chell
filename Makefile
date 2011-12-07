CFLAGS=-std=gnu99
LDFLAGS=-lreadline

chell: chell.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ chell.c

clean:
	rm -fv chell
