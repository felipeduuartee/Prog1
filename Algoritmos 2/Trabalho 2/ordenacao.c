#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Felipe Duarte Silva", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

void getNomeAlgoritmoExtra(char nomeAlg[]) {
    // substitua pelo nome do algoritmo que você escolheu
    strncpy(nomeAlg, "Bucket Sort", MAX_CHAR);
    nomeAlg[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
unsigned int getGRR() { return 20231957; }


// Função auxiliar para trocar dois elementos em um vetor
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void preencherVetorAleatorio(int* vetor, int tamVetor) {
    srand(0); // Seed do gerador de números aleatórios com base no tempo atual

    for (int i = 0; i < tamVetor; i++) {
        vetor[i] = rand() % tamVetor; // Gere um número aleatório entre 0 e tamVetor
    }
}

void preencherVetorCountingSort(unsigned int vetor[], int tam) {
    unsigned int valorAtual = tam - 1;

    for (int i = 0; i < tam; i++) {
        vetor[i] = valorAtual;
        valorAtual--;
    } 
}

void copiar(int v[], int u[], int a, int b) {
    int i = 0;
    while (i <= b - a) {
        v[a + i] = u[i];
        i++;
    }
}


// Função auxiliar para o Merge Sort
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

// Implementação do algoritmo Merge Sort recursivo
unsigned long mergeSortRecursive(int vetor[], int a, int b, long* numComparacoes) {
    if (a >= b)
        return 0;

    int m = (a + b) / 2;
    mergeSortRecursive(vetor, a, m, numComparacoes);
    mergeSortRecursive(vetor, m + 1, b, numComparacoes);
    merge(vetor, a, m, b, numComparacoes);

    return *numComparacoes;
}

unsigned long mergeSort(int vetor[], int tam) {
    long numComparacoes = 0;
    mergeSortRecursive(vetor, 0, tam - 1, &numComparacoes);
    return numComparacoes;
}

// Implementação do algoritmo Quick Sort recursivo
unsigned long quickSortRecursivo(int vetor[], int inicio, int fim, long* numComparacoes) {
    if (inicio >= fim) {
        return *numComparacoes; // caso base
    }
    int m = particionar(vetor, inicio, fim, numComparacoes);
    quickSortRecursivo(vetor, inicio, m - 1, numComparacoes);
    quickSortRecursivo(vetor, m + 1, fim, numComparacoes);
    return *numComparacoes;
}

// Função Wrapper do Quick Sort
unsigned long quickSort(int vetor[], int tam) {
    long numComparacoes = 0;
    quickSortRecursivo(vetor, 0, tam - 1, &numComparacoes);
    return numComparacoes;
}


// Função de particionamento
long particionar(int vetor[], int inicio, int fim, long* numComparacoes) {
    // Escolher o elemento do meio como pivô
    int meio = inicio + (fim - inicio) / 2;
    int x = vetor[meio];  
   
    // Trocar o pivô com o último elemento
    swap(&vetor[meio], &vetor[fim]);

    int m = inicio;
    for (int i = inicio; i <= fim - 1; i++) {
        (*numComparacoes)++;
        if (vetor[i] <= x) {
            swap(&vetor[m], &vetor[i]);
            m++;
        }
    }
    // Coloque o pivô (elemento atual do final) em sua posição correta
    swap(&vetor[m], &vetor[fim]);
    return m;
}

// Implementação do algoritmo Heap Sort com recursão em max-heapify
unsigned long maxHeapify(int vetor[], int tam, int i, unsigned long* numComparacoes) {
    int comp = 0;
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < tam) {
        (*numComparacoes)++;
        if (vetor[esquerda] > vetor[maior]) {
            maior = esquerda;
        }
    }

    if (direita < tam) {
        (*numComparacoes)++;
        if (vetor[direita] > vetor[maior]) {
            maior = direita;
        }
    }

    if (maior != i) {
        swap(&vetor[i], &vetor[maior]);
        comp++;
        comp += maxHeapify(vetor, tam, maior, numComparacoes);
    }

    return comp;
}

// Função Wrapper do Heap Sort
unsigned long heapSort(int vetor[], int tam) {
    unsigned long comp = 0;

    for (int i = tam / 2 - 1; i >= 0; i--) {
        comp += maxHeapify(vetor, tam, i, &comp);
    }

    for (int i = tam - 1; i >= 0; i--) {
        swap(&vetor[0], &vetor[i]);
        comp++;
        comp += maxHeapify(vetor, i, 0, &comp);
    }

    return comp;
}

// Implementação do algoritmo Counting Sort
void countingSort(unsigned int vetor[], int tam, int maxVal) {
    int *count = (int *)calloc(maxVal + 1, sizeof(int));
    unsigned int *output = (unsigned int *)malloc(tam * sizeof(unsigned int));

    for (int i = 0; i < tam; i++) {
        count[vetor[i]]++;
    }

    for (int i = 1; i <= maxVal; i++) {
        count[i] += count[i - 1];
    }

    for (int i = tam - 1; i >= 0; i--) {
        output[count[vetor[i]] - 1] = vetor[i];
        count[vetor[i]]--;
    }

    for (int i = 0; i < tam; i++) {
        vetor[i] = output[i];
    }

    free(count);
    free(output);
}


// Função para inserir um elemento em uma lista de buckets
void inserirBucket(int *bucket, int *tamanho, int valor, unsigned long *comparacoes) {
    int i;
    for (i = *tamanho - 1; (i >= 0 && bucket[i] > valor); i--) {
        bucket[i + 1] = bucket[i];
        (*comparacoes)++;
    }
    bucket[i + 1] = valor;
    (*tamanho)++;
}


// Função de ordenação de inserção para ordenar os buckets
void insertionSort(int *arr, int tamanho, unsigned long *comparacoes) {
    for (int i = 1; i < tamanho; i++) {
        int chave = arr[i];
        int j = i - 1;

        // Incrementar as comparações aqui
        (*comparacoes)++;

        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j--;

            // Incrementar as comparações para cada comparação dentro do loop
            (*comparacoes)++;
        }
        arr[j + 1] = chave;
    }
}


// Função do Bucket Sort que retorna o número de comparações
unsigned long algoritmoExtra(int vetor[], int tam) {
    unsigned long comparacoes = 0;
    int max_value = vetor[0];
    
    // Encontrando o valor máximo no vetor
    for (int i = 1; i < tam; i++) {
        if (vetor[i] > max_value) {
            max_value = vetor[i];
        }
    }
    
    int numBuckets = tam; // Número de buckets baseado no tamanho do vetor    int **buckets = (int **)malloc(numBuckets * sizeof(int *));
    int **buckets = (int **)malloc(numBuckets * sizeof(int *));
    int *tamanhosBuckets = (int *)calloc(numBuckets, sizeof(int));

    // Inicialização dos buckets
    for (int i = 0; i < tam; i++) {
        buckets[i] = (int *)malloc((max_value + 1) * sizeof(int)); // Alocando espaço suficiente para todos os possíveis valores
        if (buckets[i] == NULL) {
            printf("Falha na alocação de memória");
            exit(1);
        }
    }

    // Distribuição dos elementos nos buckets
    for (int i = 0; i < tam; i++) {
        int indice = vetor[i] / (max_value / numBuckets + 1);
        inserirBucket(buckets[indice], &tamanhosBuckets[indice], vetor[i], &comparacoes);
    }

    // Ordenação dos buckets e preenchimento do vetor final
    int indiceVetor = 0;
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i], tamanhosBuckets[i], &comparacoes);
        for (int j = 0; j < tamanhosBuckets[i]; j++) {
            vetor[indiceVetor++] = buckets[i][j];
        }
    }

    // Liberação de memória
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(tamanhosBuckets);

    return comparacoes;
}
