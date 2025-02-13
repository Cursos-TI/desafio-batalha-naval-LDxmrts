#include <stdio.h>

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

#define TAM 10    // Tamanho do tabuleiro
#define NAVIO 3   // Representação de partes de navios no tabuleiro

// Função para exibir uma matriz
void exibir_matriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Função para definir a habilidade tipo "cone"
void habilidade_cone(int matriz[TAM][TAM], int linha, int coluna) {
    // Limpa a matriz antes de aplicar a habilidade
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = 0;
        }
    }

    // Preenche a área do cone com 1, mas agora formando um triângulo
    for (int i = 0; i <= 2; i++) {  // Apenas 3 linhas para o cone (base de 5)
        for (int j = -i; j <= i; j++) {
            int linha_atual = linha + i;  // Linha aumenta conforme o cone vai descendo
            int coluna_atual = coluna + j;  // A coluna vai expandindo para a direita e esquerda
            if (linha_atual >= 0 && linha_atual < TAM && coluna_atual >= 0 && coluna_atual < TAM) {
                matriz[linha_atual][coluna_atual] = 1;
            }
        }
    }
}


// Função para definir a habilidade tipo "cruz"
void habilidade_cruz(int matriz[TAM][TAM], int linha, int coluna) {
    // Limpa a matriz antes de aplicar a habilidade
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = 0;
        }
    }

    // Preenche a área da cruz com 1
    for (int i = 0; i < TAM; i++) {
        matriz[linha][i] = 1; // Linha da cruz
        matriz[i][coluna] = 1; // Coluna da cruz
    }
}

// Função para definir a habilidade tipo "octaedro"
void habilidade_octaedro(int matriz[TAM][TAM], int linha, int coluna) {
    // Limpa a matriz antes de aplicar a habilidade
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = 0;
        }
    }

    // Preenche a área do octaedro com 1
    for (int i = linha - 2; i <= linha + 2; i++) {
        for (int j = coluna - 2; j <= coluna + 2; j++) {
            if (i >= 0 && i < TAM && j >= 0 && j < TAM) {
                if (abs(i - linha) + abs(j - coluna) <= 2) {
                    matriz[i][j] = 1;
                }
            }
        }
    }
}

int main() {

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
    exibir_matriz(tabuleiro);

    // Definindo as áreas de habilidades
    int habilidade[TAM][TAM];

    // Definir a habilidade tipo "cone"
    printf("\nHabilidade tipo 'Cone':\n");
    habilidade_cone(habilidade, 5, 5); // Exemplo de habilidade no centro (5, 5)
    exibir_matriz(habilidade);

    // Definir a habilidade tipo "cruz"
    printf("\nHabilidade tipo 'Cruz':\n");
    habilidade_cruz(habilidade, 5, 5); // Exemplo de habilidade no centro (5, 5)
    exibir_matriz(habilidade);

    // Definir a habilidade tipo "octaedro"
    printf("\nHabilidade tipo 'Octaedro':\n");
    habilidade_octaedro(habilidade, 5, 5); // Exemplo de habilidade no centro (5, 5)
    exibir_matriz(habilidade);

    return 0;
}
