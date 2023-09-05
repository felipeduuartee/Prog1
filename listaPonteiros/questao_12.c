#include <stdio.h>

int ordena_e_verifica (int *a, int *b, int *c) {

    int temp;

    if (*a > *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }

    if (*a > *c) {
        temp = *a;
        *a = *c;
        *c = temp;
    }

    if (*b > *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }

    return (a == b && b == c) ? 1 : 0;

}

int main() {

    int a, b, c, resultado;

    printf("Digite tres valores inteiros: ");
    scanf("%d\t %d\t %d", &a, &b, &c);

    resultado = ordena_e_verifica(&a, &b, &c);

    printf("Valores ordenado: %d, %d, %d\n", a, b, c);

    if (resultado) {
        printf("Os valores sao iguais\n");
    } else {
        printf("Os valores sao diferentes\n");
    }
}