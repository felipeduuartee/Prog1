#include <stdio.h>

int substr(char *str1, char *str2) {
    char *ptr1, *ptr2, *aux;

    for (ptr1 = str1; *ptr1; ptr1++) {
        if (*ptr1 == *str2) {  // Se o primeiro caractere de str2 é encontrado em str1
            aux = ptr1;
            for (ptr2 = str2; *ptr2 && *aux == *ptr2; ptr2++, aux++);
            
            if (!*ptr2) {  // Se chegamos ao final de str2
                return 1;  // str2 ocorre em str1
            }
        }
    }
    return 0;  // str2 não ocorre em str1
}

int main() {
    char string1[100], string2[100];
    printf("Digite a primeira string: ");
    gets(string1);  // simplifica a entrada para este exemplo
    printf("Digite a segunda string: ");
    gets(string2);

    if (substr(string1, string2)) {
        printf("A segunda string ocorre dentro da primeira.\n");
    } else {
        printf("A segunda string NAO ocorre dentro da primeira.\n");
    }

    return 0;
}
