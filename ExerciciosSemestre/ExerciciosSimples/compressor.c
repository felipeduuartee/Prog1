#include <stdio.h>

long long compressor(int a, int b, int c) {
    return a * 1000000LL + b * 1000LL + c;
}

int main() {
    int n1, n2, n3;
    printf("Digite três números inteiros (0-999): ");
    scanf("%d %d %d", &n1, &n2, &n3);
    printf("O número comprimido é: %lld\n", compressor(n1, n2, n3));
    return 0;
}
