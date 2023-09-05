#include <stdio.h>

int main() {

    int vetor[5];
    int *p;

    // Leitura dos elementos do array
    printf("Digite 5 inteiros:\n");
    for (p = vetor; p < vetor + 5; p++) {
        scanf("%d", p);
        printf("%p\n", p);
    }

    return 0;
}