#include "pilha.h"


int tamanhoPilha(Pilha* p) {
    return p->topo + 1;
}

void inicializarPilha(Pilha* p) {
    p->topo = -1;
}

int pilhaVazia(Pilha* p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha* p) {
    return p->topo == TAMANHO_PILHA - 1;
}

int empilha(Pilha* p, char valor) {
    if (pilhaCheia(p)) {
        return 0; // Falha, pilha cheia
    }
    p->topo++;
    p->itens[p->topo] = valor;
    return 1; // Sucesso
}

int desempilha(Pilha* p, char* valorRetirado) {
    if (pilhaVazia(p)) {
        return 0; // Falha, pilha vazia
    }
    if (valorRetirado) {
        *valorRetirado = p->itens[p->topo];
    }
    p->topo--;
    return 1; // Sucesso
}
