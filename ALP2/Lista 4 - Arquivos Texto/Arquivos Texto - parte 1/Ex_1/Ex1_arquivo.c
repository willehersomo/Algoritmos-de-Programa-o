#include <stdio.h>
#include <locale.h>
#include <string.h>

void abrir_arquivo(FILE **arquivo)
{
    *arquivo = fopen("../texto.txt", "r");
}

void fechar_arquivo(FILE *arquivo)
{
    fclose(arquivo);
}

void voltar_ao_inicio(FILE *arquivo)
{
    rewind(arquivo);
}

int cont_linha(FILE *arquivo)
{
    int valido = 0;
    char c;
    int cont = 0;

    voltar_ao_inicio(arquivo);

    while (valido != 1)
    {
        c = fgetc(arquivo);
        if (c == EOF)
        {
            cont++;
            valido = 1;
        }
        else if (c == '\n')
        {
            cont++;
        }
    }
    return cont;
}

int cont_espaco_branco(FILE *arquivo)
{
    int cont = 0;
    int valido = 0;
    char c;

    voltar_ao_inicio(arquivo);
    while (valido != 1)
    {
        c = fgetc(arquivo);
        if (c == EOF)
        {
            valido = 1;
        }
        else if (c == ' ')
        {
            cont++;
        }
    }
    return cont;
}

int cont_letras(FILE *arquivo)
{
    int valido = 0;
    char c;
    int cont = 0;

    voltar_ao_inicio(arquivo);

    while (valido != 1)
    {
        c = fgetc(arquivo);
        if (c == EOF)
        {
            valido = 1;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            cont++;
        }
    }
    return cont;
}

int cont_numeros(FILE *arquivo)
{
    int valido = 0;
    char c;
    int cont = 0;

    voltar_ao_inicio(arquivo);

    while (valido != 1)
    {
        c = fgetc(arquivo);
        if (c == EOF)
        {
            valido = 1;
        }
        else if (c >= '0' && c <= '9')
        {
            cont++;
        }
    }
    return cont;
}

int cont_char(FILE *arquivo)
{
    int valido = 0;
    char c;
    int cont = 0;

    voltar_ao_inicio(arquivo);

    while (valido != 1)
    {
        c = fgetc(arquivo);
        if (c == EOF)
        {
            valido = 1;
        }
        else
        {
            cont++;
        }
    }
    return cont;
}

void imprimir_informacoes(FILE *arquivo)
{
    printf("Quantidade de linhas no arquivo: %d\n", cont_linha(arquivo));
    printf("Quantidade de espaços em branco no arquivo: %d\n", cont_espaco_branco(arquivo));
    printf("Quantidade de letras no arquivo: %d\n", cont_letras(arquivo));
    printf("Quantidade de números no arquivo: %d\n", cont_numeros(arquivo));
    printf("Quantidade de caracteres no arquivo: %d\n", cont_char(arquivo));
}

void validar_impressao()
{
    FILE *arquivo;
    abrir_arquivo(&arquivo);

    if (arquivo == NULL)
    {
        printf("Nenhuma informação\n");
    }
    else
    {
        imprimir_informacoes(arquivo);
        fechar_arquivo(arquivo);
    }
}

int main()
{
    setlocale(LC_ALL, "");
    validar_impressao();
    return 0;
}
