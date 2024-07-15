#include "ordenacao.h"

#include <string.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Felipe Duarte Silva", MAX_CHAR_NOME);
    nome[MAX_CHAR_NOME - 1] =
        '\0';  // adicionada terminação manual para caso de overflow
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20231957; }

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

// Função de busca sequencial iterativa
ssize_t buscaSequencial(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    for (size_t i = 0; i < tam; i++) {
        if (vetor[i] == valor)
            return i;  
        (*numComparacoes)++;
    }
    return -1;
}


// Função auxiliar para busca sequencial recursiva
ssize_t buscaSequencialRecursiva(int vetor[], ssize_t inicio, size_t tam, int valor, uint64_t* numComparacoes) {
    if (inicio >= tam)
        return -1;

    (*numComparacoes)++; 

    if (vetor[inicio] == valor)
        return inicio; 

    return buscaSequencialRecursiva(vetor, inicio + 1, tam, valor, numComparacoes); // Chamada recursiva para o próximo índice
}

// Função wrapper para iniciar a busca sequencial recursiva
ssize_t buscaSequencialRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    *numComparacoes = 0; 
    return buscaSequencialRecursiva(vetor, 0, tam, valor, numComparacoes);
}


// Função de busca binária iterativa
ssize_t buscaBinaria(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    size_t inicio = 0, fim = tam - 1;
    while (inicio <= fim) {
        size_t meio = inicio + (fim - inicio) / 2;
        (*numComparacoes)++;

        if (vetor[meio] == valor)
            return meio;
        else if (vetor[meio] > valor)
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return -1; 
}




// Função auxiliar para busca binária recursiva
ssize_t buscaBinariaRecursiva(int vetor[], ssize_t inicio, ssize_t fim, int valor, uint64_t* numComparacoes) {
    if (inicio > fim)
        return -1;  // Caso base: intervalo inválido, valor não encontrado

    ssize_t meio = inicio + (fim - inicio) / 2;  

    (*numComparacoes)++;  // Incrementa a contagem de comparações

    if (vetor[meio] == valor)
        return meio;  // Valor encontrado na posição 'meio'
    else if (vetor[meio] > valor)
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, valor, numComparacoes);  // Busca na subparte esquerda
    else
        return buscaBinariaRecursiva(vetor, meio + 1, fim, valor, numComparacoes);  // Busca na subparte direita
}

// Função wrapper para iniciar a busca binária recursiva
ssize_t buscaBinariaRec(int vetor[], size_t tam, int valor, uint64_t* numComparacoes) {
    *numComparacoes = 0;  // Inicializa o contador de comparações
    return buscaBinariaRecursiva(vetor, 0, tam - 1, valor, numComparacoes);
}


// Função auxiliar para insertion sort
void insert(int vetor[], size_t n, uint64_t* numComparacoes) {

    int elemento = vetor[n-1];
    ssize_t j = n-2;

    // Move elementos maiores que key uma posição à frente de sua posição atual
    while (j >= 0 && vetor[j] > elemento) {
        (*numComparacoes)++;
        vetor[j + 1] = vetor[j];
        j--;
    }

    vetor[j + 1] = elemento;
}



// Insertion Sort Iterativo
uint64_t insertionSort(int vetor[], size_t tam) {
    uint64_t numComparacoes = 0;
    for (size_t i = 1; i < tam; i++) {
        insert(vetor, i, &numComparacoes);
    }
    return numComparacoes;
}


// Funcao recursiva de Insertion Sort
uint64_t insertionSortRecursivo(int vetor[], size_t n) {
    if (n <= 1)
        return 0;

    // Chamada recursiva para ordenar os primeiros n-1 elementos
    uint64_t comparacoes = insertionSortRecursivo(vetor, n-1);
    
    // Contagem de comparações para esta chamada específica da função insert
    uint64_t localComparacoes = 0;
    insert(vetor, n, &localComparacoes);

    // Retorna o total de comparações (anteriores + atuais)
    return comparacoes + localComparacoes;
}

// Função Wrapper Insertion Sort Recursivo 
uint64_t insertionSortRec(int vetor[], size_t tam) {
    return insertionSortRecursivo(vetor, tam);
}


size_t encontrarMenor(int vetor[], size_t inicio, size_t tam, uint64_t* numComparacoes) {
    
    size_t minIdx = inicio;

    for (size_t i = inicio + 1; i < tam; i++) {
        (*numComparacoes)++;

        if (vetor[i] < vetor[minIdx])
            minIdx = i;
    }

    return minIdx;
}



// Selection Sort Iterativo
uint64_t selectionSort(int vetor[], size_t tam) {

    uint64_t numComparacoes = 0;

    for (size_t i = 0; i < tam - 1; i++) {
        size_t minIdx = encontrarMenor(vetor, i, tam, &numComparacoes);

        if (i != minIdx)
            troca(&vetor[i], &vetor[minIdx]);
    }

    return numComparacoes;
}

// Funcao recursiva de Selection Sort
 uint64_t selectionSortRecursivo(int vetor[], int inicio, int tam) {

    if (inicio >= tam - 1) {
        return 0; // Caso base: chegou no último elemento ou não há elementos suficientes para ordenar
    }

    uint64_t numComparacoes = 0;
    int minIdx = encontrarMenor(vetor, inicio, tam, &numComparacoes);
    troca(&vetor[inicio], &vetor[minIdx]);

    // Acumula as comparações da chamada atual com as chamadas subsequentes
    numComparacoes += selectionSortRecursivo(vetor, inicio + 1, tam);
    return numComparacoes;
}

// Função Wrapper Selection Sort Recursivo
uint64_t selectionSortRec(int vetor[], size_t tam) {
   return selectionSortRecursivo(vetor, 0, tam);
}


void copiar(int v[], int u[], int a, int b) {
    int i = 0;
    while (i <= b - a) {
        v[a + i] = u[i];
        i++;
    }
}

void merge(int vetor[], int inicio, int meio, int fim, uint64_t* numComparacoes) {

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

// Merge Sort Recursivo
uint64_t mergeSortRecursivo(int vetor[], int a, int b) {
    uint64_t numComparacoes = 0;

    if (a < b) {
        int m = a + (b - a) / 2;
        numComparacoes += mergeSortRecursivo(vetor, a, m);
        numComparacoes += mergeSortRecursivo(vetor, m + 1, b);
        merge(vetor, a, m, b, &numComparacoes);
    }

    return numComparacoes;
}

// Função Wrapper para o Merge Sort
uint64_t mergeSortRec(int vetor[], size_t tam) {
    if (tam == 0) return 0;
    return mergeSortRecursivo(vetor, 0, tam - 1);
}
