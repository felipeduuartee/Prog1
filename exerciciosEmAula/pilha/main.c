#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
    Pilha pilhaParenteses;
    inicializarPilha(&pilhaParenteses);
    int estaBalanceado = 1;  // Usado para marcar se a expressão está balanceada ou não

    if (argc < 2) {
        printf("Por favor, forneça uma expressão numérica como argumento.\n");
        return 1;
    }

    char *expressao = argv[1];
    int tamanho = strlen(expressao);

    for (int i = 0; i < tamanho; i++) {
        if (expressao[i] == '(') {
            empilha(&pilhaParenteses, '(');
        } else if (expressao[i] == ')') {
            if (pilhaVazia(&pilhaParenteses)) {
                estaBalanceado = 0;  // Marca que não está balanceado
            } else {
                desempilha(&pilhaParenteses, NULL);  // Não precisamos do valor desempilhado
            }
        }
    }

    int tamanhoAtual = tamanhoPilha(&pilhaParenteses);
    if (estaBalanceado && tamanhoAtual == 0) {
        printf("A pilha está correta e seu tamanho é 0 (vazia).\n");
    } else {
        printf("A pilha não está correta. Seu tamanho é %d.\n", tamanhoAtual);
    }

    return 0;
}
