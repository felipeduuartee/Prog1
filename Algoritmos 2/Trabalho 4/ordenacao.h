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

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

uint64_t mergeSort(int vetor[], size_t tam);

uint64_t quickSort(int vetor[], size_t tam);

uint64_t heapSort(int vetor[], size_t tam);

// As funções que terminam em SR são "Sem Recursão"
uint64_t mergeSortSR(int vetor[], size_t tam);

uint64_t quickSortSR(int vetor[], size_t tam);

uint64_t heapSortSR(int vetor[], size_t tam);

void swap(int *a, int *b);
void merge(int vetor[], int inicio, int meio, int fim, uint64_t *numComparacoes);
void mergeSortRecursivo(int vetor[], int inicio, int fim, uint64_t *numComparacoes);
int particionar(int vetor[], int inicio, int fim, uint64_t *numComparacoes);
void quickSortRecursivo(int vetor[], int inicio, int fim, uint64_t *numComparacoes);
void maxHeapify(int vetor[], int tam, int i, uint64_t *numComparacoes);
void mergeSortSemRecursao(int vetor[], size_t tam, uint64_t *numComparacoes);
void quickSortNaoRecursivo(int v[], int a, int b, uint64_t *comparacoes);
void maxHeapifySemRecursao(int vetor[], int tam, int i, uint64_t *numComparacoes);
void preencherVetorAleatorio(int* vetor, int tamVetor);


#endif  // ORDENACAO_H_