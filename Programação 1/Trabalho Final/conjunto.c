#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include "conjunto.h"



// cria o conjunto
struct cjto_t *cjto_criar(int max) {
    struct cjto_t *c;

    c = malloc(sizeof(struct cjto_t));
    
    if (!c) {
        printf("Erro ao alocar cjto_t *c\n");
        return NULL;
    }
    
    c->flag = malloc(max * sizeof(bool));
    
    if (!c->flag) {
        printf("Erro ao alocar c->flag\n");
        return NULL;
    }
    
    c->num = 0;
    c->tamanho = max;
    return c;
}

// destroi o conjunto, libera a memoria
struct cjto_t *cjto_destruir(struct cjto_t *c) {
    if (!c)
        return NULL;
    if (!c->flag)
        return NULL;
    free(c->flag);
    free(c);
    return NULL;
}

// Adiciona um item ao conjunto.
int cjto_adicionar(struct cjto_t *c, int elemento) {
    
    if (!c)
        return 0;
    
    if (!c->flag)
        return 0;
    
    if (elemento >= c->tamanho)
        return 0;
    
    if (c->flag[elemento] == false) {
        c->flag[elemento] = true;
        c->num++;
    }
    return 1;
}

// Remove um item do conjunto.
int cjto_remover(struct cjto_t *c, int elemento) {
    
    if (!c)
        return 0;
    
    if (!c->flag)
        return 0;
    
    if (elemento >= c->tamanho)
        return 0;
    
    if (c->flag[elemento] == true) {
        c->flag[elemento] = false;
        c->num--;
    }
    return 1;
}

// Verifica se um elemento pertence ao conjunto.
int cjto_pertence(struct cjto_t *c, int elemento) {
    
    if (!c || !c->flag)
        return 0;
    
    if (c->flag[elemento])
        return 1;
    
    return 0;
}

// Verifica se o conjunto está vazio.
int cjto_vazio(struct cjto_t *c) {
    
    if (!c)
        return 0;
    
    if (!c->flag)
        return 0;
    
    if (c->num == 0) {
        printf("conjunto vazio\n");
        return 1;
    
    }
    return 0;
}

// Informa a cardinalidade do conjunto (número de elementos presentes no cjto)

int cjto_cardinalidade(struct cjto_t *c) {
    
    if (!c)
        return 0;
    
    if (!c->flag)
        return 0;
    
    if (c->num == 0)
        return 0;
    
    return c->num;
}

// Verifica se c1 contém c2
int cjto_contem(struct cjto_t *c1, struct cjto_t *c2) {
    if (!c1 || !c2)
        return 0;
    if (!c1->flag || !c2->flag)
        return 0;
    int i, maior;
    if (c1->tamanho > c2->tamanho)
        maior = c1->tamanho;
    else
        maior = c2->tamanho;
    for (i = 0; i < maior; i++) {
        if (c1->flag[i] == false && c2->flag[i] == true)
            return 0;
    }
    return 1;
}

// Verifica se c1 == c2
int cjto_igual(struct cjto_t *c1, struct cjto_t *c2) {
    int i, maior;

    if (!c1 || !c2)
        return 0;
    
    if (!c1->flag || !c2->flag)
        return 0;
    
    if (c1->tamanho > c2->tamanho)
        maior = c1->tamanho;
    
    else
        maior = c2->tamanho;
    
    for (i = 0; i < maior; i++) {
        
        if (c1->flag[i] != c2->flag[i])
            return 0;
    }
    
    return 1;
}

// Coloca em c3 a união dos conjuntos c1 e c2; c3 conteúdo anterior
// é apagado, mas seu intervalo (0, max) não é modificado
// Return: 1 em caso de sucesso ou 0 em caso de falha
int cjto_uniao(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3) {
    if (!c1 || !c2)
        return 0;
    if (!c1->flag || !c2->flag)
        return 0;
    int i;
    for (i = 0; i < c3->tamanho; i++) {
        if (c1->flag[i] == true || c2->flag[i] == true) {
            c3->flag[i] = true;
            c3->num++;
        }
    }

    return 1;
}

// Coloca em c3 a interseção dos conjuntos c1 e c2; c3 conteúdo anterior
// é apagado, mas seu intervalo (0, max) não é modificado
// Return: 1 em caso de sucesso ou 0 em caso de falha
int cjto_intersecao(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3) {
    if (!c1 || !c2)
        return 0;
    if (!c1->flag || !c2->flag)
        return 0;
    int i;
    for (i = 0; i < c3->tamanho; i++) {
        if (c1->flag[i] == true && c2->flag[i] == true) {
            c3->flag[i] = true;
            c3->num++;
        }
    }
    return 1;
}

// Coloca em c3 a diferença c1 - c2; c3 conteúdo anterior é apagado,
// mas seu intervalo (0, max) não é modificado
// Return: 1 em caso de sucesso ou 0 em caso de falha
int cjto_diferenca(struct cjto_t *c1, struct cjto_t *c2, struct cjto_t *c3) {
    if (!c1 || !c2 || !c3)
        return 0;
    if (!c1->flag || !c2->flag || !c3->flag)
        return 0;
    int i;
    for (i = 0; i < c3->tamanho; i++) {
        if (c1->flag[i] != c2->flag[i])
            c3->flag[i] = true;
    }
    return 1;
}

// Coloca em c2 uma cópia do conjunto c1; c2 conteúdo anterior é apagado,
// mas seu intervalo (0, max) não é modificado
// Return: 1 em caso de sucesso ou 0 em caso de falha
int cjto_copiar(struct cjto_t *c1, struct cjto_t *c2) {
    if (!c1 || !c2)
        return 0;
    if (!c1->flag || !c2->flag)
        return 0;
    int i;
    for (i = 0; i < c2->tamanho; i++) {
        c2->flag[i] = c1->flag[i];
    }
    return 1;
}

// Imprime o conteúdo de um conjunto usando este modelo:
// [ %d %d %d ] (%d itens)\n
// (Não faz parte da definição do TAD, mas é útil para testes)
void cjto_imprimir(struct cjto_t *c) {
    if (!c)
        return;
    if (!c->flag)
        return;
    int i;
    printf("[");
    for (i = 0; i < c->tamanho; i++) {
        if (c->flag[i] == true)
            printf(" %d ", i);
    }
    printf("] (%d itens)\n", c->num);
}
