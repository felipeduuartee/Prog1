#include <stdio.h>

int main() {
	int n, reverso = 0, temp, original;

	printf("Digite um numero inteiro: ");
	scanf("%d", &n);

	original = n;

	while (n != 0) {
		temp = n % 10;
		reverso = reverso * 10 + temp;
		n /= 10;
	}
} 