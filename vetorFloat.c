#include <stdio.h>
#include <math.h>

int pontoMaisProximo(float* x, float* y, int n, float px, float py) {
    int indice = 0;
    float minDist = sqrt(pow((x[0] - px), 2) + pow((y[0] - py), 2));

    for (int i = 1; i < n; i++) {
        float dist = sqrt(pow((x[i] - px), 2) + pow((y[i] - py), 2));
        if (dist < minDist) {
            minDist = dist;
            indice = i;
        }
    }

    return indice;
}

int main() {
    float x[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float y[4] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float px = 2.5, py = 2.5;

    int indice = pontoMaisProximo(x, y, 5, px, py);

    printf("O ponto mais próximo de (%.2f, %.2f) está no índice %d\n", px, py, indice);
    return 0;
}
