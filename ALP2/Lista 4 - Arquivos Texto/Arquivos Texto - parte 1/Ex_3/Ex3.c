#include <stdio.h>
#include <string.h>
#include <ctype.h>

void abrir_arquivo(FILE **arquivo)
{
    *arquivo = fopen("../doc.css", "r");
}

void fechar_arquivo(FILE *arquivo)
{
    fclose(arquivo);
}

void voltar_ao_inicio(FILE *arquivo)
{
    rewind(arquivo);
}

void identificar_classe(FILE *arquivo)
{
    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        char primeiro_caracter = linha[0];

        if (primeiro_caracter == '.')
        {
            printf("Classe: %s", linha + 1);
        }
    }
}

void identificar_identificador(FILE *arquivo)
{
    voltar_ao_inicio(arquivo);

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        char primeiro_caracter = linha[0];

        if (primeiro_caracter == '#')
        {
            printf("Identificador: %s", linha + 1);
        }
    }
}

void identificar_elemento(FILE *arquivo)
{
    voltar_ao_inicio(arquivo);

    char linha[256];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        int i = 0;
        while (isspace(linha[i])) {
            i++;
        }

        if (linha[i] != '\0' && linha[i] != '\n' && linha[i] != '#' && linha[i] != '.')
        {

            if (strchr(linha, '{') != NULL)
            {
                printf("Elemento: %s", linha);
            }
        }
    }
}

void preencher (FILE *arquivo)
{

    abrir_arquivo(&arquivo);

    if (arquivo == NULL)
    {
        printf("Nenhuma informação\n");
    }

    else
    {
        identificar_classe(arquivo);
        identificar_identificador(arquivo);
        identificar_elemento(arquivo);

        fechar_arquivo(arquivo);
    }
}

int main ()
{
    FILE*arquivo;
    preencher(&arquivo);
    return 0;

}


