#include <stdio.h>

int main() {
    int n, reverso = 0, temp, original;

    // Pede ao usuário para inserir um número
    printf("Insira um número: ");
    scanf("%d", &n);

    original = n;

    // Inverte o número
    while (n != 0) {
        temp = n % 10;
        reverso = reverso * 10 + temp;
        n = n / 10;
    }

    // Compara o número original com o seu reverso
    if (original == reverso) {
        printf("%d é um número palíndromo.\n", original);
    } else {
        printf("%d não é um número palíndromo.\n", original);
    }

    return 0;
}
