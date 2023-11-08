// fila.h
#ifndef FILA_H
#define FILA_H

#define MAX_TAM 100

struct Fila {
    int itens[MAX_TAM];
    int inicio, fim;
};

void inicializaFila(struct Fila* f);
int estaVazia(struct Fila f);
void enfileira(struct Fila* f, int valor);
int desenfileira(struct Fila* f);

#endif
