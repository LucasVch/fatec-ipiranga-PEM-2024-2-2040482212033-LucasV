/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 23/08/2024                                             * 
* Autor: Giulia Diaz; Lucas Vinicius Silva*
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NOTAS 100

int main() {
    int n, i, j;
    float notas[MAX_NOTAS];
    float soma;
    int qtd_provas = 0;
    float nota_final = 0.0;

    while (1) {
        printf("Digite o número de notas (0 para sair): ");
        scanf("%d", &n);

        if (n == 0) break;

        printf("Digite as %d notas: ", n);
        for (i = 0; i < n; i++) {
            scanf("%f", &notas[i]);
        }

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (notas[i] > notas[j]) {
                    float temp = notas[i];
                    notas[i] = notas[j];
                    notas[j] = temp;
                }
            }
        }
        soma = 0.0;
        for (i = 1; i < n - 1; i++) {
            soma += notas[i];
        }

        printf("Nota da prova %d: %.2f\n", qtd_provas + 1, soma);
        nota_final += soma;
        qtd_provas++;
        }
        
    printf("Nota final do candidato: %.2f\n", nota_final);

    return 0;
}