#ifndef LISTAS_H
#define LISTAS_H

#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

// Estrutura para lista duplamente encadeada
typedef struct noh {
    int dado;
    struct noh *anterior;
    struct noh *proximo;
} Noh;

typedef struct listaDuplamenteEncadeada {
    Noh *cabeca;
} ListaDuplamenteEncadeada;

Noh* buscarValor(ListaDuplamenteEncadeada *L, int v);

// Estrutura para lista circular usando vetor
typedef struct {
    int dados[TAM_MAX];
    int inicio;
    int fim;
} ListaCircularVetor;

void INICIALIZAR_CIRCULAR_VETOR(ListaCircularVetor *L);
int VAZIA_CIRCULAR_VETOR(ListaCircularVetor *L);
void INSERIR_CIRCULAR_VETOR(ListaCircularVetor *L, int valor);
int REMOVER_CIRCULAR_VETOR(ListaCircularVetor *L);
void IMPRIMIR_CIRCULAR_VETOR(ListaCircularVetor *L);

// Estrutura para lista circular duplamente encadeada com sentinela
typedef struct noh_circular {
    int dado;
    struct noh_circular *anterior;
    struct noh_circular *proximo;
} NohCircular;

typedef struct {
    NohCircular *sentinela;
} ListaCircularDupla;

void INICIALIZAR_CIRCULAR_DUPLO(ListaCircularDupla *L);
int VAZIA_CIRCULAR_DUPLO(ListaCircularDupla *L);
void INSERIR_CIRCULAR_DUPLO(ListaCircularDupla *L, int valor);
int REMOVER_CIRCULAR_DUPLO(ListaCircularDupla *L);
void IMPRIMIR_CIRCULAR_DUPLO(ListaCircularDupla *L);

#endif
