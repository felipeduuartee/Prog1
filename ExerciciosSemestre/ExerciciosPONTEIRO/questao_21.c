#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr;

    ptr = array;

    // Somar 1 a cada posição usando o ponteiro
    for (int i = 0; i < 5; i++) {
        *(ptr + i) += 1;  // Usando aritmética de ponteiros para acessar e modificar cada posição
    }

    // Imprimir o array modificado
    printf("Array após adicionar 1 a cada elemento:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
