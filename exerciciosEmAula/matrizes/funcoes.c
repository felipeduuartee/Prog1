#include "matriz.h"


void somarMatrizes(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplicarMatrizes(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            C[i][j] = 0;
            for (int k = 0; k < MAX; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void preencherAleatoriamente(float M[MAX][MAX]) {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            M[i][j] = (float)rand() / RAND_MAX * 100; 
        }
    }
}
