#include <stdio.h>
#include <math.h>

// Função que verifica se um número é positivo
int ehPositivo(int num) {
    if (num > 0) {
        return 1;
    }
    return 0;
}

// Função que verifica se um número é nulo
int ehNulo(int num) {
    if (num == 0) {
        return 1;
    }
    return 0;
}

// Função que calcula o delta da equacao
double calculaDelta(int a, int b, int c) {
    return (b * b) - (4 * a * c);
}

// Função para calcular as raízes da equacao
void calculaRaizes(int a, int b, int c) {
    if (ehNulo(a)) {
        printf("O coeficiente 'a' deve ser diferente de zero.\n");
        return;
    }

    double delta = calculaDelta(a, b, c);

    if (ehNulo(delta)) {
        double x = -b / (2.0 * a);
        printf("A equação tem uma raiz real: x = %.2f\n", x);
    } else if (ehPositivo(delta)) {
        double x1 = (-b + sqrt(delta)) / (2.0 * a);
        double x2 = (-b - sqrt(delta)) / (2.0 * a);
        printf("A equação tem duas raízes reais: x' = %.2f e x'' = %.2f\n", x1, x2);
    } else {
        double x = -b / (2.0 * a);
        double y = sqrt(-delta) / (2.0 * a);
        printf("A equação tem raízes complexas: x' = %.2f + %.2fi e x'' = %.2f - %.2fi\n", x, y, x, y);
    }
}

int main() {
    int a, b, c;

    printf("Digite os coeficientes a, b e c da equação ax^2 + bx + c = 0:\n");
    scanf("%d %d %d", &a, &b, &c);

    calculaRaizes(a, b, c);

    return 0;
}

