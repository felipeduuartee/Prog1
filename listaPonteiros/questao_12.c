#include <stdio.h>

void ordena_e_verifica (int *a, int *b, int *c) {

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