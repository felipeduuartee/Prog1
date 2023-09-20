#ifndef FILA_H
#define FILA_H

struct Fila {
    int itens[100];
    int inicio, fim;
};

void inicializaFila(struct Fila* f);
int estaVazia(struct Fila f);
void enfileira(struct Fila* f, int valor);
int desenfileira(struct Fila* f);

#endif
