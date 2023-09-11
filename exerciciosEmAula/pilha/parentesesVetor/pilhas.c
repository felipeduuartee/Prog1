#include "pilhas.h"

int main(int argc, char *argv[]) {
    struct pilha parenteses;
    parenteses.topo = 0;

    if(argc < 2) {
        printf("Por favor, forneça uma expressão como argumento.\n");
        return 1; // Termina o programa com código de erro
    }

    char *expressao = argv[1];
    printf("Expressão: %s\n", expressao);

    int i = 0;
    while (expressao[i] != '\0') {
        if (expressao[i] == '(' || expressao[i] == ')') {
            if (estaVazio(parenteses) || expressao[i] == '(') {
                empilhar(&parenteses, expressao[i]);
            } else if (verTopo(parenteses) == '(') {
                desempilhar(&parenteses);
            }
        }
        i++;
    }

    printf("\nO tamanho da pilha é %d\n", parenteses.topo);

    if (eh_vazio(parenteses)) {
        printf("Está vazia\n");
    } else {
        printf("Não está vazia\n");
    }

    return 0;
}
