#include <stdio.h>

// Constantes do tabuleiro
#define linhaTabuleiro 10
#define colunaTabuleiro 10

// Constante do navio
#define navio 3

// Constantes das habilidades
#define linhaHabilidade 3
#define colunaHabilidade 5

// Declaração das variaveis do tabuleiro globalmente
int tabuleiro[linhaTabuleiro][colunaTabuleiro]; // Criando o tabuleiro 10x10 utilizando uma matriz globalmente

// Declaração da matriz das habilidades
int habilidadeCone[linhaHabilidade][colunaHabilidade]; // Criando uma matriz 3x4, utilizando isso globalmente para o cone
int habilidadeCruz[linhaHabilidade][colunaHabilidade]; // Criando uma matriz 3x4, utilizando isso globalmente para a cruz
int habilidadeOctaedro[linhaHabilidade][colunaHabilidade]; // Criando uma matriz 3x4, utilizando isso globalmente para o octaedro

// As referencia das linhas, e colunas, usando vetores globalmente
char coluna[colunaTabuleiro] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; // As posicoes de cada coluna representado por letras
int linha[linhaTabuleiro] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // As posicoes de cada linha representada por numeros

// Declaração de variaveis para os navios
int tamanhoNavio = 3; // Todos os navios globalmente possui um valor fixo de "3"

// Variavel de verificação de posicao
int respostaVerificacao; // Aqui guardara um valor "1" ou "0", o um, verdadeiro, e o dois, falso; dependendo da resposta da verificacao 

// Variaveis de posicao do primeiro navio (horizontal)
int linhaPosicaoNavioHorizontal; // A linha onde sera colocado o primeiro navio
int colunaPosicaoNavioHorizontal; // As colunas onde sera colocado o primeiro navio

// Variaveis de posicao do segundo navio (vertical)
int linhaPosicaoNavioVertical; // A linha onde sera colocado o segundo navio
int colunaPosicaoNavioVertical; // As colunas onde sera colocado o segundo navio

// Variaveis de posicao do terceiro navio (diagonal principal)
int linhaPosicaoNavioDiagonalPrincipal; // A linha onde sera colocado o terceiro navio
int colunaPosicaoNavioDiagonalPrincipal; // As colunas onde sera colocado o terceiro navio

// Variaveis de posicao do quarto navio (diagonal secundario)
int linhaPosicaoNavioDiagonalSegundario; // A linha onde sera colocado o quarto navio
int colunaPosicaoNavioDiagonalSecundario; // As colunas onde sera colocado o quarto navio

// Variaveis de posicao da habilidade cone
int linhaHabilidadeCone; // A linha onde sera colocado a habilidade cone
int colunaHabilidadeCone; // A coluna onde sera colocado a habilidade cone

// Variaveis de posicao da habilidade cone
int linhaHabilidadeCruz; // A linha onde sera colocado a habilidade cruz
int colunaHabilidadeCruz; // A coluna onde sera colocado a habilidade cruz

// Variaveis de posicao da habilidade cone
int linhaHabilidadeOctaedro; // A linha onde sera colocado a habilidade octaedro
int colunaHabilidadeOctaedro; // A coluna onde sera colocado a habilidade octaedro

void criarTabuleiro () {
    // Usando um loop for aninhado para colocar automáticamente os "0" dentro da matriz
    for (int i = 0; i < linhaTabuleiro; i++) {
        // "-1" para assim também referenciar o "0" pois vai do "0" ao "9", sendo as "10" casas no total
        for (int j = 0; j < colunaTabuleiro; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void inserirNavios () {
    // Inserir o primeiro navio na horizontal
    linhaPosicaoNavioHorizontal = 2;
    colunaPosicaoNavioHorizontal = 2;

    // Fazendo uma verificacao do valores das posicoes
    verificarPosicaoNavio(linhaPosicaoNavioHorizontal, colunaPosicaoNavioHorizontal);

    // Primeiro uma verificação para não permitir a sobreposições de navios
    if (respostaVerificacao == 1) {
        printf("SOBREPOSIÇÃO DE NAVIOS OU POSIÇÃO FORA DA GRADE. OPERAÇÃO CANCELADA. [NAVIO HORIZONTAL]\n");
    } else {
        // Depois se não houver uma sobreposião, percorremos todo o tabuleiro
        for (int i = 0; i <= linhaTabuleiro; i++) {
            for (int j = 0; j <= colunaTabuleiro; j++) {
                /*
                    Nesta percorrida, quando a posição que esta passando bater com a 
                    posicao da linha e da coluna que o usuario deseja 
                    colocar vai para o loop que insere este navio no tabuleiro
                */ 
                if (i == linhaPosicaoNavioHorizontal && j == colunaPosicaoNavioHorizontal) {
                    // Preenche todos os espaços das posicoes com o tamanho do navio que é "3"
                    for (int k = j; k < (j + tamanhoNavio); k++) {
                        tabuleiro[i][k] = navio; // O navio é representado pelo número "3"
                    }
                    break;
                } else {
                    continue;
                }
            }
        }
    }

    // Inserir o segundo navio na vertical
    linhaPosicaoNavioVertical = 2;
    colunaPosicaoNavioVertical = 7;
    
    // Fazendo uma verificacao do valores das posicoes
    verificarPosicaoNavio(linhaPosicaoNavioVertical, colunaPosicaoNavioVertical);

    // Aplicando a mesma lógica do inserir o navio na vertical aqui
    if (respostaVerificacao == 1) {
        printf("SOBREPOSIÇÃO DE NAVIOS OU POSIÇÃO FORA DA GRADE. OPERAÇÃO CANCELADA. [NAVIO VERTICAL]\n");
    } else {
        for (int i = 0; i <= linhaTabuleiro; i++) {
            for (int j = 0; j <= colunaTabuleiro; j++) {
                if (i == linhaPosicaoNavioVertical && j == colunaPosicaoNavioVertical) {
                    // Mudando apenas para aumentar a quantidade de linha, nao coluna
                    for (int k = i; k < (i + tamanhoNavio); k++) {
                        tabuleiro[k][j] = navio;
                    }
                    break;
                } else {
                    continue;
                }
            }
        }
    }

    // Inserir o terceiro navio na diagonal principal (para baixo)
    linhaPosicaoNavioDiagonalPrincipal = 6;
    colunaPosicaoNavioDiagonalPrincipal = 2;

    // Fazendo uma verificacao do valores das posicoes
    verificarPosicaoNavio(linhaPosicaoNavioDiagonalPrincipal, colunaPosicaoNavioDiagonalPrincipal);
    
    if (respostaVerificacao == 1) {
        printf("SOBREPOSIÇÃO DE NAVIOS OU POSIÇÃO FORA DA GRADE. OPERAÇÃO CANCELADA. [NAVIO DIAGONAL PRINCIPAL]\n");
    } else {
        for (int i = 0; i <= linhaTabuleiro; i++) {
            for (int j = 0; j <= colunaTabuleiro; j++) {
                if (i == linhaPosicaoNavioDiagonalPrincipal && j == colunaPosicaoNavioDiagonalPrincipal) {
                    // Definimos uma variavel para a linha, para depois somar e fazer o efeito diagonal
                    int l = i;

                    // Colocamos o primeiro for, com a lógica do navio na horizontal
                    for (int k = j; k < (j + tamanhoNavio); k++) {
                        // A cada loop que é realizado, é somado mais um para a coluna, assim aplicando o efeito de uma diagonal para baixo
                        tabuleiro[l][k] = navio;
                        l++;
                    }
                    break;
                } else {
                    continue;
                }
            }
        }
    }

    // Inserir o quarto navio na diagonal secundaria (para cima)
    linhaPosicaoNavioDiagonalSegundario = 8;
    colunaPosicaoNavioDiagonalSecundario = 6;

    // Fazendo uma verificacao do valores das posicoes
    verificarPosicaoNavio(linhaPosicaoNavioDiagonalSegundario, colunaPosicaoNavioDiagonalSecundario);
    
    if (respostaVerificacao == 1) {
        printf("SOBREPOSIÇÃO DE NAVIOS OU POSIÇÃO FORA DA GRADE. OPERAÇÃO CANCELADA. [NAVIO DIAGONAL SECUNDARIO]\n");
    } else {
        for (int i = 0; i <= linhaTabuleiro; i++) {
            for (int j = 0; j <= colunaTabuleiro; j++) {
                if (i == linhaPosicaoNavioDiagonalSegundario && j == colunaPosicaoNavioDiagonalSecundario) {
                    // Variavel da linha
                    int l = i;
                    for (int k = j; k < (j + tamanhoNavio); k++) {
                        tabuleiro[l][k] = navio;
                        /* 
                            Mesma lógica do navio na diagonal principal (para baixo), mas
                            agora para deixar com o efeito de uma diagonal para cima (ou
                            secundaria), devemos subtrair a linha a cada loop
                        */
                        l--;
                    }
                    break;
                } else {
                    continue;
                }
            }
        }
    }
}

void criarHabilidades () {
    // Primeiro construir a matriz da habilidade de Cone
    for (int i = 0; i < linhaHabilidade; i++) {
        for (int j = 0; j < colunaHabilidade; j++) {
            // Agora com os caculos, o programa compara os valores, para assim colocar a quantidade exata de um's nos lugares certos
            if ((i == 0 && j == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 2)) {
                habilidadeCone[i][j] = 5;
            } else {
                habilidadeCone[i][j] = 0;
            }
        }
    }

    // Segundo contruimos a habilidade de Cruz
    for (int i = 0; i < linhaHabilidade; i++) {
        for (int j = 0; j < colunaHabilidade; j++) {
            if ((i == 0 && j == 2) || (i == 1) || (i == 2 && j == 2)) {
                habilidadeCruz[i][j] = 5;
            } else {
                habilidadeCruz[i][j] = 0;
            }
        }
    }

    // Terceiro construimos a habilidade de Octaedro
    for (int i = 0; i < linhaHabilidade; i++) {
        for (int j = 0; j < colunaHabilidade; j++) {
            if ((i == 0 && j == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 2 && j == 2)) {
                habilidadeOctaedro[i][j] = 5;
            } else {
                habilidadeOctaedro[i][j] = 0;
            }
        }
    }
}

void inserirHabilidades () {
    // Encontrando a metade das linhas e colunas para no final achar o meio
    int metadeLinhas = (linhaHabilidade - 1) / 2;
    int metadeColunas = (colunaHabilidade - 1) / 2;

    // Inserir a habilidade cone
    linhaHabilidadeCone = 5;
    colunaHabilidadeCone = 5;

    for (int i = 0; i < linhaHabilidade; i++) {
        for (int j = 0; j < colunaHabilidade; j++) {
            // Calculando os destinos da linha e coluna, para assim achar o meio
            int destinoLinha = linhaHabilidadeCone - metadeLinhas + i;
            int destinoColuna = colunaHabilidadeCone - metadeColunas + j;

            // Imprimindo os valores na matriz central "tabuleiro", descartando os "0"
            if (destinoLinha >= 0 && destinoLinha < linhaTabuleiro && destinoColuna >= 0 && destinoColuna < colunaTabuleiro) {
                if (habilidadeCone[i][j] != 0) {
                    tabuleiro[destinoLinha][destinoColuna] = habilidadeCone[i][j];
                }
            }
        }
    }

    // Inserir a habilidade cruz
    linhaHabilidadeCruz = 2;
    colunaHabilidadeCruz = 1;

    for (int i = 0; i < linhaHabilidade; i++) {
        for (int j = 0; j < colunaHabilidade; j++) {
            // Calculando os destinos da linha e coluna, para assim achar o meio
            int destinoLinha = linhaHabilidadeCruz - metadeLinhas + i;
            int destinoColuna = colunaHabilidadeCruz - metadeColunas + j;

            // Imprimindo os valores na matriz central "tabuleiro", descartando os "0"
            if (destinoLinha >= 0 && destinoLinha < linhaTabuleiro && destinoColuna >= 0 && destinoColuna < colunaTabuleiro) {
                if (habilidadeCruz[i][j] != 0) {
                    tabuleiro[destinoLinha][destinoColuna] = habilidadeCruz[i][j];
                }
            }
        }
    }

    // Inserir a habilidade octaedro
    linhaHabilidadeOctaedro = 2;
    colunaHabilidadeOctaedro = 7;

    for (int i = 0; i < linhaHabilidade; i++) {
        for (int j = 0; j < colunaHabilidade; j++) {
            // Calculando os destinos da linha e coluna, para assim achar o meio
            int destinoLinha = linhaHabilidadeOctaedro - metadeLinhas + i;
            int destinoColuna = colunaHabilidadeOctaedro - metadeColunas + j;

            // Imprimindo os valores na matriz central "tabuleiro", descartando os "0"
            if (destinoLinha >= 0 && destinoLinha < linhaTabuleiro && destinoColuna >= 0 && destinoColuna < colunaTabuleiro) {
                if (habilidadeOctaedro[i][j] != 0) {
                    tabuleiro[destinoLinha][destinoColuna] = habilidadeOctaedro[i][j];
                }
            }
        }
    }
}

int verificarPosicaoNavio (int linha, int coluna) {
    // Primeira verificacao e de sobreposicao de navios, se houver um navio no local que é desejado colocar outro navio, é impedido
    if (tabuleiro[linha][coluna] == 3) {
        respostaVerificacao = 1;
    } else if (linha >= linhaTabuleiro || coluna >= colunaTabuleiro) { // Se não houver, mas sair da grade do tabuleiro 10x10, tambem é impedido 
        respostaVerificacao = 1;
    } else {
        // Se apos a verificação nao tiver nenhum comflito, é dado o "alvara" para posicionar o navio na posicao desejada
        respostaVerificacao = 0;
    }
}

void mostrarTabuleiro () {
    // "-1" para começar referenciando pelo "0" o índice
    // Mostrando as posições de cada coluna
    printf("\n   ");
    for (int i = 0; i < colunaTabuleiro; i++) {
        printf("  %c", coluna[i]);
    }

    printf("\n\n"); // Quebra de linha

    // Mostrar as posições da linha, e logo em seguida, o tabuleiro, seguindo a mesma lógica da criação do tabuleiro
    for (int i = 0; i < linhaTabuleiro; i++) {
        // Mostrando as posições da linha
        printf("%-4d", linha[i]);
        for (int j = 0; j < colunaTabuleiro; j++) {
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
    criarHabilidades();
    inserirHabilidades();
    mostrarTabuleiro();

    return 0;
}