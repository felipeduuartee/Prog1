#define MATRIZ_H
#define MAX 5  // matriz 5x5

#include <stdio.h>
#include <stdlib.h>


void imprimirMatriz(float M[MAX][MAX], char* nome);
void somarMatrizes(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX]);
void multiplicarMatrizes(float A[MAX][MAX], float B[MAX][MAX], float C[MAX][MAX]);
void preencherAleatoriamente(float M[MAX][MAX]);


