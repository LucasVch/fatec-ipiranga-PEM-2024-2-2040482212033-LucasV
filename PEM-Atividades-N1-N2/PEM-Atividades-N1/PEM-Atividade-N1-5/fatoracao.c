#ifndef TABULEIRO_H
#define TABULEIRO_H

#define TAMANHO 8

void criar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
void imprimir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]);

#endif // TABULEIRO_H

#include "tabuleiro.h"
#include <stdio.h>

void criar_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = '-';
        }
    }
}

void imprimir_tabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

#ifndef JOGADA_H
#define JOGADA_H

void jogada_bispo(char tabuleiro[TAMANHO][TAMANHO], int linha_inicial, int coluna_inicial, int linha_final, int coluna_final);

#endif // JOGADA_H

#include "jogada.h"
#include "tabuleiro.h"

void jogada_bispo(char tabuleiro[TAMANHO][TAMANHO], int linha_inicial, int coluna_inicial, int linha_final, int coluna_final) {
    if (abs(linha_inicial - linha_final) == abs(coluna_inicial - coluna_final)) {
        tabuleiro[linha_final][coluna_final] = 'B';
        imprimir_tabuleiro(tabuleiro);
    } else {
        printf("Jogada inválida. A jogada do bispo deve ser diagonal.\n");
    }
}

#include "tabuleiro.h"
#include "jogada.h"

int main() {
    char tabuleiro[TAMANHO][TAMANHO];
    criar_tabuleiro(tabuleiro);
    tabuleiro[5][5] = 'B';
    jogada_bispo(tabuleiro, 5, 5, 2, 2);
    return 0;
}