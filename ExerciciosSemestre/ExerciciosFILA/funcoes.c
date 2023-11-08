#include "fila.h"

void inicializaFila(struct Fila* f) {
    f->inicio = f->fim = 0;
}

void inicializaPilha(struct Pilha* p) {
    p->topo = 0;
}

int estaVaziaFila(struct Fila f) {
    return f.inicio == f.fim;
}

int estaVaziaPilha(struct Pilha p) {
    return p.topo == 0;
}

void enfileira(struct Fila* f, int valor) {
    f->itens[f->fim] = valor;
    f->fim = (f->fim + 1) % 100;
}

int desenfileira(struct Fila* f) {
    int valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % 100;
    return valor;
}

void empilha(struct Pilha* p, int valor) {
    p->itens[p->topo] = valor;
    p->topo++;
}

int desempilha(struct Pilha* p) {
    p->topo--;
    return p->itens[p->topo];
}

void inverteFila(struct Fila* f) {
    struct Pilha p;
    inicializaPilha(&p);
    
    while (!estaVaziaFila(*f)) {
        empilha(&p, desenfileira(f));
    }

    while (!estaVaziaPilha(p)) {
        enfileira(f, desempilha(&p));
    }
}
