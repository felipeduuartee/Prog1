CC=gcc
CFLAGS=-Wall -g
OBJS=main.o funcoes.o

balanceado: $(OBJS)
	$(CC) $(CFLAGS) -o balanceado $(OBJS)

main.o: main.c pilha.h
	$(CC) $(CFLAGS) -c main.c

funcoes.o: funcoes.c pilha.h
	$(CC) $(CFLAGS) -c funcoes.c

clean:
	rm -f $(OBJS) balanceado
