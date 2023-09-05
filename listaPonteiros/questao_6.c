#include <stdio.h>

void dobro(int *n) {

	*n *= 2;

}

int main () {

	int a,b;

	scanf("%d", a);
	scanf("%d", b);

	dobro(&a);
	dobro(&b);

	printf("a: %d, b: %d\n", a, b);

	return 0;
}
