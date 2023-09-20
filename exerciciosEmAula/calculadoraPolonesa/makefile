# Definindo o compilador
CC = gcc

# Definindo as flags de compilação
CFLAGS = -Wall -Wextra -std=c99

# Nome do executável
TARGET = calculadoraRPN

# Arquivos objeto
OBJS = funcoes.o main.o

# Regra default
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	rm -f $(OBJS) # Removendo os arquivos objeto após a compilação

funcoes.o: funcoes.c pilhas.h
	$(CC) $(CFLAGS) -c funcoes.c

main.o: main.c pilhas.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJS) $(TARGET)

# Indica que 'all' e 'clean' são regras phony e não arquivos
.PHONY: all clean
