#include <stdio.h>

void abrir_arquivos(FILE **arquivo, FILE **destino) {
    *arquivo = fopen("../texto_criptografado.txt", "r");
    *destino = fopen("../texto_descriptografado.txt", "w");
}

void descriptografar(FILE *arquivo, FILE *destino) {
    char c;
    if (arquivo == NULL || destino == NULL) {
        printf("N�o h� segredos para revelar\n");
    } else {
        while ((c = fgetc(arquivo)) != EOF) {
            if (c == '\n') {
                fputc(c, destino);
            } else {
                fputc(c - 1, destino);
            }
        }
    }
}

void fechar_arquivos(FILE *arquivo, FILE *destino) {
    fclose(arquivo);
    fclose(destino);
}

int main() {
    FILE *arquivo, *destino;
    abrir_arquivos(&arquivo, &destino);
    descriptografar(arquivo, destino);
    fechar_arquivos(arquivo, destino);
    printf("Segredo revelado, :OOOO\n");
    return 0;
}
