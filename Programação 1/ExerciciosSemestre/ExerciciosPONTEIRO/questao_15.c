#include <stdio.h>

void imprimir(int *arr, int tamanho) {
    int *ptr_end = arr + tamanho;  // ponteiro para o final do array
    for (int *ptr = arr; ptr < ptr_end; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");  // Quebra de linha após imprimir todos os elementos
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};

    printf("Elementos do array: ");
    imprimir(array, 5);
    
    return 0;
}
