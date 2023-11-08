#include <stdio.h>

int soma_arrays(float *arr1, float *arr2, float *result, int size1, int size2) {
    if (size1 != size2) {
        return 0; // Tamanhos diferentes, retornando 0
    }

    float *end = arr1 + size1; // Ponto final para a aritmética de ponteiros

    while (arr1 < end) {
        *result = *arr1 + *arr2;
        arr1++;
        arr2++;
        result++;
    }

    return 1;
}

int main() {
    float array1[] = {1.2, 2.4, 3.6};
    float array2[] = {4.8, 5.1, 6.3};
    float result[3];
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    if (soma_arrays(array1, array2, result, size1, size2)) {
        printf("Array resultante:\n");
        for (int i = 0; i < size1; i++) {
            printf("%f ", result[i]);
        }
    } else {
        printf("Os arrays têm tamanhos diferentes e não podem ser somados.\n");
    }

    return 0;
}
