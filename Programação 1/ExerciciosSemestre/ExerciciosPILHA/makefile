# Definir o compilador
CC = gcc

# Definir as flags de compilação
CFLAGS = -Wall -Wextra

# Nome do executável
TARGET = programa

all: $(TARGET)

$(TARGET): funcoes.o pilhas.o
	$(CC) $(CFLAGS) -o $(TARGET) funcoes.o pilhas.o

funcoes.o: funcoes.c pilhas.h
	$(CC) $(CFLAGS) -c funcoes.c

pilhas.o: pilhas.c pilhas.h
	$(CC) $(CFLAGS) -c pilhas.c

clean:
	rm -f *.o $(TARGET)
