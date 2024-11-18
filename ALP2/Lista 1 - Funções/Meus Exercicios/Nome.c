#include <stdio.h>
#include <locale.h>
#define TF 100

int contar_caracteres(char nome[])
{
    int i = 0;
    int cont = 0;
    while (nome[i] != '\0')
    {
        cont++;
        i++;
    }
    return cont;
}


int contar_palavras(char nome[])
{
    int i, palavras = 0;
    for (i = 0; i < contar_caracteres(nome); i++)
    {
        if (nome[i] == ' ')
        {
            palavras++;
        }
    }
    return palavras + 1;
}


int contar_letras(char nome[])
{
    int i, letras = 0;
    for (i = 0; i < contar_caracteres(nome); i++)
    {
        if (nome[i] != ' ')
        {
            letras++;
        }
    }
    return letras;
}

void imprimir_palavras(char nome[])
{
    int i, j = 0, k=0;
    printf("Palavras que formam o nome:\n");
    for (i = 0; i < contar_caracteres(nome); i++)
    {
        if (nome[i] == ' ')
        {
            printf("\n");
            j++;
        }
        else
        {
            printf("%c", nome[i]);
            k++;
            if (i == k-1||i==k)
            {
                if (nome[i] >= 'A' && nome[i] <= 'Z')
                {
                    printf(" (essa palavra inicia com letra maiúscula)\n");
                    j--;
                    i--;
                }
                else if (nome [i]>='a'&& nome[i]<='z')
                {
                    printf (" (essa palavra inicia com letra minúscula)\n" );
                    j--;
                    i--;
                }
            }
        }
    }
}


void copiar_nome_sem_espacos(char nome[], char nome_sem_espacos[])
{
    int i, k = 0;
    for (i = 0; i < contar_caracteres(nome); i++)
    {
        if (nome[i] != ' ')
        {
            nome_sem_espacos[k] = nome[i];
            k++;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "");
    char nome[TF];
    char nome_sem_espacos[TF];


    printf("Digite o nome completo de uma pessoa: ");
    fgets(nome, TF, stdin);

    printf("Quantidade de palavras que formam esse nome: %d\n", contar_palavras(nome));

    printf("Quantidade de letras nesse nome, sem contar espaços: %d\n", contar_letras(nome));

    imprimir_palavras(nome);

    copiar_nome_sem_espacos(nome, nome_sem_espacos);

    printf("Nome sem espaços em branco: %s\n", nome_sem_espacos);

    return 0;
}
