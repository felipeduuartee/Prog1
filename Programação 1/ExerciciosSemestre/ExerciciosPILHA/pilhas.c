#include "pilhas.h"

int main(int argc, char *argv[]) {
    struct pilha casado;
    casado.topo = 0;

    if(argc < 2) {
        printf("Por favor, forneça uma expressão como argumento.\n");
        return 1; // Termina o programa com código de erro
    }

    char *expressao = argv[1];
    printf("Expressão: %s\n", expressao);

int i = 0;
while (expressao[i] != '\0') {
    if (expressao[i] == '(') {
        empilhar(&casado, expressao[i]);
    } else if (expressao[i] == ')') {
        if (!estaVazio(casado) && verTopo(casado) == '(') {
            desempilhar(&casado);
        } else {
            empilhar(&casado, expressao[i]);
        }
    }
    i++;
}



    printf("\nO tamanho da pilha é %d\n", casado.topo);

    if (estaVazio(casado)) {
        printf("Está vazia\n");
    } else {
        printf("Não está vazia\n");
    }

    return 0;
}
