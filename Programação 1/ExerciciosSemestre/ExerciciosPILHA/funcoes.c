#include "pilhas.h"

void empilhar(struct pilha *p, char prox) {

    if (estaCheio(*p)) {
        printf("A pilha está cheia!\n ");
        exit(1);
    }

    (*p).pilha[(*p).topo] = prox;
    (*p).topo++;

};

void desempilhar(struct pilha *p) {

    (*p).topo--;
    (*p).pilha[(*p).topo] = 0;

};


int estaCheio(struct pilha p) {
    
        if (p.topo == 100) {
            return 1;
        };
    
        return 0;
};

int estaVazio(struct pilha p) {

    if (p.topo == 0) {
        return 1;
    };

    return 0;
};

char verTopo(struct pilha p) {
    return p.pilha[p.topo-1];
};

