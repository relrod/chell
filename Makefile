LDFLAGS=-lreadline

chell: chell.c
	$(CC) $(LDFLAGS) -o chell chell.c

clean:
	rm -fv chell
