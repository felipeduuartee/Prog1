#include <stdio.h>
#include <math.h>
#define PI 3.14

void calc_esfera(float R, float *area, float *volume) {
    *area = 4 * PI * R * R;             // A = 4 * π * R^2
    *volume = (4.0/3.0) * PI * R * R * R; // V = 4/3 * π * R^3
}

int main() {
    float raio, area, volume;

    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);

    calc_esfera(raio, &area, &volume);

    printf("Area da superficie: %f\n", area);
    printf("Volume: %f\n", volume);

    return 0;
}
