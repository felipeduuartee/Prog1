// Tipo Abstrato de Dados "conjunto de inteiros"
// implementado usando um vetor de booleanos
// Carlos Maziero - DINF/UFPR, Setembro de 2023

// Esta implementação de conjunto usa um vetor de flags booleanas para representar
// o conteúdo do conjunto: se flag[x] == true, então x está no conjunto

// ESTE ARQUIVO NÃO DEVE SER MODIFICADO

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

// Cria um conjunto vazio capaz de armazenar "tamanho" valores (de 0 a tamanho -1)
// Retorno: ponteiro para o novo conjunto ou NULL em caso de falha
struct cjto_t *cjto_criar(int max);

// Destroi o conjunto, liberando sua memória
// Retorno: NULL
struct cjto_t *cjto_destruir(struct cjto_t *c);

// Adiciona um elemento ao conjunto.
// Retorno: 1 em caso de sucesso ou 0 em caso de falha
int cjto_adicionar(struct cjto_t *c, int elemento);

// Remove um elemento do conjunto.
// Retorno: 1 em caso de sucesso ou 0 em caso de falha
int cjto_remover(struct cjto_t *c, int elemento);

// Verifica se um elemento pertence ao conjunto.
// Retorno: 1 se pertence ou 0 se não pertence
int cjto_pertence(struct cjto_t *c, int elemento);

// Verifica se o conjunto está vazio.
// Retorno: 1 se estiver vazio ou 0 se não estiver vazio
int cjto_vazio(struct cjto_t *c);

// Informa a cardinalidade do conjunto (número de elementos ou |S|)
// Retorno: n >= 0 em caso de sucesso ou -1 em caso de falha
int cjto_cardinalidade(struct cjto_t *c);

// Verifica se c1 contém c2
// Retorno: 1 em caso de sucesso ou 0 em caso de falha
int cjto_contem(struct cjto_t *c1, struct cjto_t *c2);

// Verifica se c1 == c2
// Retorno: 1 em caso de sucesso ou 0 em caso de falha
int cjto_igual(struct cjto_t *c1, struct cjto_t *c2);

// Coloca em c3 a união dos conjuntos c1 e c2; o conteúdo anterior de c3
// é apagado, mas seu intervalo (0, max) não é modificado
// Retorno: 1 em caso de sucesso ou 0 em caso de falha
int cjto_uniao(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3);

// Coloca em c3 a interseção dos conjuntos c1 e c2; o conteúdo anterior de c3
// é apagado, mas seu intervalo (0, max) não é modificado
// Retorno: 1 em caso de sucesso ou 0 em caso de falha
int cjto_intersecao(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3);

// Coloca em c3 a diferença c1 - c2; o conteúdo anterior de c3 é apagado,
// mas seu intervalo (0, max) não é modificado
// Retorno: 1 em caso de sucesso ou 0 em caso de falha
int cjto_diferenca(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3);

// Coloca em c2 uma cópia do conjunto c1; o conteúdo anterior de c2 é apagado,
// mas seu intervalo (0, max) não é modificado
// Retorno: 1 em caso de sucesso ou 0 em caso de falha
int cjto_copiar(struct cjto_t *c1, struct cjto_t *c2);

// Imprime o conteúdo de um conjunto usando este modelo:
// [ %d %d %d ]\n
// (Não faz parte da definição do TAD, mas é útil para testes)
void cjto_imprimir(struct cjto_t *c);

#endif
