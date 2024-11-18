#include <stdio.h>
#include <locale.h>

void main() {
    setlocale (LC_ALL, "");
    char frase[51];
    int i, palavras = 0, vogais = 0;
    char numeros[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    printf("Insira uma frase: ");
    scanf("%50[^\n]", frase);

    for (i = 0; frase[i] != '\0'; i++) {

        if (frase[i] == 'a' || frase[i] == 'A' ||
            frase[i] == 'e' || frase[i] == 'E' ||
            frase[i] == 'i' || frase[i] == 'I' ||
            frase[i] == 'o' || frase[i] == 'O' ||
            frase[i] == 'u' || frase[i] == 'U') {
            vogais++;
        }


        int j = 0;
        int encontrado = 0;
        while (j < 10 && !encontrado) {
            if (frase[i] == numeros[j]) {
                printf("Número encontrado: %c\n", frase[i]);
                encontrado = 1;
            }
            j++;
        }


        if (frase[i] == ' ') {

            if (frase[i + 1] != ' ' && frase[i + 1] != '\0') {
                palavras++;
            }
        }
    }


    if (frase[i - 1] != ' ') {
        palavras++;
    }

    printf("Palavras: %d\n", palavras);
    printf("Vogais: %d\n", vogais);

}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 22/06 às 17:38
