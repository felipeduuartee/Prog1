#include <stdio.h>

int negativos(float *vet, int N) {
    int count = 0;  // Contador de números negativos
    for (int i = 0; i < N; i++) {
        if (vet[i] < 0) {
            count++;  // Incrementa o contador se o número é negativo
        }
    }
    return count;  // Retorna a contagem de números negativos
}

int main() {
    float array[] = {-1.5, 2.3, -3.7, 4.1, 5.6, -6.8};
    int N = sizeof(array) / sizeof(array[0]);  // Determina o tamanho do array

    int total_negativos = negativos(array, N);
    printf("O número de elementos negativos é: %d\n", total_negativos);

    return 0;
}
