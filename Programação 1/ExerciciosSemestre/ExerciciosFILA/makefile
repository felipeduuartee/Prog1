CC = gcc
CFLAGS = -Wall
TARGET = programa

all: $(TARGET)

$(TARGET): main.o funcoes.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o funcoes.o

main.o: main.c fila.h
	$(CC) $(CFLAGS) -c main.c

funcoes.o: funcoes.c fila.h
	$(CC) $(CFLAGS) -c funcoes.c

clean:
	rm -f *.o $(TARGET)
