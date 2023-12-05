#ifndef _CONJUNTO_H
#define _CONJUNTO_H

#include <stdbool.h>

// Representa um conjunto de inteiros
struct cjto_t
{
  int tamanho;       // número máximo de valores para armazenar
  int num;           // cardinalidade (número atual de elementos)
  bool *flag;        // aponta para um array de booleanos de "tamanho"
};

struct cjto_t *cjto_criar(int max);

struct cjto_t *cjto_destruir(struct cjto_t *c);

int cjto_adicionar(struct cjto_t *c, int elemento);

int cjto_remover(struct cjto_t *c, int elemento);

int cjto_pertence(struct cjto_t *c, int elemento);

int cjto_vazio(struct cjto_t *c);

int cjto_cardinalidade(struct cjto_t *c);

int cjto_contem(struct cjto_t *c1, struct cjto_t *c2);

int cjto_igual(struct cjto_t *c1, struct cjto_t *c2);

int cjto_uniao(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3);

int cjto_intersecao(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3);

int cjto_diferenca(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3);

int cjto_copiar(struct cjto_t *c1, struct cjto_t *c2);

void cjto_imprimir(struct cjto_t *c);

#endif
