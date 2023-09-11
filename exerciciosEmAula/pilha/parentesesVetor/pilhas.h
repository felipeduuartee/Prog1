#include <stdio.h>

struct pilha {
    int topo;
    char pilha[100];
};

void empilhar(struct pilha *p, char novo) {

    (*p).pilha[(*p).topo] = novo;
    (*p).topo++;
    
};