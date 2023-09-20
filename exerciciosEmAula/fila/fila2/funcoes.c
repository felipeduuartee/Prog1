#include "fila.h"
#include <stdio.h>

void inicializaFila(struct Fila* f) {
    f->inicio = f->fim = 0;
}

int estaVazia(struct Fila f) {
    return f.inicio == f.fim;
}

void enfileira(struct Fila* f, int valor) {
    if (f->fim == 100) {
        if (f->inicio == 0) {
            printf("A fila está cheia!\n");
            return;
        }
        for (int i = f->inicio, j = 0; i < f->fim; i++, j++) {
            f->itens[j] = f->itens[i];
        }
        f->fim -= f->inicio;
        f->inicio = 0;
    }
    f->itens[f->fim] = valor;
    f->fim++;
}

int desenfileira(struct Fila* f) {
    if (estaVazia(*f)) {
        printf("A fila está vazia!\n");
        return -1;
    }
    return f->itens[f->inicio++];
}
