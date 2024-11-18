#include <stdio.h>
#include <string.h>

void abrir_arquivo(FILE **arquivo, FILE **destino)
{
    *arquivo = fopen("../html.html", "r");
    *destino = fopen("../descartado.txt", "w+");
}

void fechar_arquivo(FILE *arquivo, FILE *destino)
{
    fclose(arquivo);
    fclose(destino);
}

void voltar_ao_inicio(FILE *destino)
{
    rewind(destino);
}

void extrair_tags(FILE *arquivo, FILE *destino)
{
    char linha[256];
    int encontrou = 0;

    while (fgets(linha, sizeof(linha), arquivo) != NULL && !encontrou)
    {
        char *inicio = strchr(linha, '<');
        char *fim;

        while (inicio != NULL && !encontrou)
        {
            fim = strchr(inicio, '>');

            if (fim != NULL)
            {
                encontrou = 1;
                fwrite(inicio, 1, fim - inicio + 1, destino);
                fprintf(destino, "\n");
                inicio = strchr(fim + 1, '<');
            }
            else
            {
                encontrou = 1;
            }
        }

        encontrou = 0;
    }
}


void apresentar_arquivo(FILE *destino)
{
    char caracter;
    voltar_ao_inicio(destino);
    while ((caracter = fgetc(destino)) != EOF)
    {
        printf("%c", caracter);
    }
    printf("\n");
}



void organizar_cod(FILE *arquivo, FILE *destino)
{
    abrir_arquivo(&arquivo, &destino);

    if (arquivo == NULL || destino == NULL)
    {
        printf("Arquivo inexistente\n");
    }
    else
    {   printf ("Entrou em organizar\n");
        extrair_tags(arquivo, destino);
        apresentar_arquivo(destino);
        fechar_arquivo(arquivo, destino);
    }
}

int main()
{

    FILE *arquivo, *destino;
    organizar_cod(arquivo, destino);
    return 0;
}
