#include <stdio.h>

void soma(int *a, int *b) {

	*a += *b;
}

int main() {

	int a, b;

	scanf("%d",&a);
	scanf("%d",&b);

	soma(&a, &b);

	printf("a soma dos dois inteiros é %d\n", a);

	return 0;

}
