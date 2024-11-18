#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define LINHA 10
#define COLUNA 10

void preencher_com_zero(int matriz[COLUNA][LINHA]) {
    for (int i = 0; i < COLUNA; i++) {
        for (int j = 0; j < LINHA; j++) {
            matriz[i][j] = 0;
        }
    }
}

void randomizar(int numeros_gerados[]) {
    srand(time(NULL));
    for (int i = 1; i <= 20; i++) {
        numeros_gerados[i - 1] = i;
    }
    for (int i = 19; i >= 1; i--) {
        int j = rand() % (i + 1);
        int temp = numeros_gerados[i];
        numeros_gerados[i] = numeros_gerados[j];
        numeros_gerados[j] = temp;
    }
}

void inserir_numeros_gerados_na_matriz(int matriz[COLUNA][LINHA], int numeros_gerados[]) {
    int usado[COLUNA][LINHA];
    preencher_com_zero(usado);

    for (int i = 0; i < 20; i++) {
        int numero = numeros_gerados[i];
        int x, y;

        do {
            x = rand() % COLUNA;
            y = rand() % LINHA;
        } while (usado[x][y] != 0);

        matriz[x][y] = numero;
        usado[x][y] = 1;
    }
}

void apresentar_matriz(int matriz[COLUNA][LINHA]) {
    printf("   ");
    for (int j = 1; j <= LINHA; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    printf("   ");

    for (int i = 0; i <= 29; i++) {
        printf("_");
    }
    printf("\n");

    for (int i = 0; i < COLUNA; i++) {
        printf("%2d|", i + 1);

        for (int j = 0; j < LINHA; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void jogadas(int matriz[COLUNA][LINHA], int *jogador, int *pc) {
    int jogaditas = 0;
    int coordenadas_usadas[COLUNA][LINHA];
    preencher_com_zero(coordenadas_usadas);
    int validar;

    printf("Valor máximo de x=10 (vertical); Valor máximo de y=10 (horizontal)\n");
    printf("\n");

    while (jogaditas != 20) {
        int x, y;
        validar = 1;

        do {
            x = rand() % COLUNA;
            y = rand() % LINHA;
        } while (matriz[x][y] == -1 || coordenadas_usadas[x][y] != 0);

        printf("Jogada do PC: x=%d, y=%d\n", x + 1, y + 1);

        while (validar) {
            if (matriz[x][y] != 0) {
                printf("PC acertou!\n");
                printf("\n");
                *pc += matriz[x][y];
                matriz[x][y] = -1;
                coordenadas_usadas[x][y] = 1;
                jogaditas++;
                validar = 0;
            } else {
                printf("PC errou!\n");
                printf("\n");
                validar = 0;
            }
        }

        validar = 1;

        while (validar) {
            int jogador_x, jogador_y;

            printf("Sua jogada, digite a coordenada (x, y): ");
            scanf("%d %d", &jogador_x, &jogador_y);

            jogador_x--;
            jogador_y--;

            if (jogador_x >= 0 && jogador_x < COLUNA && jogador_y >= 0 && jogador_y < LINHA) {
                if (matriz[jogador_x][jogador_y] != 0 && coordenadas_usadas[jogador_x][jogador_y] == 0) {
                    printf("Você acertou!\n");
                    printf("\n");
                    *jogador += matriz[jogador_x][jogador_y];
                    matriz[jogador_x][jogador_y] = -1;
                    coordenadas_usadas[jogador_x][jogador_y] = 1;
                    jogaditas++;
                    validar = 0;
                } else if (coordenadas_usadas[jogador_x][jogador_y] == 1) {
                    printf("Essa coordenada já foi escolhida. Escolha outra.\n");
                } else {
                    printf("Você errou!\n");
                    printf("\n");
                    jogaditas++;
                    validar = 0;
                }
            } else {
                printf("Jogada inválida. As coordenadas estão fora dos limites.\n");
            }
        }
    }
}

void pontos(int jogador, int pc) {
    printf("Pontos do jogador = %d\n", jogador);
    printf("Pontos do PC = %d\n", pc);
    printf("\n");
}

void declarar_ganhador(int jogador, int pc) {
    if (jogador > pc) {
        printf("Jogador Ganhou!\n");
    } else if (pc > jogador) {
        printf("PC Ganhou!\n");
    } else {
        printf("Empate!\n");
    }
}

int main() {
    int jogador = 0;
    int pc = 0;

    setlocale(LC_ALL, "");
    int matriz[COLUNA][LINHA];
    int numeros_gerados[20];
    preencher_com_zero(matriz);
    randomizar(numeros_gerados);
    inserir_numeros_gerados_na_matriz(matriz, numeros_gerados);
    jogadas(matriz, &jogador, &pc);
    pontos(jogador, pc);
    declarar_ganhador(jogador, pc);
    apresentar_matriz(matriz);

    return 0;
}
