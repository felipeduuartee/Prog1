#ifndef _LISTA_H
#define _LISTA_H

// estrutura de um nodo da lista
typedef struct lnode_t {
  int val ;			// valor armazenado
  struct lnode_t *prev ;	// no anterior
  struct lnode_t *next ;	// no seguinte
} lnode_t;

// estrutura de uma lista
typedef struct {
  lnode_t *head ;		// primeiro elemento
  lnode_t *tail ;		// último elemento
  int size ;			// tamanho da lista
} lista_t;

lista_t* lista_cria ();

lista_t* lista_destroi (lista_t* lst);

int lista_insere (lista_t* lst, int elem, int pos);

int lista_retira (lista_t* lst, int* elem, int pos);

int lista_consulta (lista_t* lst, int* elem, int pos);

int lista_procura (lista_t* lst, int elem);

int lista_vazia (lista_t* lst);

int lista_tamanho (lista_t* lst);

void lista_imprime (char *nome, lista_t* lst);

#endif

