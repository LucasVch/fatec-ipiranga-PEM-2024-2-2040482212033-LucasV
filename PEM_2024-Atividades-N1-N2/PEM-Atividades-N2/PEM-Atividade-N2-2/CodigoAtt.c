/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 11/10/2024                                             * 
* Autor: Giulia Diaz; Lucas Vinicius Silva*
*--------------------------------------------------------*/


#include <stdio.h>
#include <time.h>
 
void exibirArray(int array[], int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", array[i]);
        if (i < tamanho - 1) printf(", ");
    }
    printf("]\n");
}
 
void ordenacaoInsercao(int array[], int tamanho) {
    int trocas = 0, ciclos = 0;
    clock_t start, end;
    double tempo;
 
    start = clock();
    for (int i = 1; i < tamanho; i++) {
        int elemento = array[i];
        int j = i - 1;
        ciclos++;
        while (j >= 0 && array[j] > elemento) {
            array[j + 1] = array[j];
            trocas++;
            j--;
            ciclos++;
        }
        array[j + 1] = elemento;
    }
    end = clock();
    tempo = ((double)(end - start)) / CLOCKS_PER_SEC;
 
    printf("Ordenação por Inserção - Resultados:\n");
    exibirArray(array, tamanho);
    printf("Trocas: %d\n", trocas);
    printf("Ciclos: %d\n", ciclos);
    printf("Tempo de execução: %f segundos\n", tempo);
}
 
int main() {
    int arr[] = {5, 3, 8, 4, 2, 115, 113, 118, 114, 112, 125, 123, 128, 124, 122,
                 35, 33, 38, 34, 32, 45, 43, 48, 44, 42, 55, 53, 58, 54, 52,
                 65, 63, 68, 64, 62, 75, 73, 78, 74, 72, 85, 83, 88, 84, 82,
                 95, 93, 98, 94, 92, 15, 13, 18, 14, 12, 25, 23, 28, 24, 22};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
 
    printf("Array original: ");
    exibirArray(arr, tamanho);
 
    ordenacaoInsercao(arr, tamanho);
 
    return 0;
}