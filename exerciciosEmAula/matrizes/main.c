
#include "matriz.h"

int main() {
    float A[MAX][MAX], B[MAX][MAX], Resultado[MAX][MAX];

    srand(0);

    // Preenchendo as matrizes A e B aleatoriamente
    preencherAleatoriamente(A);
    preencherAleatoriamente(B);

    // Somando matrizes
    somarMatrizes(A, B, Resultado);
    printf("Resultado da Soma:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%.2f ", Resultado[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Multiplicando matrizes
    multiplicarMatrizes(A, B, Resultado);
    printf("Resultado da Multiplicação:\n");
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            printf("%.2f ", Resultado[i][j]);
        }
        printf("\n");
    }

    return 0;
}
