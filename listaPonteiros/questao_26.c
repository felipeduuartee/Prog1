#include <stdio.h>
#include <math.h>

int raizes(float A, float B, float C, float *X1, float *X2) {
    if (A == 0) {
        return -1;  // A não pode ser zero
    }

    float delta = B * B - 4 * A * C;

    if (delta < 0) {
        return 0;  // Não existem raízes reais
    } else if (delta == 0) {
        *X1 = -B / (2 * A);  // Uma raiz real
        return 1;
    } else {
        *X1 = (-B + sqrt(delta)) / (2 * A);
        *X2 = (-B - sqrt(delta)) / (2 * A);
        return 2;  // Duas raízes reais e distintas
    }
}

int main() {
    float A, B, C, X1, X2;
    int num_raizes;

    printf("Informe os coeficientes A, B e C da equação do segundo grau (Ax^2 + Bx + C = 0):\n");
    scanf("%f %f %f", &A, &B, &C);

    num_raizes = raizes(A, B, C, &X1, &X2);

    switch (num_raizes) {
        case 0:
            printf("A equação não possui raízes reais.\n");
            break;
        case 1:
            printf("A equação possui uma raiz real: %f\n", X1);
            break;
        case 2:
            printf("A equação possui duas raízes reais e distintas: %f e %f\n", X1, X2);
            break;
        default:
            printf("Erro: coeficiente A não pode ser zero.\n");
            break;
    }

    return 0;
}
