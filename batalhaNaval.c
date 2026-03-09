#include <stdio.h>

// Declaração das variaveis do tabuleiro globalmente
int tabuleiro[10][10]; // Criando o tabuleiro 10x10 utilizando uma matriz globalmente

// As referencia das linhas, e colunas, usando vetores globalmente
char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // As posicoes de cada coluna representado por letras
int linha[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // As posicoes de cada linha representada por numeros

// Declaração de variaveis para os navios
int tamanhoNavio = 3; // Todos os navios globalmente possui um valor fixo de "3"

// Variaveis de posicao do primeiro navio
int linhaPosicaoNavio_1; // A linha onde sera colocado o primeiro navio
int colunaPosicaoNavio_1; // As colunas onde sera colocado o primeiro navio

// Variaveis de posicao do segundo navio
int linhaPosicaoNavio_2; // A linha onde sera colocado o segundo navio
int colunaPosicaoNavio_2; // As colunas onde sera colocado o segundo navio

void criarTabuleiro () {
    // Usando um loop for aninhado para colocar automáticamente os "0" dentro da matriz
    for (int i = 0; i <= 9; i++) {
        // "-1" para assim também referenciar o "0" pois vai do "0" ao "9", sendo as "10" casas no total
        for (int j = 0; j <= 9; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void inserirNavios () {
    // Inserir o primeiro navio na horizontal
    linhaPosicaoNavio_1 = 2;
    colunaPosicaoNavio_1 = 2;

    // Primeiro uma verificação para não permitir a sobreposições de navios
    if (linhaPosicaoNavio_2 == linhaPosicaoNavio_1 || colunaPosicaoNavio_2 == colunaPosicaoNavio_1) {
        printf("SOBREPOSIÇÃO ENCONTRADA. NAVIO 1 NÃO COLOCADO.\n");
    } else {
        // Depois se não houver uma sobreposião, percorremos todo o tabuleiro
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                /*
                    Nesta percorrida, quando a posição que esta passando bater com a 
                    posicao da linha e da coluna que o usuario deseja 
                    colocar vai para o loop que insere este navio no tabuleiro
                */ 
                if (i == linhaPosicaoNavio_1 && j == colunaPosicaoNavio_1) {
                    // Preenche todos os espaços das posicoes com o tamanho do navio que é "3"
                    for (int k = j; k < (j + tamanhoNavio); k++) {
                        tabuleiro[i][k] = 3; // O navio é representado pelo número "3"
                    }
                    break;
                } else {
                    continue;
                }
            }
        }
    }

    // Inserir o segundo navio na vertical
    linhaPosicaoNavio_2 = 6;
    colunaPosicaoNavio_2 = 7;
    
    // Aplicando a mesma lógica do inserir o navio na horizontal aqui
    if (linhaPosicaoNavio_1 == linhaPosicaoNavio_2 || colunaPosicaoNavio_1 == colunaPosicaoNavio_2) {
        printf("SOBREPOSIÇÃO ENCONTRADA. NAVIO 2 NÃO COLOCADO.\n");
    } else {
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j <= 9; j++) {
                if (i == linhaPosicaoNavio_2 && j == colunaPosicaoNavio_2) {
                    // Mudando apenas para aumentar a quantidade de linha, nao coluna
                    for (int k = i; k < (i + tamanhoNavio); k++) {
                        tabuleiro[k][j] = 3;
                    }
                    break;
                } else {
                    continue;
                }
            }
        }
    }
}

void mostrarTabuleiro () {
    // "-1" para começar referenciando pelo "0" o índice
    // Mostrando as posições de cada coluna
    printf("\n   ");
    for (int i = 0; i <= 9; i++) {
        printf("  %c", coluna[i]);
    }

    printf("\n\n"); // Quebra de linha

    // Mostrar as posições da linha, e logo em seguida, o tabuleiro, seguindo a mesma lógica da criação do tabuleiro
    for (int i = 0; i <= 9; i++) {
        // Mostrando as posições da linha
        printf("%-4d", linha[i]);
        for (int j = 0; j <= 9; j++) {
            // Mostrando o tabuleiro
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("### BEM-VINDO AO BATALHA NAVAL VIRTUAL ###\n\n");

    // Chamando as funções
    criarTabuleiro();
    inserirNavios();
    mostrarTabuleiro();

    return 0;
}
