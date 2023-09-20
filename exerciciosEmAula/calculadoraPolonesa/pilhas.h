#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct pilha {
    int topo;
    double pilha[100];
};

void empilhar(struct pilha *p, double novo);
void desempilhar(struct pilha *p);
int estaCheio(struct pilha p);
int estaVazio(struct pilha p);
double verTopo(struct pilha p);
