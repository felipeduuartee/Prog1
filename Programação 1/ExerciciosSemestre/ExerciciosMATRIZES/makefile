# Definindo o compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -g

# Nome do executável
TARGET = main


all: $(TARGET)


$(TARGET): main.o funcoes.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o funcoes.o


main.o: main.c matriz.h
	$(CC) $(CFLAGS) -c main.c


funcoes.o: funcoes.c matriz.h
	$(CC) $(CFLAGS) -c funcoes.c


clean:
	rm -f *.o $(TARGET)
