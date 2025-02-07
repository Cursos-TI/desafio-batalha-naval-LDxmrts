#include <stdio.h>

#define TAMANHO_TABULEIRO 5

// Função para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navio horizontal
void posicionarNavioHorizontal(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int colunaInicial, int comprimento) {
    for (int i = 0; i < comprimento; i++) {
        tabuleiro[linha][colunaInicial + i] = 'N'; // N representa o navio
    }
}

// Função para posicionar navio vertical
void posicionarNavioVertical(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coluna, int linhaInicial, int comprimento) {
    for (int i = 0; i < comprimento; i++) {
        tabuleiro[linhaInicial + i][coluna] = 'N'; // N representa o navio
    }
}

int main() {
    // Inicializando o tabuleiro com águas (representadas por 'O')
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 'O'; // 'O' representa água
        }
    }

    // Posicionando os navios manualmente
    // Exemplo: Navio horizontal na linha 1, começando na coluna 0, com comprimento 3
    posicionarNavioHorizontal(tabuleiro, 1, 0, 3);
    
    // Exemplo: Navio vertical na coluna 3, começando na linha 0, com comprimento 4
    posicionarNavioVertical(tabuleiro, 3, 0, 4);

    // Exibindo o tabuleiro após o posicionamento dos navios
    printf("Tabuleiro após o posicionamento dos navios:\n");
    exibirTabuleiro(tabuleiro);

    // Exibindo as coordenadas dos navios
    printf("\nCoordenadas do navio horizontal (linha 1, colunas 0-2):\n");
    for (int i = 0; i < 3; i++) {
        printf("Linha 1, Coluna %d\n", i);
    }

    printf("\nCoordenadas do navio vertical (coluna 3, linhas 0-3):\n");
    for (int i = 0; i < 4; i++) {
        printf("Linha %d, Coluna 3\n", i);
    }

    return 0;
}
