#include "fila.h"
#include <stdio.h>

int main() {
    struct Fila f;
    inicializaFila(&f);

    enfileira(&f, 1);
    enfileira(&f, 2);
    enfileira(&f, 3);
    
    printf("%d ", desenfileira(&f));  // Deve imprimir 1
    printf("%d ", desenfileira(&f));  // Deve imprimir 2

    enfileira(&f, 4);
    enfileira(&f, 5);

    printf("%d ", desenfileira(&f));  // Deve imprimir 3
    printf("%d ", desenfileira(&f));  // Deve imprimir 4
    printf("%d ", desenfileira(&f));  // Deve imprimir 5

    return 0;
}
