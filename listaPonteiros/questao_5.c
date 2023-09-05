#include <stdio.h>

// Função que reordena os valores das variáveis usando ponteiros
void maior(int *a, int *b) {
    if (*a < *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    // Se *a já for maior ou igual a *b, não é necessário fazer nada.
}

int main() {
    int valor1, valor2;

    printf("Digite o primeiro valor: ");
    scanf("%d", &valor1);
    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);

    maior(&valor1, &valor2);

    printf("\nMaior valor: %d\nMenor valor: %d\n", valor1, valor2);

    return 0;
}
