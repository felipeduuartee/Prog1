# Definindo o compilador
CC = gcc

# Definindo as opções do compilador
CFLAGS = -Wall -O2

# Definindo o nome do executável
TARGET = listas

all: $(TARGET)

$(TARGET): main.o listas.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o listas.o

main.o: main.c listas.h
	$(CC) $(CFLAGS) -c main.c

listas.o: listas.c listas.h
	$(CC) $(CFLAGS) -c listas.c

clean:
	rm -f *.o $(TARGET)
