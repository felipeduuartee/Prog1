#ifndef CONJUNTO_H
#define CONJUNTO_H

typedef struct nodo {
    int valor;
    struct nodo *prox;
} Nodo;

typedef Nodo* Conjunto;

typedef struct {
    int valor;
    int quantidade;
} Duplicata;

// Protótipos
int uniao(Conjunto A, Conjunto B, Conjunto *C);
int interseccao(Conjunto A, Conjunto B, Conjunto *C);
int existe(Conjunto A, int valor);
int contem(Conjunto A, Conjunto B);
void imprime(Conjunto A);
int igual(Conjunto A, Conjunto B);
Duplicata* duplicado(Conjunto A);

#endif
