#include <stdio.h>
#include <string.h>
#include <locale.h>
#define TF 51

void ler_strings(char string1[], char string2[])
{
    printf("Insira o conteúdo na string1:\n");
    scanf(" %50[^\n]", string1);
    printf("Insira o conteúdo na string2:\n");
    scanf(" %50[^\n]", string2);
}

int comparar_strings(char string1[], char string2[])
{
    int len = strlen(string1);
    int len2 = strlen(string2);

    if (len != len2)
    {
        return 0;
    }
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (string1[i] != string2[i])
            {
                return 0;
            }
        }
    }
    return 1;
}

int verificar_maior(char string1[], char string2[])
{
    int len = strlen(string1);
    int len2 = strlen(string2);

    if (len > len2)
    {
        return 1;
    }
    else if (len2 > len)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

void localizar_string(char string1[], char string2[])
{
    if (strstr(string1, string2) != NULL)
    {
        printf("String2 encontrada dentro da string1.\n");
    }
    else
    {
        printf("String2 não encontrada dentro da string1.\n");
    }

    if (strstr(string2, string1) != NULL)
    {
        printf("String1 encontrada dentro da string2.\n");
    }
    else
    {
        printf("String1 não encontrada dentro da string2.\n");
    }
}

void localizar_caracter(char string1[])
{
    int validar = 1;
    char caractere;
    printf("Digite o caractere que deseja procurar na string1:\n");
    scanf(" %c", &caractere);

    int len = strlen(string1);
    int encontrado = 0;

    do
    {
        for (int i = len-1; i >0; i--)
        {
            if (string1[i] == caractere)
            {
                printf("Caractere '%c' encontrado na posição %d da string1.\n", caractere, i);
                encontrado = 1;
                i=0;
            }
        }
    }
    while (encontrado!=1);

    if (!encontrado)
    {
        printf("Caractere '%c' não encontrado na string1.\n", caractere);
    }
}

void localizar_caracter2(char string2[])
{
    char caractere;
    printf("Digite o caractere que deseja procurar na string2:\n");
    scanf(" %c", &caractere);

    int len = strlen(string2);
    int encontrado = 0;

    do
    {
        for (int i = len - 1; i >= 0; i--)
        {
            if (string2[i] == caractere)
            {
                printf("Caractere '%c' encontrado na posição %d da string2.\n", caractere, i);
                encontrado = 1;
                i=0;

            }
        }
    }
    while (encontrado!=1);


    if (!encontrado)
    {
        printf("Caractere '%c' não encontrado na string2.\n", caractere);
    }
}

void verificar_vazia(char string1[])
{
    if (string1[0] == '\0')
    {
        printf("String vazia!\n");
    }
    else
    {
        printf("String não vazia!\n");
    }
}

void verificar_vazia2(char string2[])
{
    if (string2[0] == '\0')
    {
        printf("String2 vazia!\n");
    }
    else
    {
        printf("String2 não vazia!\n");
    }
}

int contar_maiusculas(char string1[])
{
    int len = strlen(string1);
    int contagem = 0;

    for (int i = 0; i < len; i++)
    {
        if (string1[i] >= 'A' && string1[i] <= 'Z')
        {
            contagem++;
        }
    }

    return contagem;
}

int contar_maiusculas2(char string2[])
{
    int len = strlen(string2);
    int contagem = 0;

    for (int i = 0; i < len; i++)
    {
        if (string2[i] >= 'A' && string2[i] <= 'Z')
        {
            contagem++;
        }
    }

    return contagem;
}

int contar_minusculas(char string1[])
{
    int len = strlen(string1);
    int contagem = 0;

    for (int i = 0; i < len; i++)
    {
        if (string1[i] >= 'a' && string1[i] <= 'z')
        {
            contagem++;
        }
    }

    return contagem;
}

int contar_minusculas2(char string2[])
{
    int len = strlen(string2);
    int contagem = 0;

    for (int i = 0; i < len; i++)
    {
        if (string2[i] >= 'a' && string2[i] <= 'z')
        {
            contagem++;
        }
    }

    return contagem;
}

int main()
{
    setlocale (LC_ALL, "");
    char string1[TF];
    char string2[TF];

    ler_strings(string1, string2);

    int resultado_comparacao = comparar_strings(string1, string2);
    int resultado_maior = verificar_maior(string1, string2);

    printf("Dado obtido ao comparar as strings: %d\n", resultado_comparacao);
    printf("Dado obtido ao verificar e comparar o tamanho de duas strings: %d\n", resultado_maior);

    localizar_string(string1, string2);
    localizar_caracter(string1);
    localizar_caracter2(string2);

    verificar_vazia(string1);
    verificar_vazia2(string2);

    int contagem_maiusculas_string1 = contar_maiusculas(string1);
    int contagem_maiusculas_string2 = contar_maiusculas2(string2);
    int contagem_minusculas_string1 = contar_minusculas(string1);
    int contagem_minusculas_string2 = contar_minusculas2(string2);

    printf("Quantidade de caracteres maiúsculos na string1: %d\n", contagem_maiusculas_string1);
    printf("Quantidade de caracteres maiúsculos na string2: %d\n", contagem_maiusculas_string2);
    printf("Quantidade de caracteres minúsculos na string1: %d\n", contagem_minusculas_string1);
    printf("Quantidade de caracteres minúsculos na string2: %d\n", contagem_minusculas_string2);

    return 0;
}
