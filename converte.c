#include <stdio.h>

int main() {
    int TotalSeconds;
    int hours, minutes, seconds;

    // Pede ao usuário que insira o número de segundos
    printf("Insira o número total de segundos: ");
    scanf("%d", &TotalSeconds);

    // Converte os segundos em horas, minutos e segundos
    hours = TotalSeconds / 3600;
    TotalSeconds = TotalSeconds % 3600;
    minutes = TotalSeconds / 60;
    seconds = TotalSeconds % 60;

    // Imprime o tempo no formato hh:mm:ss
    printf("Tempo no formato hh:mm:ss = %02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
