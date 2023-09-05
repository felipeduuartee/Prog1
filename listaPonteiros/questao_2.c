#include <stdio.h>

int main() {
    int var1 = 10, var2 = 20;

    int *ptr1 = &var1;
    int *ptr2 = &var2;

    if (ptr1 > ptr2) {
        printf("Endereco apontado por ptr1 é maior: %p\n", ptr1);
    } else if (ptr2 > ptr1) {
        printf("Endereco apontado por ptr2 é maior: %p\n", ptr2);
    } else {
        printf("Os endereços apontados são iguais.\n");
    }

    return 0;
}
