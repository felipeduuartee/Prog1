#include "ordenacao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void getNome(char nome[]){
    strncpy(nome, "Felipe Duarte Silva", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME-1] = '\0'; // adicionada terminação manual para caso de overflow
}

unsigned int getGRR(){
    return 20231957;
}


// Preencher o vetor
void preencherVetor(int* vetor, int tamVetor) {
    int valorAtual = tamVetor - 1;

    for (int i = 0; i < tamVetor; i++) {
        vetor[i] = valorAtual;
        valorAtual--;
    }
}

void preencherVetorOrdenado(int* vetor, int tamVetor) {
    for (int i = 0; i < tamVetor; i++) {
        vetor[i] = i;
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
    // Se o índice 'inicio' atingir o tamanho do vetor, significa que o valor não foi encontrado
    if (inicio >= tam || vetor[inicio] > valor) 
        return -1;

    (*numComparacoes)++;

    
    if (vetor[inicio] == valor) 
        return inicio;


    return buscaSequencialRecursiva(vetor, inicio + 1, tam, valor, numComparacoes);
}

// Funcao Wrapper de busca sequencial
int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes) {
    *numComparacoes = 0;
    return buscaSequencialRecursiva(vetor, 0, tam, valor, numComparacoes);
}


// Funções de busca binária recursiva
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int valor, long* numComparacoes) {
    if (inicio > fim) 
        return -1;

    int meio = inicio + (fim - inicio) / 2;

    (*numComparacoes)++;
    
    if (vetor[meio] == valor) 
        return meio; 

    else if 
        (vetor[meio] > valor) return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor, numComparacoes);
        
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


void copiar(int v[], int u[], int a, int b) {
    int i = 0;
    while (i <= b - a) {
        v[a + i] = u[i];
        i++;
    }
}

void merge(int vetor[], int inicio, int meio, int fim, long* numComparacoes) {

    if (inicio >= fim) {
        return;
    }

    int k = 0;
    int i = inicio;
    int j = meio + 1;

    // Criando um vetor auxiliar
    int *u = (int*) malloc((fim - inicio + 1) * sizeof(int));
    if (!u) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }

    while (k <= fim - inicio) {
        int p;
        if (j > fim || (i <= meio && vetor[i] <= vetor[j])) {
            p = i;
            i++;
        } else {
            p = j;
            j++;
        }
        (*numComparacoes)++; // Incrementando a contagem de comparações
        u[k] = vetor[p];
        k++;
    }

    copiar(vetor, u, inicio, fim);
    free(u); // Liberando a memória do vetor auxiliar após seu uso
}

long mergeSortRecursive(int vetor[], int a, int b, long* numComparacoes) {
    if (a >= b)
        return 0;

    int m = (a + b) / 2;
    mergeSortRecursive(vetor, a, m, numComparacoes);
    mergeSortRecursive(vetor, m + 1, b, numComparacoes);
    merge(vetor, a, m, b, numComparacoes);

    return *numComparacoes;
}

long mergeSort(int vetor[], int tam) {
    long numComparacoes = 0;
    mergeSortRecursive(vetor, 0, tam - 1, &numComparacoes);
    return numComparacoes;
}


// Função de particionamento
long particionar(int vetor[], int inicio, int fim, long* numComparacoes) {
    // Escolher o elemento do meio como pivô
    int meio = inicio + (fim - inicio) / 2;
    int x = vetor[meio];  
   
    // Trocar o pivô com o último elemento
    troca(&vetor[meio], &vetor[fim]);

    int m = inicio;
    for (int i = inicio; i <= fim - 1; i++) {
        (*numComparacoes)++;
        if (vetor[i] <= x) {
            troca(&vetor[m], &vetor[i]);
            m++;
        }
    }
    // Coloque o pivô (elemento atual do final) em sua posição correta
    troca(&vetor[m], &vetor[fim]);
    return m;
}


long quickSortRecursivo(int vetor[], int inicio, int fim, long* numComparacoes) {
    if (inicio >= fim) {
        return *numComparacoes;  // Caso base: não precisa ordenar se o segmento tem tamanho <= 1
    }
    int m = particionar(vetor, inicio, fim, numComparacoes);
    quickSortRecursivo(vetor, inicio, m - 1, numComparacoes);
    quickSortRecursivo(vetor, m + 1, fim, numComparacoes);
    return *numComparacoes;
}

long quickSort(int vetor[], int tam) {
    long numComparacoes = 0;
    quickSortRecursivo(vetor, 0, tam - 1, &numComparacoes);
    return numComparacoes;
}

