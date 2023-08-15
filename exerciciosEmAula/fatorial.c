#include <stdio.h>

long long fatorial(int n) {
    if (n < 0) {
        return 0;
    }
    else if (n == 0) {
        return 1;
    }
    else {
        long long fat = 1;
        for (int i = 1; i <= n; i++) {
            fat *= i;
        }
        return fat;
    }
}

int main() {
    int n;
    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);
    printf("O fatorial de %d é: %lld\n", n, fatorial(n));
    return 0;
}
