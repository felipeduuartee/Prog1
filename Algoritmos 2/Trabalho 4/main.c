#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main() {

    uint64_t numComp;
    char nome[MAX_CHAR];
    int tamVetor = 100000;
    int *vetor = (int *)malloc(tamVetor * sizeof(int));

    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memória.");
        return 1;
    }

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    clock_t start, end;
    double total;

    // Merge Sort
    preencherVetorAleatorio(vetor, tamVetor);
    start = clock();
    numComp = mergeSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);

    // Merge Sort Sem Recursão
    preencherVetorAleatorio(vetor, tamVetor);
    start = clock();
    numComp = mergeSortSR(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort SR - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);

    // Quick Sort
    preencherVetorAleatorio(vetor, tamVetor);
    start = clock();
    numComp = quickSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    

    // Quick Sort Sem Recursão
    preencherVetorAleatorio(vetor, tamVetor);
    start = clock();
    numComp = quickSortSR(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort SR - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);


    // Heap Sort
    preencherVetorAleatorio(vetor, tamVetor);
    start = clock();
    numComp = heapSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Heap Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);


    // Heap Sort Sem Recursão
    preencherVetorAleatorio(vetor, tamVetor);
    start = clock();
    numComp = heapSortSR(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Heap Sort SR - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);

    free(vetor);

    return 0;
}
