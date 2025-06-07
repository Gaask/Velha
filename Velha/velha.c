#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3
#define X 3
#define O 6

int tabuleiro[LINHAS][COLUNAS] = {0};
int vencedor = 0;

void imprimirTabuleiro() {
    printf("\nTabuleiro do Jogo da Velha:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == X) {
                printf("| X ");
            } else if (tabuleiro[i][j] == O) {
                printf("| O ");
            } else {
                printf("|   ");
            }
        }
        printf("|\n");
    }
}

void posicionarJogador(int jogador) {
    int linha, coluna, verificacao;
    do {
        printf("\nJogador %c, selecione a linha (1-3): ", jogador == X ? 'X' : 'O');
        scanf("%d", &linha);
        printf("Jogador %c, selecione a coluna (1-3): ", jogador == X ? 'X' : 'O');
        scanf("%d", &coluna);

        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha - 1][coluna - 1] != 0) {
            printf("\nPosição inválida! Escolha novamente.\n");
            verificacao = 0;
        } else {
            tabuleiro[linha - 1][coluna - 1] = jogador;
            verificacao = 1;
        }
    } while (verificacao == 0);
}

int verificarVencedor() {
    // Verificar win em linha
    for (int i = 0; i < LINHAS; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != 0)
            return tabuleiro[i][0];
    }
    // Verificar win em coluna
    for (int i = 0; i < COLUNAS; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != 0)
            return tabuleiro[0][i];
    }
    // Verificar win em diagonal
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != 0)
        return tabuleiro[0][0];
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != 0)
        return tabuleiro[0][2];

    // Verificar empate
    for (int i = 0; i < LINHAS; i++)
        for (int j = 0; j < COLUNAS; j++)
            if (tabuleiro[i][j] == 0) // Se houver um espaço vazio, ainda há jogadas possíveis
                return 0;

    return -1; // Retorna -1 se for um empate
}

int main() {
    while (vencedor == 0) {
        imprimirTabuleiro();
        posicionarJogador(X);
        vencedor = verificarVencedor();
        if (vencedor != 0) break;

        imprimirTabuleiro();
        posicionarJogador(O);
        vencedor = verificarVencedor();
    }

    imprimirTabuleiro();
    if (vencedor == X) {
        printf("\nO vencedor foi X!\n");
    } else if (vencedor == O) {
        printf("\nO vencedor foi O!\n");
    } else {
        printf("\nO jogo terminou em empate!\n");
    }

    return 0;
}
