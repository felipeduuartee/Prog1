#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char nome[MAX_CHAR_NOME];
    ssize_t idxBusca;
    uint64_t numComp;

    int tamVetor = 100;  // Usado para Merge Sort
    int tamVetorInsESel = 100;  // Usado para Insertion Sort e Selection Sort
    int tamVetorBusca = 10000;  // Usado para as buscas
    int *vetor = malloc(tamVetor * sizeof(int));

    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memoria.\n");
        return 1;
    }

    preencherVetor(vetor, tamVetorInsESel);
    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    // Medição do tempo de cada algoritmo
    clock_t start, end;
    double total;

    // Insertion Sort Recursivo
    printf("\n---------Insertion Sort em vetor de %d posições---------\n", tamVetorInsESel);
    start = clock();
    numComp = insertionSortRec(vetor, tamVetorInsESel);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort Recursivo - Tempo: %f segundos, Comparacoes: %lu\n", total, numComp);
    free(vetor);
    vetor = NULL;

    // Insertion Sort Iterativo
    vetor = malloc(tamVetorInsESel * sizeof(int));
    if (vetor == NULL) {
        printf("Falha ao alocar memória para Insertion Sort Iterativo.\n");
        return 1;
    }
    preencherVetor(vetor, tamVetorInsESel);
    start = clock();
    numComp = insertionSort(vetor, tamVetorInsESel);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort Iterativo - Tempo: %f segundos, Comparacoes: %lu\n", total, numComp);
    free(vetor);
    vetor = NULL;

    // Selection Sort Recursivo
    vetor = malloc(tamVetorInsESel * sizeof(int));
    preencherVetor(vetor, tamVetorInsESel);
    printf("\n---------Selection Sort em vetor de %d posições---------\n", tamVetorInsESel);
    start = clock();
    numComp = selectionSortRec(vetor, tamVetorInsESel);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort Recursivo - Tempo: %f segundos, Comparacoes: %lu\n", total, numComp);
    free(vetor);
    vetor = NULL;

    // Selection Sort Iterativo
    vetor = malloc(tamVetorInsESel * sizeof(int));
    preencherVetor(vetor, tamVetorInsESel);
    start = clock();
    numComp = selectionSort(vetor, tamVetorInsESel);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort Iterativo - Tempo: %f segundos, Comparacoes: %lu\n", total, numComp);
    free(vetor);
    vetor = NULL;

    // Merge Sort Recursivo
    vetor = malloc(tamVetor * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memória para Merge Sort.\n");
        return 1;
    }
    preencherVetor(vetor, tamVetor);
    printf("\n---------Merge Sort em vetor de %d posições---------\n", tamVetor);
    start = clock();
    numComp = mergeSortRec(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort Recursivo - Tempo: %f segundos, Comparacoes: %lu\n", total, numComp);
    free(vetor);
    vetor = NULL;
    printf("\n");

    
    // Busca Binária Recursiva e Iterativa em um vetor ordenado
    vetor = malloc(tamVetorBusca * sizeof(int));
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memória para a busca.\n");
        return 1;
    }
    preencherVetorOrdenado(vetor, tamVetorBusca);
    
    printf("\n---------Busca Binária em vetor de %d posições---------\n", tamVetorBusca);


    
    // Busca Binária Recursiva
    start = clock();
    idxBusca = buscaBinariaRec(vetor, tamVetorBusca, -1, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Busca Binária Recursiva - Tempo: %f segundos, Comparacoes: %lu, Resultado: %zd\n", total, numComp, idxBusca);

    free(vetor);
    vetor = NULL;

    

    vetor = malloc(tamVetorBusca * sizeof(int)); 
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memória para a busca sequencial.\n");
        return 1;
    }
    preencherVetorOrdenado(vetor, tamVetorBusca); 

    // Busca Binária Iterativa
    start = clock();
    idxBusca = buscaBinaria(vetor, tamVetorBusca, 999999, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Busca Binária Iterativa %d posicoes - Tempo: %f segundos, Comparacoes: %lu, Resultado: %zd\n",tamVetorBusca, total, numComp, idxBusca);
    
    free(vetor);
    vetor = NULL;


    vetor = malloc(tamVetorBusca * sizeof(int));  
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memória para a busca sequencial.\n");
        return 1;
    }
    preencherVetorOrdenado(vetor, tamVetorBusca);  

    printf("\n---------Busca Sequencial em vetor de %d posições---------\n", tamVetorBusca);
    
    // Busca Sequencial Recursiva
    start = clock();
    idxBusca = buscaSequencialRec(vetor, tamVetorBusca, -1, &numComp);  
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Busca Sequencial Recursiva - Tempo: %f segundos, Comparacoes: %lu, Resultado: %zd\n", total, numComp, idxBusca);

    free(vetor);
    vetor = NULL;


    vetor = malloc(tamVetorBusca * sizeof(int)); 
    if (vetor == NULL) {
        printf("Falha fatal. Impossível alocar memória para a busca sequencial.\n");
        return 1;
    }
    preencherVetorOrdenado(vetor, tamVetorBusca); 

    start = clock();
    idxBusca = buscaSequencial(vetor, tamVetorBusca, 999999, &numComp); 
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Busca Sequencial Iterativa %d posicoes - Tempo: %f segundos, Comparacoes: %lu, Resultado: %zd\n",tamVetorBusca, total, numComp, idxBusca);

    free(vetor);
    vetor = NULL;

    return 0;
}

