
#include "matriz.h"

int main() {
    float A[MAX][MAX], B[MAX][MAX], Resultado[MAX][MAX];

    srand(0);

    // Preenchendo as matrizes A e B aleatoriamente
    preencherAleatoriamente(A);
    preencherAleatoriamente(B);

    // Imprimindo as matrizes A e B
    imprimirMatriz(A, "Matriz A");
    imprimirMatriz(B, "Matriz B");

    // Somando matrizes
    somarMatrizes(A, B, Resultado);
    imprimirMatriz(Resultado, "Resultado da Soma");

    // Multiplicando matrizes
    multiplicarMatrizes(A, B, Resultado);
    imprimirMatriz(Resultado, "Resultado da Multiplicação");

    return 0;
}
