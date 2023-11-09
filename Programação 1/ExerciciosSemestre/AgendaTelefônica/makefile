# Definir o compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -Wextra

# Nome do arquivo executável
EXEC = agenda

# Todos os arquivos de origem
SRC = agenda.c lib_agenda.c
OBJ = $(SRC:.c=.o)

# Regra padrão
all: $(EXEC)

# Regra para o arquivo executável
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $@

# Regra para arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar arquivos compilados
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
