# Definindo o compilador
CC = gcc

# Definindo flags de compilação
CFLAGS = -Wall -O2

# Definindo o nome do executável
TARGET = programa

# Regra padrão
all: $(TARGET)

$(TARGET): main.o funcoes.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o funcoes.o

main.o: main.c conjunto.h
	$(CC) $(CFLAGS) -c main.c

funcoes.o: funcoes.c conjunto.h
	$(CC) $(CFLAGS) -c funcoes.c

clean:
	rm -f *.o $(TARGET)
