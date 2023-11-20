#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função getNomeAlgoritmoExtra deve colocar o nome do algoritmo
// extra implementado no trabalho
void getNomeAlgoritmoExtra(char nomeAlg[]);

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR();

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

void swap(int *a, int *b);

void preencherVetorAleatorio(int* vetor, int tamVetor);

void preencherVetorCountingSort(unsigned int vetor[], int tam);

void copiar(int v[], int u[], int a, int b);

void merge(int vetor[], int inicio, int meio, int fim, long* numComparacoes);

unsigned long mergeSortRecursive(int vetor[], int a, int b, long* numComparacoes);

unsigned long mergeSort(int vetor[], int tam);

unsigned long quickSortRecursivo(int vetor[], int inicio, int fim, long* numComparacoes);

unsigned long quickSort(int vetor[], int tam);

long particionar(int vetor[], int inicio, int fim, long* numComparacoes);

unsigned long heapSort(int vetor[], int tam);

unsigned long maxHeapify(int vetor[], int tam, int i, unsigned long* numComparacoes);

void countingSort(unsigned int vetor[], int tam,int maxVal);  // maxVal é o k do algoritmo

// Na função algoritmoExtra implemente o algoritmo extra solicitado.
// Se o seu algoritmo escolhido não faz comparações, retorne -1.
unsigned long algoritmoExtra(int vetor[], int tam);

void inserirBucket(int *bucket, int *tamanho, int valor, unsigned long *comparacoes);

void insertionSort(int *arr, int tamanho, unsigned long *comparacoes);
#endif  // ORDENACAO_H_
