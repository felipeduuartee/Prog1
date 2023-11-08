#include <stdio.h>
#include <math.h>

int main() {
    int num, square, temp, lastDigits, digits = 0;

    // Pede ao usuário para inserir um número
    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    // Calcula o quadrado do número
    square = num * num;

    // Conta a quantidade de dígitos do número original
    temp = num;
    while (temp != 0) {
        digits++;
        temp = temp / 10;
    }

    // Pega os últimos dígitos do quadrado
    lastDigits = square % (int)pow(10, digits);

    // Verifica se os últimos dígitos do quadrado são iguais ao número original
    if (lastDigits == num) {
        printf("%d tem a propriedade:\n%d*%d=%d, termina com %d\n", num, num, num, square, num);
    } else {
        printf("%d nao tem a propriedade:\n%d*%d=%d, termina com %d\n", num, num, num, square, lastDigits);
    }

    return 0;
}
