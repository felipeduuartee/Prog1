#include <stdio.h>

int main() {
	int segundos, horas, minutos;
	printf("Digite um numero em segundos: ");
	scanf("%d", &segundos);

	horas = segundos / 3600;
	segundos = segundos % 3600;
	minutos = segundos / 60;
	segundos = segundos % 60;

	printf("tempo no formato hh:mm:ss = %02d:%02d:%02d\n", horas, minutos, segundos);
}