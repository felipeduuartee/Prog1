#include <stdio.h>

void preencher(int *arr, int tamanho, int valor) {
    int *ptr_end = arr + tamanho;  // ponteiro para o final do array
    for (int *ptr = arr; ptr < ptr_end; ptr++) {
        *ptr = valor;
    }
}

int main() {
    int array[5];
    int valor;

    printf("Digite um valor para preencher o array: ");
    scanf("%d", &valor);

    preencher(array, 5, valor);

    printf("Array preenchido:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
