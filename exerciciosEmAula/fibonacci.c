#include <stdio.h>

// Define um tamanho máximo para a sequência de Fibonacci
#define MAX 1000

int fib[MAX];

void generateFibonacci() {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    int n;

    generateFibonacci();

    // Pede ao usuário para inserir um número
    printf("Insira um número: ");
    scanf("%d", &n);

    // Verifica se o número é menor que o tamanho máximo definido
    if (n < MAX) {
        // Imprime o n-ésimo número na sequência de Fibonacci
        printf("O %dº número na sequência de Fibonacci é: %d\n", n, fib[n]);
    } else {
        printf("O número é muito grande!\n");
    }

    return 0;
}
