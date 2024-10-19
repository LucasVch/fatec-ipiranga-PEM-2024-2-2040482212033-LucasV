/*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: *************
* Data - 12/09/2024                                             * 
* Autor: Giulia Diaz; Lucas Vinicius Silva*
*--------------------------------------------------------*/

#include <stdio.h>

#define TAMANHO 8


void imprimir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


void jogada_bispo(char tabuleiro[TAMANHO][TAMANHO], int linha_inicial, int coluna_inicial, int linha_final, int coluna_final) {
 
    if (abs(linha_inicial - linha_final) == abs(coluna_inicial - coluna_final)) {
    
        tabuleiro[linha_final][coluna_final] = 'B';
        imprimir_tabuleiro(tabuleiro);
    } else {
        printf("Jogada inválida. A jogada do bispo deve ser diagonal.\n");
    }
}

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = '-';
        }
    }

   
    tabuleiro[5][5] = 'B';
    jogada_bispo(tabuleiro, 5, 5, 2, 2);

    return 0;
}