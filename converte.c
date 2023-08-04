#include <stdio.h>

int main() {
    int total_seconds;
    int hours, minutes, seconds;

    // Pede ao usuário que insira o número de segundos
    printf("Insira o número total de segundos: ");
    scanf("%d", &total_seconds);

    // Converte os segundos em horas, minutos e segundos
    hours = total_seconds / 3600;
    total_seconds = total_seconds % 3600;
    minutes = total_seconds / 60;
    seconds = total_seconds % 60;

    // Imprime o tempo no formato hh:mm:ss
    printf("Tempo no formato hh:mm:ss = %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
