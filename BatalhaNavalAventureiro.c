#include <stdio.h>


// Desafio Batalha Naval - MateCheck - Aventureiro

#define TAM 10    // Tamanho do tabuleiro
#define NAVIO 3   // Representação de partes de navios no tabuleiro

int main(){

    // Declaração e inicialização do tabuleiro 10x10
    int tabuleiro[TAM][TAM] = {0};  // Inicializa a matriz com 0 (sem navio)

    // Colocando os navios na diagonal
    // Navio 1 - Diagonal principal
    tabuleiro[2][2] = NAVIO;
    tabuleiro[3][3] = NAVIO;
    tabuleiro[4][4] = NAVIO;
    tabuleiro[5][5] = NAVIO;

    // Navio 2 - Diagonal secundária
    tabuleiro[6][4] = NAVIO;
    tabuleiro[7][5] = NAVIO;
    tabuleiro[8][6] = NAVIO;
    tabuleiro[9][7] = NAVIO;

    // Navio 3 - Em uma posição horizontal
    tabuleiro[0][0] = NAVIO;
    tabuleiro[0][1] = NAVIO;
    tabuleiro[0][2] = NAVIO;
    
    // Navio 4 - Em uma posição vertical
    tabuleiro[3][7] = NAVIO;
    tabuleiro[4][7] = NAVIO;
    tabuleiro[5][7] = NAVIO;

    // Exibindo o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;


}