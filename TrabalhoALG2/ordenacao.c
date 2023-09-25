#include "ordenacao.h"
#include <string.h>
#include <stdio.h>

void getNome(char nome[]){
    strncpy(nome, "Felipe Duarte Silva", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME-1] = '\0'; // adicionada terminação manual para caso de overflow
}

unsigned int getGRR(){
    return 20231957;
}


// Preencher o vetor
void preencherVetor(int* vetor, int tamVetor) {
    int valorAtual = tamVetor;

    for (int i = 0; i < tamVetor; i++) {
        vetor[i] = valorAtual;
        valorAtual--;
    }
}

// Função auxiliar para imprimir o vetor
void imprimirVetor(int vetor[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
// Função universal para troca de valores
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funções de busca sequencial recursiva
int buscaSequencialRecursiva(int vetor[], int inicio, int tam, int valor, long* numComparacoes) {
    (*numComparacoes)++;
    if (inicio >= tam) return -1;
    if (vetor[inicio] == valor) return inicio;
    return buscaSequencialRecursiva(vetor, inicio + 1, tam, valor, numComparacoes);
}

// Funcao Wrapper de busca sequencial
int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes) {
    *numComparacoes = 0;
    return buscaSequencialRecursiva(vetor, 0, tam, valor, numComparacoes);
}

// Funções de busca binária recursiva
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor, long* numComparacoes) {
    if (inicio > fim) return -1;
    int meio = (inicio + fim) / 2;
    (*numComparacoes)++;
    if (vetor[meio] == valor) return meio; 
    else if (vetor[meio] > valor) return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor, numComparacoes);
    else return buscaBinariaRecursiva(vetor, meio + 1, fim, valor, numComparacoes);
}

// Funcao Wrapper de busca binaria
int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes) {
    *numComparacoes = 0;
    return buscaBinariaRecursiva(vetor, 0, tam - 1, valor, numComparacoes);
}

// Funções auxiliar do insertion sort
void insert(int vetor[], int n, long* numComparacoes) {
    int ultimo = vetor[n-1];
    int j = n-2;
    
    // Enquanto o elemento anterior for maior que o 'ultimo', movemos os elementos
    while (j >= 0 && vetor[j] > ultimo) {
        (*numComparacoes)++;
        vetor[j + 1] = vetor[j];
        j--;
    }
    
    // Inserir o 'ultimo' na posição correta
    vetor[j + 1] = ultimo;
}


// Funcao recursiva de Insertion Sort
long insertionSortRec(int vetor[], int n) {
    if (n <= 1) 
        return 0;

    long comparacoes = insertionSortRec(vetor, n-1);
    
    // Inicializamos a contagem de comparações para esta chamada específica da função insert
    long localComparacoes = 0;
    insert(vetor, n, &localComparacoes);

    // Retorna o total de comparações (anteriores + atuais)
    return comparacoes + localComparacoes;
}


// Funcao Wrapper Insertion Sort
long insertionSort(int vetor[], int tam) {
    return insertionSortRec(vetor, tam);
}

// Funções auxiliares do selection sort
int encontrarMenor(int vetor[], int inicio, int tam, long* numComparacoes) {
    int minIdx = inicio;
    for (int i = inicio + 1; i < tam; i++) {
        (*numComparacoes)++;
        if (vetor[i] < vetor[minIdx]) minIdx = i;
    }
    return minIdx;
}

// Funcao recursiva de Selection Sort
void selectionSortRecursivo(int vetor[], int inicio, int tam, long* numComparacoes) {
    if (inicio >= tam - 1) return;
    int minIdx = encontrarMenor(vetor, inicio, tam, numComparacoes);
    troca(&vetor[inicio], &vetor[minIdx]);
    selectionSortRecursivo(vetor, inicio + 1, tam, numComparacoes);
}

// Funcao Wrapper Selection Sort
long selectionSort(int vetor[], int tam) {
    long numComparacoes = 0;
    selectionSortRecursivo(vetor, 0, tam, &numComparacoes);
    return numComparacoes;
}

// Funções auxiliares do merge sort
void merge(int vetor[], int inicio, int meio, int fim, long* numComparacoes) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Criar vetores temporários
    int L[n1], R[n2];

    // Copiar dados para vetores temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = vetor[inicio + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = vetor[meio + 1 + j];
    }

    // Merge dos vetores temporários de volta para o vetor original
    i = 0; 
    j = 0; 
    k = inicio;
    while (i < n1 && j < n2) {
        (*numComparacoes)++;
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

long mergeSort(int vetor[], int tam) {
    long numComparacoes = 0;
    // Começamos com sub-arrays de tamanho 1 e dobramos o tamanho em cada iteração.
    for (int curr_tam = 1; curr_tam <= tam-1; curr_tam = 2*curr_tam) {
        for (int inicio = 0; inicio < tam-1; inicio += 2*curr_tam) {
            int meio = inicio + curr_tam - 1;
            int fim = (inicio + 2*curr_tam - 1 < tam) ? (inicio + 2*curr_tam - 1) : (tam-1);
            merge(vetor, inicio, meio, fim, &numComparacoes);
        }
    }
    return numComparacoes;
}

long partition(int vetor[], int inicio, int fim, long* numComparacoes) {
    int pivot = vetor[fim]; 
    int i = inicio - 1;
    for (int j = inicio; j <= fim - 1; j++) {
        (*numComparacoes)++;
        if (vetor[j] < pivot) {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[fim]);
    return (i + 1);
}

long quickSortRecursivo(int vetor[], int inicio, int fim, long* numComparacoes) {
    if (inicio < fim) {
        int pi = partition(vetor, inicio, fim, numComparacoes);
        quickSortRecursivo(vetor, inicio, pi - 1, numComparacoes);
        quickSortRecursivo(vetor, pi + 1, fim, numComparacoes);
    }
    return *numComparacoes;
}

long quickSort(int vetor[], int tam) {
    long numComparacoes = 0;
    quickSortRecursivo(vetor, 0, tam - 1, &numComparacoes);
    return numComparacoes;
}

void maxHeapify(int vetor[], int tam, int i, long* numComparacoes) {
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;
    if (esquerda < tam && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
        (*numComparacoes)++;
    }
    if (direita < tam && vetor[direita] > vetor[maior]) {
        maior = direita;
        (*numComparacoes)++;
    }
    if (maior != i) {
        troca(&vetor[i], &vetor[maior]);
        maxHeapify(vetor, tam, maior, numComparacoes);  // Recursão no nó filho
    }
}

long heapSort(int vetor[], int tam) {
    long numComparacoes = 0;
    for (int i = tam / 2 - 1; i >= 0; i--) {
        maxHeapify(vetor, tam, i, &numComparacoes);
    }
    for (int i = tam - 1; i > 0; i--) {
        troca(&vetor[0], &vetor[i]);
        maxHeapify(vetor, i, 0, &numComparacoes);
    }
    return numComparacoes;
}
