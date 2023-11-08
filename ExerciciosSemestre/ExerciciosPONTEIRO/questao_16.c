#include <stdio.h>

int main() {
    int A, *B, **C, ***D;

    // Leitura do valor para A
    printf("Digite um valor para A: ");
    scanf("%d", &A);

    // Associando endereços aos ponteiros
    B = &A;
    C = &B;
    D = &C;

    // Calculando e exibindo o dobro, triplo e quádruplo usando os ponteiros
    printf("Dobro de %d: %d\n", A, *B * 2);
    printf("Triplo de %d: %d\n", A, **C * 3);
    printf("Quádruplo de %d: %d\n", A, ***D * 4);

    return 0;
}
