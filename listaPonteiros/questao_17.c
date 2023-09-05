#include <stdio.h>

void frac(float num, int* inteiro, float* frac) {
    *inteiro = (int) num;              // Atribui a parte inteira do número
    *frac = num - *inteiro;           // Atribui a parte fracionária do número
}

int main() {
    float numero, parteFracionaria;
    int parteInteira;

    printf("Digite um numero real: ");
    scanf("%f", &numero);

    frac(numero, &parteInteira, &parteFracionaria);

    printf("Parte Inteira: %d\n", parteInteira);
    printf("Parte Fracionaria: %f\n", parteFracionaria);

    return 0;
}
