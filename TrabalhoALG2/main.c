#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

int main(){
        char nome[MAX_CHAR_NOME];
        int idxBusca;
        long numComp;

        //Dica: somente é posśivel criar vetores grandes utilizando alocação dinâmica de memória
        //Veja um exemplo de alocação dinâmica a seguir
        int tamVetor = 10;
        int* vetor = malloc(tamVetor * sizeof(int));

        if(vetor == NULL){
                printf("Falha fatal. Impossível alocar memoria.");
                return 1;
        }

        // Preenchendo o vetor de forma aleatória
       /* for (int i = 0; i < tamVetor; i++) {
                vetor[i] = rand() % 100;
        }
        */

        preencherVetor(vetor, tamVetor);
        

        getNome(nome);
        printf("Trabalho de %s\n", nome);
        printf("GRR %u\n", getGRR());

        //Medição do tempo de cada algoritmo
        clock_t start, end;
        double total;

        printf("---------Vetor de %d posições---------\n", tamVetor);
        printf("\n");

        imprimirVetor(vetor, tamVetor);

        
        // Insertion Sort: Medição Tempo e Comparação
        start = clock();//start recebe o "ciclo" corrente
        numComp = insertionSort(vetor, tamVetor);
        end = clock();//end recebe o "ciclo" corrente
        total = ((double)end - start)/CLOCKS_PER_SEC;
        imprimirVetor(vetor, tamVetor);
        printf("Insertion Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
        free(vetor);
    
        // "Desordenar" o vetor novamente
        vetor = malloc(tamVetor * sizeof(int));
        preencherVetor(vetor, tamVetor);
        // Selection Sort: Medição Tempo e Comparação
        start = clock();
    numComp = selectionSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    imprimirVetor(vetor, tamVetor);
    printf("Selection Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    free(vetor);

         // "Desordenar" o vetor novamente
        vetor = malloc(tamVetor * sizeof(int));
        preencherVetor(vetor, tamVetor);
        // Merge Sort: Medição Tempo e Comparação
        start = clock();
    numComp = mergeSort(vetor, tamVetor);
	    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
        imprimirVetor(vetor, tamVetor);
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
    imprimirVetor(vetor, tamVetor);
    printf("Quick Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
    free(vetor);

         // "Desordenar" o vetor novamente
        vetor = malloc(tamVetor * sizeof(int));
        preencherVetor(vetor, tamVetor);
        // Heap Sort: Medição Tempo e Comparação
        start = clock();
    numComp = heapSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    imprimirVetor(vetor, tamVetor);
    printf("Heap Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
 
 
        // Busca Sequencial: Medição Tempo e Comparação
        start = clock();
    idxBusca = buscaSequencial(vetor, tamVetor, 3, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    imprimirVetor(vetor, tamVetor);
    printf("Busca Sequencial - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
        printf("Resultado: %d\n", idxBusca);

        // Busca Binária: Medição Tempo e Comparação
        start = clock();
    idxBusca = buscaBinaria(vetor, tamVetor, 3, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Busca Binaria - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
        printf("Resultado: %d\n", idxBusca);

        free(vetor);

        return 0;
}
