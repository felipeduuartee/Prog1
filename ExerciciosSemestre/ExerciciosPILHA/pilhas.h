#include <stdio.h>
#include <stdlib.h>

struct pilha {
    int topo;
    char pilha[100];
};

void empilhar(struct pilha *p, char novo);
void desempilhar(struct pilha *p);
int estaCheio(struct pilha p);
int estaVazio(struct pilha p);
char verTopo(struct pilha p);