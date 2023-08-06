#include <stdio.h>

int fibonacci(int n) {
	if (n <= 0) {
			return 0;
	}
	else if (n == 1 || n == 2) {
			return 1;
	}
	else {
			int fib1 = 1, fib2 = 1, fib = 0;
			for (int i = 3; i <= n; i++) {
					fib = fib1 + fib2;
					fib1 = fib2;
					fib2 = fib;
			}
			return fib;
	}
}
	
int main() {
	int n;
	printf("Digite um numero: ");
	scanf("%d", &n);
	printf(" O %d numero da seuquencia de fibonacci é: %d\n", n, fibonacci(n));
	return 0;
}