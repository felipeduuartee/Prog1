CC=gcc
CFLAGS=-Wall -Wextra

all: main

main: main.o listas.o
	$(CC) $(CFLAGS) -o main main.o listas.o

main.o: main.c listas.h
	$(CC) $(CFLAGS) -c main.c

listas.o: listas.c listas.h
	$(CC) $(CFLAGS) -c listas.c

clean:
	rm -f *.o main
