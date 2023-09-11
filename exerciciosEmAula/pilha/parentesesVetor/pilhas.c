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

   for(int i = 0; i < 100; i++) {
        if(expressao[i] == '\0') {
            break;
        }
        if(expressao[i] == '(') {
            empilhar(&casado, expressao[i]);
        }
        if(expressao[i] == ')') {
            desempilhar(&casado);
        }
   }


    printf("\nO tamanho da pilha é %d\n", casado.topo);

    if (estaVazio(casado)) {
        printf("Está vazia\n");
    } else {
        printf("Não está vazia\n");
    }

    return 0;
}
