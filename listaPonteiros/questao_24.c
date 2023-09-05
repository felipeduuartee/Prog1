#include <stdio.h>

void min_max(int V[], int N, int *min, int *max) {
    *min = V[0];  // Inicializar com o primeiro valor do array
    *max = V[0];  // Inicializar com o primeiro valor do array

    for (int i = 1; i < N; i++) {
        if (V[i] < *min) {
            *min = V[i];
        }
        if (V[i] > *max) {
            *max = V[i];
        }
    }
}

int main() {
    int N;

    printf("Informe o tamanho do array: ");
    scanf("%d", &N);

    int array[N];

    printf("Digite os %d elementos do array:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    int min_val, max_val;
    min_max(array, N, &min_val, &max_val);

    printf("Valor mínimo: %d\n", min_val);
    printf("Valor máximo: %d\n", max_val);

    return 0;
}
