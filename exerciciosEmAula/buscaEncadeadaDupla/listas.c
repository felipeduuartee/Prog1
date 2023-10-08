#include "listas.h"

void INICIALIZAR(ListaDuplamenteEncadeada *L) {
    L->cabeca = NULL;
}

Noh* buscarValor(ListaDuplamenteEncadeada *L, int valor) {
    Noh *atual = L->cabeca;
    while (atual) {
        if (atual->dado == valor) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void IMPRIMIR(ListaDuplamenteEncadeada *L) {
    Noh *atual = L->cabeca;
    printf("Lista: ");
    while (atual) {
        printf("%d ", atual->dado);
        atual = atual->proximo;
    }
    printf("\n");
}

void INSERIR(ListaDuplamenteEncadeada *L, int valor) {
    Noh *novo = malloc(sizeof(Noh));
    novo->dado = valor;
    novo->anterior = NULL;
    novo->proximo = L->cabeca;
    if (L->cabeca != NULL) {
        L->cabeca->anterior = novo;
    }
    L->cabeca = novo;
}
