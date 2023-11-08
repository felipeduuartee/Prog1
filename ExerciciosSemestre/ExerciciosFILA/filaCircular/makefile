CC=gcc
CFLAGS=-Wall -g
OBJS=main.o fila.o

all: programa

programa: $(OBJS)
	$(CC) $(CFLAGS) -o programa $(OBJS)

main.o: main.c fila.h
	$(CC) $(CFLAGS) -c main.c

fila.o: fila.c fila.h
	$(CC) $(CFLAGS) -c fila.c

clean:
	rm -f *.o programa
