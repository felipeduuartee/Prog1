#include <stdio.h>

void max_ocorrencias(int arr[], int N, int *max_val, int *ocorrencias) {
    *max_val = arr[0];  // Inicializa com o primeiro valor do array
    *ocorrencias = 1;  // Inicializa com 1 ocorrência

    // Loop para encontrar o maior valor
    for (int i = 1; i < N; i++) {
        if (arr[i] > *max_val) {
            *max_val = arr[i];
            *ocorrencias = 1;  // Reinicia a contagem de ocorrências
        } else if (arr[i] == *max_val) {
            (*ocorrencias)++;  // Incrementa o contador de ocorrências
        }
    }
}

int main() {
    int array[] = {5, 2, 15, 3, 7, 15, 8, 6, 15};
    int N = sizeof(array) / sizeof(array[0]);  // Determina o tamanho do array
    int maior_valor, vezes;

    max_ocorrencias(array, N, &maior_valor, &vezes);

    printf("O maior valor é %d e ele ocorre %d vezes.\n", maior_valor, vezes);

    return 0;
}
