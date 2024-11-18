#include <locale.h>
#include <stdio.h>
#include <locale.h>

#define LINHA 10
#define COLUNA 10

void preencher_matriz(int matriz[COLUNA][LINHA]) {
    int j, i;
    printf("Preencha a matriz: \n");
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            printf("Coluna %d - Linha %d\n", j + 1, i + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void apresentar_matriz(int matriz[COLUNA][LINHA]) {
    printf("     ");
    for (int j = 1; j <= LINHA; j++) {
        printf("%4d ", j);
    }
    printf("\n");
    printf("   ");

    for (int i = 0; i <= 51; i++) {
        printf("_");
    }
    printf("\n");

    for (int i = 0; i < COLUNA; i++) {
        printf("%4d|", i + 1);

        for (int j = 0; j < LINHA; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void calcular_linhas(int matriz[COLUNA][LINHA], int valores_linhas[LINHA]) {
    for (int i = 0; i < LINHA; i++) {
        valores_linhas[i] = 0;
        for (int j = 0; j < COLUNA; j++) {
            valores_linhas[i] += matriz[i][j];
        }
    }
}

void apresentar_linhas(int valores_linhas[]) {
    for (int i = 0; i < LINHA; i++) {
        printf("Soma da linha %d: %d\n", i + 1, valores_linhas[i]);
    }
}

void calcular_colunas(int matriz[COLUNA][LINHA], int valores_colunas[COLUNA]) {
    for (int j = 0; j < COLUNA; j++) {
        valores_colunas[j] = 0;
        for (int i = 0; i < LINHA; i++) {
            valores_colunas[j] += matriz[i][j];
        }
    }
}

void apresentar_colunas(int valores_colunas[]) {
    for (int i = 0; i < COLUNA; i++) {
        printf("Soma da coluna %d: %d\n", i + 1, valores_colunas[i]);
    }
}

int apresentar_maior_soma_linha(int valores_linhas[LINHA]) {
    int maior = valores_linhas[0];
    int indice_maior = 0;
    for (int i = 1; i < LINHA; i++) {
        if (valores_linhas[i] > maior) {
            maior = valores_linhas[i];
            indice_maior = i;
        }
    }
    return indice_maior + 1;
}

int maior_elemento_linha(int matriz[COLUNA][LINHA], int linha) {
    int maior = matriz[linha][0];
    for (int j = 1; j < COLUNA; j++) {
        if (matriz[linha][j] > maior) {
            maior = j;
        }
    }
    return maior+1;
}

int maior_elemento_coluna(int matriz[COLUNA][LINHA], int coluna) {
    int maior = matriz[0][coluna];
    for (int i = 1; i < LINHA; i++) {
        if (matriz[i][coluna] > maior) {
            maior = i;
        }
    }
    return maior+1;
}

void menor_elemento_pos(int matriz[COLUNA][LINHA], int pos[2]) {
    int menor = matriz[0][0];
    pos[0] = 0;
    pos[1] = 0;

    for (int i = 0; i < LINHA; i++) {
        for (int j = 0; j < COLUNA; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
}

void apresentar_menor_pos(int pos[]) {
    printf("Posição do menor elemento: Linha %d - Coluna %d\n", pos[0] + 1, pos[1] + 1);
}

int main() {
    setlocale (LC_ALL, "");
    int matriz[COLUNA][LINHA];
    int valores_linhas[LINHA];
    int valores_colunas[COLUNA];
    int pos[2];

    preencher_matriz(matriz);
    apresentar_matriz(matriz);
    calcular_linhas(matriz, valores_linhas);
    apresentar_linhas(valores_linhas);
    calcular_colunas(matriz, valores_colunas);
    apresentar_colunas(valores_colunas);

    int maior_soma_linha = apresentar_maior_soma_linha(valores_linhas);
    printf("Maior linha (somatória): %d\n", maior_soma_linha);

    int linha_maior_elemento = maior_elemento_linha(matriz, maior_soma_linha - 1);
    printf("Maior linha (elemento): %d\n", linha_maior_elemento);

    int coluna_maior_elemento = maior_elemento_coluna(matriz, maior_soma_linha - 1);
    printf("Maior coluna (elemento): %d\n", coluna_maior_elemento);

    menor_elemento_pos(matriz, pos);
    apresentar_menor_pos(pos);

    return 0;
}
