#include <stdio.h>
#include <string.h>

#define TAMANHO 64

char tabuleiro[TAMANHO];

void inicializarTabuleiro() {
    int i;
    for (i = 0; i < TAMANHO; i++) {
        tabuleiro[i] = 'X'; // Inicializar todos os espaços como vazios
    }

    // Configurar peças brancas
    tabuleiro[0] = 'BR1'; // Torre 1
    tabuleiro[1] = 'BC1'; // Cavalo 1
    tabuleiro[2] = 'BB1'; // Bispo 1
    tabuleiro[3] = 'BD'; // Rainha
    tabuleiro[4] = 'BK'; // Rei
    tabuleiro[5] = 'BB2'; // Bispo 2
    tabuleiro[6] = 'BC2'; // Cavalo 2
    tabuleiro[7] = 'BR2'; // Torre 2

    for (i = 8; i < 16; i++) {
        tabuleiro[i] = 'BP' + (i - 8); // Peões 1-8
    }

    // Configurar peças pretas
    tabuleiro[56] = 'PR1'; // Torre 1
    tabuleiro[57] = 'PC1'; // Cavalo 1
    tabuleiro[58] = 'PB1'; // Bispo 1
    tabuleiro[59] = 'PD'; // Rainha
    tabuleiro[60] = 'PK'; // Rei
    tabuleiro[61] = 'PB2'; // Bispo 2
    tabuleiro[62] = 'PC2'; // Cavalo 2
    tabuleiro[63] = 'PR2'; // Torre 2

    for (i = 48; i < 56; i++) {
        tabuleiro[i] = 'PP' + (i - 48); // Peões 1-8
    }
}

void imprimirTabuleiro() {
    int i;
    for (i = 0; i < TAMANHO; i++) {
        printf("%c ", tabuleiro[i]);
        if ((i + 1) % 8 == 0) {
            printf("\n");
        }
    }
}

int main() {
    inicializarTabuleiro();
    imprimirTabuleiro();
    return 0;
}