#include "pilhas.h"
#include <string.h>

int main(int argc, char *argv[]) {
    struct pilha calc;
    calc.topo = 0;

    if (argc < 2) {
        printf("Por favor, forneça uma expressão RPN como argumento.\n");
        return 1;
    }

    double num, a, b;

    for (int argIndex = 1; argIndex < argc; argIndex++) {
        if (sscanf(argv[argIndex], "%lf", &num) == 1) {
            empilhar(&calc, num);
        } else if (strchr("+-*/", argv[argIndex][0])) {
            b = verTopo(calc);
            desempilhar(&calc);
            a = verTopo(calc);
            desempilhar(&calc);
            switch (argv[argIndex][0]) {
                case '+': empilhar(&calc, a + b); break;
                case '-': empilhar(&calc, a - b); break;
                case '*': empilhar(&calc, a * b); break;
                case '/': 
                    if(b != 0.0) {
                        empilhar(&calc, a / b); 
                    } else {
                        printf("Erro: Divisão por zero.\n");
                        return 1;
                    }
                    break;
            }
        }
    }

    printf("Resultado: %f\n", verTopo(calc));
    return 0;
}
