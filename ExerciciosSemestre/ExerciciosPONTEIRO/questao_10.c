#include <stdio.h>

int main() {
    int vetor[5];
    int *ptr;

    // Leitura dos elementos do array
    printf("Digite 5 inteiros:\n");
    for (ptr = vetor; ptr < vetor + 5; ptr++) {
        scanf("%d", ptr);
    }

    // Imprime o dobro de cada valor lido
    printf("\nO dobro de cada valor inserido:\n");
    for (ptr = vetor; ptr < vetor + 5; ptr++) {
        printf("%d\n", *ptr * 2);
    }

    return 0;
}
