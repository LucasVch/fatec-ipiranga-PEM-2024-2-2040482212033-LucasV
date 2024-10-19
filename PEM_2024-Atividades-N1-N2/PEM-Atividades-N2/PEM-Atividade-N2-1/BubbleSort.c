#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void exibirArray(int array[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", array[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}


void bubbleSort(int array[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                troca(&array[j], &array[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    int numeros[n];

    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
    }

    printf("Array original: ");
    exibirArray(numeros, n);

    bubbleSort(numeros, n);

    printf("Array ordenado: ");
    exibirArray(numeros, n);

    return 0;
}
