#include <stdio.h>

int main() {
    int val, quad;

    // Começa assumindo que a sequência é uma série de valor-quadrado
    int valor_quadrado = 0;

    printf("Digite uma sequencia de numeros (termina com 0): ");
    
    // Leia o primeiro valor
    scanf("%d", &val);
    while(val != 0) {
        // Leia o próximo valor (que deve ser o quadrado do anterior)
        scanf("%d", &quad);
        
        // Se o quadrado não é o quadrado do valor, então a sequência não é uma série de valor-quadrado
        if(quad != val * val) {
            valor_quadrado = 0;
        }

        // Leia o próximo valor
        scanf("%d", &val);
    }
    
    printf("%d\n", valor_quadrado);
    
    return 0;
}
