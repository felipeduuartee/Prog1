# Makefile for The Boys game project
# Adapted by user - DINF/UFPR, 10/2023

CC      = gcc
CFLAGS  = -Wall -Wextra -g -std=c99
LDLIBS  = -lm
MAIN    = theboys
OBJ     = conjunto.o lef.o lista.o mundo.o theboys.o

# programa principal
$(MAIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

# TADs e main
conjunto.o: conjunto.c conjunto.h
lef.o: lef.c lef.h
lista.o: lista.c lista.h
mundo.o: mundo.c mundo.h define.h
theboys.o: theboys.c conjunto.h lef.h lista.h mundo.h define.h

clean:
	rm -f *.o *~ $(MAIN)
