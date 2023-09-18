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
	int tamVetor = 1000000;
	int* vetor = malloc(tamVetor * sizeof(int));

	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
		
	// Preenchendo o vetor de forma aleatória
	for (int i = 0; i < tamVetor; i++) {
		vetor[i] = rand() % 1000000;
	}

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());

	//Medição do tempo de cada algoritmo
	clock_t start, end;
    double total;

	// Insertion Sort: Medição Tempo e Comparação
	start = clock();//start recebe o "ciclo" corrente
	numComp = insertionSort(vetor, tamVetor);
	end = clock();//end recebe o "ciclo" corrente
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Insertion Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);


	// Selection Sort: Medição Tempo e Comparação
	start = clock();
    numComp = selectionSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Selection Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);

	// Merge Sort: Medição Tempo e Comparação
	start = clock();
    numComp = mergeSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Merge Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);

	// Quick Sort: Medição Tempo e Comparação
	start = clock();
    numComp = quickSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Quick Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);


	// Heap Sort: Medição Tempo e Comparação
	start = clock();
    numComp = heapSort(vetor, tamVetor);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Heap Sort - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
	

	for(int i=0; i < 3; i++){
		printf("%d ", vetor[i]);
	}

	// Busca Sequencial: Medição Tempo e Comparação
	start = clock();
    idxBusca = buscaSequencial(vetor, tamVetor, 10, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Busca Sequencial - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
	printf("Resultado: %d\n", idxBusca);

	// Busca Binária: Medição Tempo e Comparação
	start = clock();
    idxBusca = buscaBinaria(vetor, tamVetor, 10, &numComp);
    end = clock();
    total = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Busca Binaria - Tempo: %f segundos, Comparacoes: %ld\n", total, numComp);
	printf("Resultado: %d\n", idxBusca);


	free(vetor);

	return 0;
}
