#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ordenacao.h"

int main() {

    char nomeAlg[MAX_CHAR];
    unsigned long numComp;
    char nome[MAX_CHAR];
    unsigned int *vetorUnsigned;
    int tamVetor = 10000;
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

    // Bucket Sort
    getNomeAlgoritmoExtra(nomeAlg);
    printf("Executando %s\n", nomeAlg);
    preencherVetorAleatorio(vetor, tamVetor);

    start = clock();
    numComp = algoritmoExtra(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Bucket Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    free(vetor);
    
    
    // Merge Sort
    vetor = (int *)malloc(tamVetor * sizeof(int));
    preencherVetorAleatorio(vetor, tamVetor);

    start = clock();
    numComp = mergeSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Merge Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    free(vetor);


    // Quick Sort
    vetor = (int *)malloc(tamVetor * sizeof(int));
    preencherVetorAleatorio(vetor, tamVetor);

    start = clock();
    numComp = quickSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Quick Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    free(vetor);


    
    // Heap Sort
    vetor = (int *)malloc(tamVetor * sizeof(int));
    preencherVetorAleatorio(vetor, tamVetor);

    start = clock();
    numComp = heapSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Heap Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    free(vetor);

 
    // Counting Sort para vetor de unsigned ints
    vetorUnsigned = (unsigned int *)malloc(tamVetor * sizeof(unsigned int));
    preencherVetorCountingSort(vetorUnsigned, tamVetor);

    start = clock();
    countingSort(vetorUnsigned, tamVetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Counting Sort - Tempo: %f segundos\n", total);

    free(vetorUnsigned);

    return 0;
}
