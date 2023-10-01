#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int main()
{
    char nome[MAX_CHAR_NOME];
    int idxBusca;
    long numComp;

    // Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
    // Veja um exemplo de alocação dinâmica a seguir
    int tamVetor = 1000000000;
    int tamVetorInsESel = 100000;
    int *vetor = malloc(tamVetorInsESel * sizeof(int));

    if (vetor == NULL)
    {
        printf("Falha fatal. Impossível alocar memoria.");
        return 1;
    }

    preencherVetor(vetor, tamVetorInsESel);

    getNome(nome);
    printf("Trabalho de %s\n", nome);
    printf("GRR %u\n", getGRR());

    // Medição do tempo de cada algoritmo
    clock_t start, end;
    double total;

    printf("\n");
    printf("---------Vetor de %d posições---------\n", tamVetorInsESel);
    printf("\n");

    // Insertion Sort: Medição Tempo e Comparação

    start = clock(); // start recebe o "ciclo" corrente

    numComp = insertionSort(vetor, tamVetorInsESel);

    end = clock(); // end recebe o "ciclo" corrente
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Insertion Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    free(vetor);

    // "Desordenar" o vetor novamente
    vetor = malloc(tamVetorInsESel * sizeof(int));

    preencherVetor(vetor, tamVetorInsESel);

    // Selection Sort: Medição Tempo e Comparação
    start = clock();
    numComp = selectionSort(vetor, tamVetorInsESel);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Selection Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    free(vetor);

    printf("\n");
    printf("---------Vetor de %d posições---------\n", tamVetor);
    printf("\n");



    
    // "Desordenar" o vetor novamente
    vetor = malloc(tamVetor * sizeof(int));
    preencherVetor(vetor, tamVetor);
    // Merge Sort: Medição Tempo e Comparação
    start = clock();
    numComp = mergeSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Merge Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);

    free(vetor);

    // "Desordenar" o vetor novamente
    vetor = malloc(tamVetor * sizeof(int));
    preencherVetor(vetor, tamVetor);
    // Quick Sort: Medição Tempo e Comparação
    start = clock();
    numComp = quickSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Quick Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);

    free(vetor);



    vetor = malloc(tamVetor * sizeof(int));
    preencherVetorOrdenado(vetor, tamVetor);
    // Busca Sequencial: Medição Tempo e Comparação
    start = clock();
    idxBusca = buscaSequencial(vetor, tamVetor, 100001, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;

    printf("Busca Sequencial - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    printf("Resultado: %d\n", idxBusca);
    
    free(vetor);



    vetor = malloc(tamVetor * sizeof(int));
    preencherVetorOrdenado(vetor, tamVetor);
    // Busca Binária: Medição Tempo e Comparação
    start = clock();
    idxBusca = buscaBinaria(vetor, tamVetor, 1000000001, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Busca Binaria - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    printf("Resultado: %d\n", idxBusca);

    free(vetor);

    return 0;
}
