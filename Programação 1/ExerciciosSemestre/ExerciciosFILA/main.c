#include <stdio.h>
#include "fila.h"

int main() {
    struct Fila f;
    inicializaFila(&f);

    enfileira(&f, 1);
    enfileira(&f, 2);
    enfileira(&f, 3);
    enfileira(&f, 4);
    enfileira(&f, 5);

    inverteFila(&f);

    while (!estaVaziaFila(f)) {
        printf("%d ", desenfileira(&f));
    }

    return 0;
}
