#include <stdio.h>

void troca(int *a, int *b) {

	int temp;

	temp = *a;
	*a = *b;
	*b = temp;

}

int main() {

	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);

	printf("valores antes da troca: A = %d, B = %d\n", a, b);

	troca(&a, &b);

	printf("valores apos a troca: A = %d, B = %d\n", a, b);

	return 0;
}
