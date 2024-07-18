#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stdint.h>
#include <sys/types.h>

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR();

// funçoes auxiliares
void preencherVetorAleatorio(int* vetor, int tamVetor);
void swap(int *a, int *b);
void empilhar(int *pilha, int *topo, int valor);
void desempilhar(int *pilha, int *topo, int *valor);
void merge(int vetor[], int inicio, int meio, int fim, uint64_t *numComparacoes);
int particionar(int vetor[], int inicio, int fim, uint64_t *numComparacoes);

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

uint64_t mergeSort(int vetor[], size_t tam);
void mergeSortRecursivo(int vetor[], int inicio, int fim, uint64_t *numComparacoes);

uint64_t quickSort(int vetor[], size_t tam);
void quickSortRecursivo(int vetor[], int inicio, int fim, uint64_t *numComparacoes);

uint64_t heapSort(int vetor[], size_t tam);
void maxHeapify(int vetor[], int tam, int i, uint64_t *numComparacoes);


// As funções que terminam em SR são "Sem Recursão"
uint64_t mergeSortSR(int vetor[], size_t tam);
void mergeSortSemRecursao(int vetor[], size_t tam, uint64_t *numComparacoes);


uint64_t quickSortSR(int vetor[], size_t tam);
void quickSortNaoRecursivo(int v[], int a, int b, uint64_t *comparacoes);

uint64_t heapSortSR(int vetor[], size_t tam);
void maxHeapifySemRecursao(int vetor[], int tam, int i, uint64_t *numComparacoes);


#endif  // ORDENACAO_H_
