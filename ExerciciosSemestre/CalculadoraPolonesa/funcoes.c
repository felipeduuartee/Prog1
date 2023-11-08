#include "pilhas.h"

void empilhar(struct pilha *p, double valor) {
    if (estaCheio(*p)) {
        printf("A pilha está cheia!\n");
        exit(1);
    }

    p->pilha[p->topo] = valor;
    p->topo++;
}

void desempilhar(struct pilha *p) {
    if (!estaVazio(*p)) {
        p->topo--;
    }
}

double verTopo(struct pilha p) {
    if (!estaVazio(p)) {
        return p.pilha[p.topo - 1];
    }
    printf("A pilha está vazia!\n");
    exit(1);
    return 0;  // Nunca chegará aqui, mas evita warnings de compilação
}

int estaCheio(struct pilha p) {
    return p.topo == 100;
}

int estaVazio(struct pilha p) {
    return p.topo == 0;
}
