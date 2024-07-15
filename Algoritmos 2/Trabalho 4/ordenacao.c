#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getNome(char nome[]) {
    strncpy(nome, "Felipe Duarte Silva", MAX_CHAR);
    nome[MAX_CHAR - 1] = '\0';
}

uint32_t getGRR() { return 20231957; }

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void preencherVetorAleatorio(int* vetor, int tamVetor) {
    srand(0);
    for (int i = 0; i < tamVetor; i++) {
        vetor[i] = rand() % tamVetor; // Gere um número aleatório entre 0 e tamVetor
    }
}

void merge(int vetor[], int inicio, int meio, int fim, uint64_t *numComparacoes) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda = (int *)malloc(n1 * sizeof(int));
    int *direita = (int *)malloc(n2 * sizeof(int));

    if (!esquerda || !direita) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++) {
        esquerda[i] = vetor[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        direita[j] = vetor[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        (*numComparacoes)++;
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}

void mergeSortRecursivo(int vetor[], int inicio, int fim, uint64_t *numComparacoes) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSortRecursivo(vetor, inicio, meio, numComparacoes);
        mergeSortRecursivo(vetor, meio + 1, fim, numComparacoes);

        merge(vetor, inicio, meio, fim, numComparacoes);
    }
}

uint64_t mergeSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    mergeSortRecursivo(vetor, 0, tam - 1, &numComparacoes);
    return numComparacoes;
}





void mergeSortSemRecursao(int vetor[], size_t tam, uint64_t *numComparacoes) {
    for (int tamAtual = 1; tamAtual < tam; tamAtual *= 2) {
        for (int inicio = 0; inicio < tam; inicio += 2 * tamAtual) {
            int meio = inicio + tamAtual - 1;
            int fim;
            if (inicio + 2 * tamAtual - 1 < tam) {
                fim = inicio + 2 * tamAtual - 1;
            } else {
                fim = tam - 1;
            }
            
            if (meio < fim) {
                merge(vetor, inicio, meio, fim, numComparacoes);
            }
        }
    }
}

uint64_t mergeSortSR(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    mergeSortSemRecursao(vetor, tam, &numComparacoes);
    return numComparacoes;
}
















int particionar(int vetor[], int inicio, int fim, uint64_t *numComparacoes) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        (*numComparacoes)++;
        if (vetor[j] <= pivo) {
            i++;
            swap(&vetor[i], &vetor[j]);
        }
    }
    swap(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

void quickSortRecursivo(int vetor[], int inicio, int fim, uint64_t *numComparacoes) {
    if (inicio < fim) {
        int pi = particionar(vetor, inicio, fim, numComparacoes);

        quickSortRecursivo(vetor, inicio, pi - 1, numComparacoes);
        quickSortRecursivo(vetor, pi + 1, fim, numComparacoes);
    }
}

uint64_t quickSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    quickSortRecursivo(vetor, 0, tam - 1, &numComparacoes);
    return numComparacoes;
}

void quickSortNaoRecursivo(int v[], int a, int b, uint64_t *comparacoes) {
    int *p = (int *)malloc((b - a + 1) * sizeof(int));
    int top = -1;
    p[++top] = a;
    p[++top] = b;

    while (top >= 0) {
        b = p[top--];
        a = p[top--];

        if (a < b) {
            int m = particionar(v, a, b, comparacoes);
            p[++top] = a;
            p[++top] = m - 1;
            p[++top] = m + 1;
            p[++top] = b;
        }
    }

    free(p);
}


uint64_t quickSortSR(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    quickSortNaoRecursivo(vetor, 0, tam - 1, &numComparacoes);    
    return numComparacoes;
}

void maxHeapify(int vetor[], int tam, int i, uint64_t *numComparacoes) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < tam && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }
    if (direita < tam && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    if (maior != i) {
        (*numComparacoes)++;
        swap(&vetor[i], &vetor[maior]);
        maxHeapify(vetor, tam, maior, numComparacoes);
    }
}

uint64_t heapSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;

    for (int i = tam / 2 - 1; i >= 0; i--) {
        maxHeapify(vetor, tam, i, &numComparacoes);
    }

    for (int i = tam - 1; i > 0; i--) {
        swap(&vetor[0], &vetor[i]);
        maxHeapify(vetor, i, 0, &numComparacoes);
    }

    return numComparacoes;
}

void maxHeapifySemRecursao(int vetor[], int tam, int i, uint64_t *numComparacoes) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    while (esquerda < tam) {
        if (vetor[esquerda] > vetor[maior]) {
            maior = esquerda;
        }
        if (direita < tam && vetor[direita] > vetor[maior]) {
            maior = direita;
        }
        if (maior != i) {
            (*numComparacoes)++;
            swap(&vetor[i], &vetor[maior]);
            i = maior;
            esquerda = 2 * i + 1;
            direita = 2 * i + 2;
        } else {
            break;
        }
    }
}

uint64_t heapSortSR(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;

    for (int i = tam / 2 - 1; i >= 0; i--) {
        maxHeapifySemRecursao(vetor, tam, i, &numComparacoes);
    }

    for (int i = tam - 1; i > 0; i--) {
        swap(&vetor[0], &vetor[i]);
        maxHeapifySemRecursao(vetor, i, 0, &numComparacoes);
    }

    return numComparacoes;
}

