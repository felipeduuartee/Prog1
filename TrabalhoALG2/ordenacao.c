#include "ordenacao.h"

#include <string.h>

void getNome(char nome[]){

	strncpy(nome, "Felipe Duarte Silva", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';//adicionada terminação manual para caso de overflow
}

//a função a seguir deve retornar o seu número de GRR
unsigned int getGRR(){
	return 20231957;
}



// Função de busca ingênua em um vetor retornando o índice que se encontra o valor procurado
int buscaSequencial(int vetor[], int tam, int valor, long* numComparacoes){
	*numComparacoes = 0;

	for(int i = 0; i < tam; i++){
		*numComparacoes += 1;
		if(vetor[i] == valor){
			return i;
		}
	}
	return -1;
}

// Função de busca binária em um vetor ORDENADO retornando o 
int buscaBinaria(int vetor[], int tam, int valor, long* numComparacoes){
    int inicio = 0;
    int fim = tam - 1;

    *numComparacoes = 0; 

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;  // Fórmula para evitar overflow

        if (vetor[meio] == valor) {
            (*numComparacoes)++;
            return meio;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }

        (*numComparacoes)++;
    }

    return -1;
}



long insertionSort(int vetor[], int tam){

    if (tam <= 1)
        return 0; // Caso base

    long numComparacoes = insertionSort(vetor, tam - 1); // Chamada recursiva

    int ultimo = vetor[tam - 1];
    int j = tam - 2;

    // Move os elementos de vetor[0..i-1], que são maiores do que 
    // o elemento chave, para uma posição à frente de sua posição atual
    while (j >= 0 && vetor[j] > ultimo) {
        vetor[j + 1] = vetor[j];
        j--;
        numComparacoes++; // Incrementa a contagem de comparações
    }
    vetor[j + 1] = ultimo;

    return numComparacoes;
}



long selectionSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

long mergeSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

long quickSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}

long heapSort(int vetor[], int tam){
	vetor[0] = 99;
	return -1;
}