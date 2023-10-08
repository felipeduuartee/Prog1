#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct noh {
    int dado;
    struct noh *anterior;
    struct noh *proximo;
} Noh;

typedef struct listaDuplamenteEncadeada {
    Noh *cabeca;
} ListaDuplamenteEncadeada;

Noh* buscarValor(ListaDuplamenteEncadeada *L, int v);
void INSERIR(ListaDuplamenteEncadeada *L, int valor);
void INICIALIZAR(ListaDuplamenteEncadeada *L);
void IMPRIMIR(ListaDuplamenteEncadeada *L);

#endif
