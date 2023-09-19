#include <stdio.h>

#include <stdbool.h>



//the code was made using IA(ChatGPT) just 'cause DIO asked me to do. 





// Tamanho do tabuleiro

#define TAMANHO_TABULEIRO 3



// Símbolos para as peças dos jogadores

#define JOGADOR_X 'X'

#define JOGADOR_O 'O'

#define VAZIO ' '



// Função para inicializar o tabuleiro

void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {

  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

      tabuleiro[i][j] = VAZIO;

    }

  }

}



// Função para imprimir o tabuleiro

void imprimirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {

  printf("\n");

  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

      printf("%c", tabuleiro[i][j]);

      if (j < TAMANHO_TABULEIRO - 1) {

        printf(" | ");

      }

    }

    printf("\n");

    if (i < TAMANHO_TABULEIRO - 1) {

      for (int k = 0; k < TAMANHO_TABULEIRO * 4 - 1; k++) {

        printf("-");

      }

      printf("\n");

    }

  }

  printf("\n");

}



// Função para verificar se o tabuleiro está cheio (empate)

bool tabuleiroCheio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {

  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

      if (tabuleiro[i][j] == VAZIO) {

        return false;

      }

    }

  }

  return true;

}



// Função para verificar se um jogador venceu

bool verificarVitoria(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], char jogador) {

  // Verificar linhas e colunas

  for (int i = 0; i < TAMANHO_TABULEIRO; i++) {

    if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {

      return true; // Linha

    }

    if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {

      return true; // Coluna

    }

  }

  // Verificar diagonais

  if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {

    return true; // Diagonal principal

  }

  if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {

    return true; // Diagonal secundária

  }

  return false;

}



int main() {

  char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

  char jogadorAtual = JOGADOR_X;

  int linha, coluna;



  inicializarTabuleiro(tabuleiro);



  printf("Bem-vindo ao Jogo da Velha!\n");



  while (true) {

    imprimirTabuleiro(tabuleiro);



    printf("É a vez do jogador %c. Informe a linha (0 a 2) e a coluna (0 a 2): ", jogadorAtual);

    scanf("%d %d", &linha, &coluna);



    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO || tabuleiro[linha][coluna] != VAZIO) {

      printf("Movimento inválido. Tente novamente.\n");

      continue;

    }



    tabuleiro[linha][coluna] = jogadorAtual;



    if (verificarVitoria(tabuleiro, jogadorAtual)) {

      imprimirTabuleiro(tabuleiro);

      printf("Parabéns! O jogador %c venceu!\n", jogadorAtual);

      break;

    }



    if (tabuleiroCheio(tabuleiro)) {

      imprimirTabuleiro(tabuleiro);

      printf("Empate! O jogo terminou em empate.\n");

      break;

    }



    // Alternar o jogador

    jogadorAtual = (jogadorAtual == JOGADOR_X) ? JOGADOR_O : JOGADOR_X;

  }



  return 0;

}
