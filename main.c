//Intercalar vetores

#include <stdio.h>

void intercalar(int vetor1[], int vetor2[], int vetorIntercalado[], int n) {
    for (int i = 0; i < n; i++) {
        vetorIntercalado[2*i] = vetor1[i];
        vetorIntercalado[2*i + 1] = vetor2[i];
    }
}

int main() {
    int vetor1[4] = {10, 1, 45, 7};
    int vetor2[4] = {12, 98, 90, 11};
    int vetorIntercalado[8];

    intercalar(vetor1, vetor2, vetorIntercalado, 4);

    printf("Vetor intercalado: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", vetorIntercalado[i]);
    }
    printf("\n");
    return 0;
}
