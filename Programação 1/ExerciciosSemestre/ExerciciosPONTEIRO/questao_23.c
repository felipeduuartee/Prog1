#include <stdio.h>

// Função para determinar o maior valor de um array
int maior_valor(int arr[], int N) {
    int max = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int N, k;

    // Lendo o tamanho N do array
    printf("Informe o tamanho do array (N): ");
    scanf("%d", &N);

    int array[N];

    // Lendo os elementos do array
    printf("Digite os %d valores do array:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    // Lendo o valor de k
    printf("Digite o número de elementos por linha (k): ");
    scanf("%d", &k);

    // Imprimindo o array com k elementos por linha
    printf("\nArray:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % k == 0) {
            printf("\n");  // Quebra de linha após imprimir k elementos
        }
    }

    // Imprimindo o maior elemento
    printf("\nMaior elemento: %d\n", maior_valor(array, N));

    return 0;
}
