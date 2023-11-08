#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para adicionar um elemento no final de um conjunto
void adicionar(Conjunto *A, int valor) {
    Nodo *novo = malloc(sizeof(Nodo));
    novo->valor = valor;
    novo->prox = NULL;
    if (*A == NULL) {
        *A = novo;
    } else {
        Nodo *aux = *A;
        while (aux->prox) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int uniao(Conjunto A, Conjunto B, Conjunto *C) {
    if (*C || (!A && !B)) {
        return 0; // Se C já está preenchido ou ambos A e B estão vazios
    }

    while (A) {
        adicionar(C, A->valor);
        A = A->prox;
    }
    while (B) {
        if (!existe(*C, B->valor)) {
            adicionar(C, B->valor);
        }
        B = B->prox;
    }
    return 1; // União bem-sucedida
}

int interseccao(Conjunto A, Conjunto B, Conjunto *C) {
    if (*C || (!A || !B)) {
        return 0; // Se C já está preenchido ou um dos conjuntos A ou B está vazio
    }

    while (A) {
        if (existe(B, A->valor) && !existe(*C, A->valor)) {
            adicionar(C, A->valor);
        }
        A = A->prox;
    }
    return 1; // Interseção bem-sucedida
}


int existe(Conjunto A, int valor) {
    while (A) {
        if (A->valor == valor) {
            return 1;
        }
        A = A->prox;
    }
    return 0;
}

int contem(Conjunto A, Conjunto B) {
    if (!B)
        return 1;  // Conjunto vazio é subconjunto de qualquer conjunto
    if (!A)
        return 0;  // Se A é vazio e B não é, então A não contém B

    while (B) {
        if (!existe(A, B->valor)) {
            return 0;
        }
        B = B->prox;
    }
    return 1;
}

void imprime(Conjunto A) {
    while (A) {
        printf("%d ", A->valor);
        A = A->prox;
    }
    printf("\n");
}

int igual(Conjunto A, Conjunto B) {
    while (A && B) {
        if (A->valor != B->valor) {
            return 0;
        }
        A = A->prox;
        B = B->prox;
    }
    return A == NULL && B == NULL;
}


Duplicata* duplicado(Conjunto A) {
    int count = 0;
    Nodo *atual = A;
    Duplicata *result = NULL;

    while (atual) {
        Nodo *aux = atual->prox;
        int qtd = 0;
        while (aux) {
            if (atual->valor == aux->valor) {
                qtd++;
            }
            aux = aux->prox;
        }
        if (qtd > 0) {
            result = realloc(result, (count+1)*sizeof(Duplicata));
            result[count].valor = atual->valor;
            result[count].quantidade = qtd + 1;
            count++;
        }
        atual = atual->prox;
    }

    // Adicionando um elemento finalizador para indicar o fim do array
    result = realloc(result, (count+1)*sizeof(Duplicata));
    result[count].valor = -1;  // valor sentinela
    result[count].quantidade = -1; // quantidade sentinela
    return result;
}
