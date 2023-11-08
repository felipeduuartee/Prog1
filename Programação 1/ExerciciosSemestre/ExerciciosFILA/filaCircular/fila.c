// fila.c
#include "fila.h"
#include <stdio.h>

void inicializaFila(struct Fila* f) {
    f->inicio = f->fim = 0;
}

int estaVazia(struct Fila f) {
    return f.inicio == f.fim;
}

void enfileira(struct Fila* f, int valor) {
    if ((f->fim + 1) % MAX_TAM == f->inicio) {
        printf("A fila está cheia!\n");
        return;
    }
    f->itens[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX_TAM;
}

int desenfileira(struct Fila* f) {
    if (estaVazia(*f)) {
        printf("A fila está vazia!\n");
        return -1;
    }
    int valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_TAM;
    return valor;
}
