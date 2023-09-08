
#include "matriz.h"

int main() {
    float A[MAX][MAX];

    srand(0);

    preencherAleatoriamente(A);

    printf("Matriz A (preenchida aleatoriamente):\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
