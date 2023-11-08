#include <stdio.h>

void ler_notas(float *nota1, float *nota2) {
    do {
        printf("Digite a primeira nota (0 a 10): ");
        scanf("%f", nota1);
    } while (*nota1 < 0 || *nota1 > 10);  // Verificar se a nota é válida

    do {
        printf("Digite a segunda nota (0 a 10): ");
        scanf("%f", nota2);
    } while (*nota2 < 0 || *nota2 > 10);  // Verificar se a nota é válida
}

void calcular_medias(float nota1, float nota2, float *media_simples, float *media_ponderada) {
    *media_simples = (nota1 + nota2) / 2;
    *media_ponderada = (nota1 + nota2 * 2) / 3;
}

int main() {
    float nota1, nota2, media_s, media_p;

    ler_notas(&nota1, &nota2);
    calcular_medias(nota1, nota2, &media_s, &media_p);

    printf("Média simples: %f\n", media_s);
    printf("Média ponderada: %f\n", media_p);

    return 0;
}
