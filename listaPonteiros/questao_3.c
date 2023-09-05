#include <stdio.h>

int main() {
    int a, b;

    int *pont1 = &a;
    int *pont2 = &b;

    printf("Digite o valor para a: ");
    scanf("%d", pont1);

    printf("Digite o valor para b: ");
    scanf("%d", pont2);

    if (a > b) {
        printf("O maior valor é: %d\n", a);
    } else if (b > a) {
        printf("O maior valor é: %d\n", b);
    } else {
        printf("Ambos os valores são iguais: %d\n", a);
    }

    return 0;
}
