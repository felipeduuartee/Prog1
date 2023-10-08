#include "listas.h"

// Implementação para lista duplamente encadeada
Noh* buscarValor(ListaDuplamenteEncadeada *L, int v) {
    Noh *aux = L->cabeca;
    while (aux) {
        if (aux->dado == v) {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

// Implementação para lista circular usando vetor
void INICIALIZAR_CIRCULAR_VETOR(ListaCircularVetor *L) {
    L->inicio = L->fim = -1;
}

int VAZIA_CIRCULAR_VETOR(ListaCircularVetor *L) {
    return L->inicio == -1;
}

void INSERIR_CIRCULAR_VETOR(ListaCircularVetor *L, int valor) {
    if ((L->fim + 1) % TAM_MAX == L->inicio) return;
    
    if (L->inicio == -1) {
        L->inicio = L->fim = 0;
    } else {
        L->fim = (L->fim + 1) % TAM_MAX;
    }
    L->dados[L->fim] = valor;
}

int REMOVER_CIRCULAR_VETOR(ListaCircularVetor *L) {
    if (L->inicio == -1) return -1;
    
    int valorRemovido = L->dados[L->inicio];
    if (L->inicio == L->fim) {
        L->inicio = L->fim = -1;
    } else {
        L->inicio = (L->inicio + 1) % TAM_MAX;
    }
    return valorRemovido;
}

void IMPRIMIR_CIRCULAR_VETOR(ListaCircularVetor *L) {
    if (L->inicio == -1) return;
    
    int i = L->inicio;
    do {
        printf("%d ", L->dados[i]);
        i = (i + 1) % TAM_MAX;
    } while (i != L->fim);
    printf("%d\n", L->dados[i]);  // Imprime o último valor
}

// Implementação para lista circular duplamente encadeada com sentinela
void INICIALIZAR_CIRCULAR_DUPLO(ListaCircularDupla *L) {
    L->sentinela = (NohCircular*)malloc(sizeof(NohCircular));
    L->sentinela->proximo = L->sentinela->anterior = L->sentinela;
}

int VAZIA_CIRCULAR_DUPLO(ListaCircularDupla *L) {
    return L->sentinela->proximo == L->sentinela;
}

void INSERIR_CIRCULAR_DUPLO(ListaCircularDupla *L, int valor) {
    NohCircular *novoNoh = (NohCircular*)malloc(sizeof(NohCircular));
    novoNoh->dado = valor;
    novoNoh->proximo = L->sentinela->proximo;
    novoNoh->anterior = L->sentinela;
    L->sentinela->proximo->anterior = novoNoh;
    L->sentinela->proximo = novoNoh;
}

int REMOVER_CIRCULAR_DUPLO(ListaCircularDupla *L) {
    if (VAZIA_CIRCULAR_DUPLO(L)) return -1;
    
    NohCircular *removerNoh = L->sentinela->proximo;
    int valorRemovido = removerNoh->dado;
    L->sentinela->proximo = removerNoh->proximo;
    removerNoh->proximo->anterior = L->sentinela;
    free(removerNoh);
    return valorRemovido;
}

void IMPRIMIR_CIRCULAR_DUPLO(ListaCircularDupla *L) {
    NohCircular *aux = L->sentinela->proximo;
    while (aux != L->sentinela) {
        printf("%d ", aux->dado);
        aux = aux->proximo;
    }
    printf("\n");
}
