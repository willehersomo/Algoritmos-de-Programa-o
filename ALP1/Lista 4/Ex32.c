#include <stdio.h>

void main() {
    char nome[31];
    int i, palavras = 0, letras = 0;
    int espaco = 1;

    printf("Insira seu nome: ");
    scanf("%30[^\n]", nome);

    for (i = 0; nome[i] != '\0'; i++) {
        if (nome[i] != ' ') {
            letras++;
            espaco = 0;
        } else if (nome[i] == ' ' && !espaco) {
            palavras++;
            espaco = 1;
        }
    }

    if (!espaco) {
        palavras++;
    }

    printf("Palavras: %d\n", palavras);
    printf("Letras: %d\n", letras);

    printf("Primeiro nome: ");
    for (i = 0; nome[i] != ' ' && nome[i] != '\0'; i++) {
        printf("%c", nome[i]);
    }
    printf("\n");

}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 21/06 às 20:19
