#include "listas.h"

int main() {

    printf("\n");
    printf("5 exercícios da lista do professor Grégio em um código com alguns testes ja implementados\n");
    printf("\n");
    
    // Testes para Lista Duplamente Encadeada
    ListaDuplamenteEncadeada L;
    Noh *nohBuscado;

    printf("Testes para Lista Duplamente Encadeada:\n");

// Inicialização da lista
L.cabeca = NULL;  // Isso significa que a lista está vazia

// Inserindo alguns elementos
Noh *novo1 = (Noh*)malloc(sizeof(Noh));
novo1->dado = 10;
novo1->proximo = NULL;
novo1->anterior = NULL;
L.cabeca = novo1;  // Este é o primeiro elemento, então se torna a cabeça da lista

Noh *novo2 = (Noh*)malloc(sizeof(Noh));
novo2->dado = 20;
novo2->proximo = NULL;
novo2->anterior = novo1;
novo1->proximo = novo2;  // O segundo nó é ligado após o primeiro

Noh *novo3 = (Noh*)malloc(sizeof(Noh));
novo3->dado = 30;
novo3->proximo = NULL;
novo3->anterior = novo2;
novo2->proximo = novo3;  // O terceiro nó é ligado após o segundo

// Imprimir lista
Noh *iter = L.cabeca;
while(iter) {
    printf("%d ", iter->dado);
    iter = iter->proximo;
}
printf("\n");
    nohBuscado = buscarValor(&L, 5);
    if (nohBuscado) {
        printf("Valor %d encontrado.\n", nohBuscado->dado);
    } else {
        printf("Valor não encontrado.\n");
    }

    // Testes para Lista Circular com Vetor
    ListaCircularVetor LC;
    INICIALIZAR_CIRCULAR_VETOR(&LC);

    printf("\nTestes para Lista Circular com Vetor:\n");
    if (VAZIA_CIRCULAR_VETOR(&LC)) {
        printf("Lista está vazia.\n");
    }

    INSERIR_CIRCULAR_VETOR(&LC, 10);
    INSERIR_CIRCULAR_VETOR(&LC, 20);
    INSERIR_CIRCULAR_VETOR(&LC, 30);

    IMPRIMIR_CIRCULAR_VETOR(&LC);

    printf("Valor removido: %d\n", REMOVER_CIRCULAR_VETOR(&LC));
    IMPRIMIR_CIRCULAR_VETOR(&LC);

    // Testes para Lista Circular Duplamente Encadeada com Sentinela
    ListaCircularDupla LCD;
    INICIALIZAR_CIRCULAR_DUPLO(&LCD);

    printf("\nTestes para Lista Circular Duplamente Encadeada com Sentinela:\n");
    if (VAZIA_CIRCULAR_DUPLO(&LCD)) {
        printf("Lista está vazia.\n");
    }

    INSERIR_CIRCULAR_DUPLO(&LCD, 40);
    INSERIR_CIRCULAR_DUPLO(&LCD, 50);
    INSERIR_CIRCULAR_DUPLO(&LCD, 60);

    IMPRIMIR_CIRCULAR_DUPLO(&LCD);

    printf("Valor removido: %d\n", REMOVER_CIRCULAR_DUPLO(&LCD));
    IMPRIMIR_CIRCULAR_DUPLO(&LCD);

    return 0;
}
