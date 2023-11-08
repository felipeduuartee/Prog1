#ifndef FILA_H
#define FILA_H

struct Fila {
    int itens[100];
    int inicio, fim;
};

struct Pilha {
    int itens[100];
    int topo;
};

void inicializaFila(struct Fila* f);
void inicializaPilha(struct Pilha* p);
int estaVaziaFila(struct Fila f);
int estaVaziaPilha(struct Pilha p);
void enfileira(struct Fila* f, int valor);
int desenfileira(struct Fila* f);
void empilha(struct Pilha* p, int valor);
int desempilha(struct Pilha* p);
void inverteFila(struct Fila* f);

#endif
