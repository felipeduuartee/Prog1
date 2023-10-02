#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para criar um conjunto com base em um array
Conjunto criarConjunto(int *valores, int tamanho) {
    Conjunto A = NULL;
    for (int i = 0; i < tamanho; i++) {
        Nodo *novo = malloc(sizeof(Nodo));
        novo->valor = valores[i];
        novo->prox = A;
        A = novo;
    }
    return A;
}

int main() {
    int valoresA[] = {1, 2, 3, 4, 5};
    int valoresB[] = {4, 5, 6, 7, 8, 5};

    Conjunto A = criarConjunto(valoresA, sizeof(valoresA) / sizeof(valoresA[0]));
    Conjunto B = criarConjunto(valoresB, sizeof(valoresB) / sizeof(valoresB[0]));
    Conjunto U = NULL, I = NULL;

    printf("Conjunto A: ");
    imprime(A);

    printf("Conjunto B: ");
    imprime(B);

    if (uniao(A, B, &U)) {
        printf("Uniao de A e B: ");
        imprime(U);
    }

    if (interseccao(A, B, &I)) {
        printf("Interseccao de A e B: ");
        imprime(I);
    }

    printf("A contem 3? %s\n", existe(A, 3) ? "Sim" : "Nao");
    printf("B contem 3? %s\n", existe(B, 3) ? "Sim" : "Nao");

    printf("A contem B? %s\n", contem(A, B) ? "Sim" : "Nao");

    printf("A e B sao iguais? %s\n", igual(A, B) ? "Sim" : "Nao");

    Duplicata *dups = duplicado(B);
    for (int i = 0; dups[i].valor != -1; i++) {
        printf("Valor %d aparece %d vezes.\n", dups[i].valor, dups[i].quantidade);
    }
    free(dups);

    return 0;
}
