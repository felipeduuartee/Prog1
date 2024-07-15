#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#define MAX_CHAR_NOME 50

// a função getNome deve colocar o seu nome dentro da chamada
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR();

void preencherVetor(int* vetor, int tamVetor);

void preencherVetorOrdenado(int* vetor, int tamVetor);

void imprimirVetor(int vetor[], int tam);

void troca(int *a, int *b);

// Assuma que os vetores estão ordenados ao chamar as funções de busca
// As funções de busca não devem alterar o vetor
// O retorno das funções de busca é o índice do elemento no vetor,
// ou -1 caso o elemeno não exista no vetor
// Você deve armazenar no ponteiro int* numComparacoes o número de comparações
// envolvendo elementos do vetor feito pelo seu algoritmo na chamada

// Implemente a versão recursiva nos algoritmos que terminam em Rec, e a versão
// iterativa nos demais

// a busca sequencial é a busca ingênua

ssize_t buscaSequencialRecursiva(int vetor[], ssize_t inicio, size_t tam, int valor, uint64_t* numComparacoes);
ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor,
                           uint64_t* numComparacoes);

ssize_t buscaSequencial(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes);

// busca binária no vetor
ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor,
                        uint64_t* numComparacoes);

ssize_t buscaBinariaRecursiva(int vetor[], ssize_t inicio, ssize_t fim, int valor, uint64_t* numComparacoes);

ssize_t buscaBinaria(int vetor[], size_t tam, int valor,
                     uint64_t* numComparacoes);

// Cada uma das funções deve ordenar o vetor passado como parâmetro
// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor realizado


void insert(int vetor[], size_t n, uint64_t* numComparacoes);

uint64_t insertionSortRecursivo(int vetor[], size_t n);
uint64_t insertionSortRec(int vetor[], size_t tam);

uint64_t insertionSort(int vetor[], size_t tam);

size_t encontrarMenor(int vetor[], size_t inicio, size_t tam, uint64_t* numComparacoes);

uint64_t selectionSortRecursivo(int vetor[], int inicio, int tam);

uint64_t selectionSortRec(int vetor[], size_t tam);

uint64_t selectionSort(int vetor[], size_t tam);

void copiar(int v[], int u[], int a, int b);

void merge(int vetor[], int inicio, int meio, int fim, uint64_t* numComparacoes);

uint64_t mergeSortRecursivo(int vetor[], int a, int b);

uint64_t mergeSortRec(int vetor[], size_t tam);

#endif  // ORDENACAO_H_