# Nome do executável final
PROG = tp2

# Todos os arquivos .c
SRCS = tp2.c racionais.c

# Todos os arquivos .o
OBJS = $(SRCS:.c=.o)

# Compilador
CC = gcc

# Flags do compilador
CFLAGS = -Wall -g

# Regra padrão (all)
all: $(PROG)

# Linkagem final
$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

# Como transformar .c em .o
.c.o:
	$(CC) $(CFLAGS) -c $<

# Limpar arquivos .o e o executável
clean:
	rm -f $(OBJS) $(PROG)

# Para executar com: make run
run: $(PROG)
	./$(PROG)
