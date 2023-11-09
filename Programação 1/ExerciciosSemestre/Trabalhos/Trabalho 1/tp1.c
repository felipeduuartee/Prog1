#include "racionais.h"


int main() {

    // inicia o srand em 0 como pedido no pdf
    srand(0);

    int n, max;
    struct racional r1, r2, resultadoSoma, resultadoSub, resultadoMult, resultadoDiv;

    // quantas vezes o programa vai sortear, operar e imprimir 2 racionais
    do {
        printf("Digite um valor entre 0 e 30 para n: ");
        scanf("%d", &n);
    } while(n < 0 || n > 30);

    // intervalo maximo dos numeradores e denominadores sorteados
    do {
        printf("Digite um valor entre 0 e 100 para max: ");
        scanf("%d", &max);
    } while(max < 0 || max > 100);

    for(int i = 1; i <= n; i++) {
        printf("\n%d: ", i);

        r1 = sorteia_r(max);
        r2 = sorteia_r(max);

        imprime_r(r1);
        printf(" ");
        imprime_r(r2);

        if(!valido_r (r1) || !valido_r(r2)) {
            printf(" NUMERO INVALIDO \n");
            return 1;
        }

        resultadoSoma = soma_r(r1, r2);
        resultadoSub = subtrai_r(r1, r2);
        resultadoMult = multiplica_r(r1, r2);
        resultadoDiv = divide_r(r1, r2);

        imprime_r(resultadoSoma);
        imprime_r(resultadoSub);
        imprime_r(resultadoMult);

        if(!valido_r(resultadoDiv)) {
            printf("NUMERO INVALIDO \n");
            return 1;
        }

        imprime_r(resultadoDiv);

        printf("\n");
    }

    return 0;
}
