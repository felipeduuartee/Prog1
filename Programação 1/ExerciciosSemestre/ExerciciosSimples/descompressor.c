#include <stdio.h>

void descompressor(long long num, int* vec) {
    vec[0] = num / 1000000;
    vec[1] = (num / 1000) % 1000;
    vec[2] = num % 1000;
}

int main() {
    long long num;
    int vec[3];
    printf("Digite um número inteiro comprimido: ");
    scanf("%lld", &num);
    descompressor(num, vec);
    printf("Os números descomprimidos são: %d %d %d\n", vec[0], vec[1], vec[2]);
    return 0;
}
