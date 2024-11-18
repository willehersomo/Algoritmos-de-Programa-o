#include <stdio.h>
#include <locale.h>
#define TF 5

struct produto
{
    int qnt_produtos;
    int codigo;
    int estoque;
    float preco;
    char nomes[50];
};

void abrir_arquivo_produto(FILE **arquivo)
{
    *arquivo = fopen("../produtos-exerc1.txt", "r");
}

void fechar_arquivo_produto(FILE *arquivo)
{
    fclose(arquivo);
}

void ler_informacoes(FILE *arquivo, struct produto tab_produto[])
{
    fscanf(arquivo, "%d", &tab_produto[0].qnt_produtos);

    for (int i = 0; i < tab_produto[0].qnt_produtos; i++)
    {
        fscanf(arquivo, "%d %49[^\n] %d %f", &tab_produto[i].codigo, tab_produto[i].nomes, &tab_produto[i].estoque, &tab_produto[i].preco);
    }
}

void apresentar_informacoes(struct produto tab_produto[])
{
    printf("Quantidade de produto: %d\n", tab_produto[0].qnt_produtos);
    printf ("\n");
    for (int i = 0; i < tab_produto[0].qnt_produtos; i++)
    {
        printf("Nome do produto: %s\nCodigo: %d\nTotal no estoque: %d\nPreço: %.2f\n", tab_produto[i].nomes, tab_produto[i].codigo, tab_produto[i].estoque, tab_produto[i].preco);
        printf ("\n");
    }
}

void processar_informacoes(FILE *arquivo, struct produto tab_produto[])
{
    abrir_arquivo_produto(&arquivo);
    if (arquivo == NULL)
    {
        printf("Falha ao processar\n");
    }
    else
    {
        ler_informacoes(arquivo, tab_produto);
        apresentar_informacoes(tab_produto);
    }
    fechar_arquivo_produto(arquivo);
}

int main()
{   setlocale (LC_ALL, "english"); //em português ele não consegui ler o preço e bugava as leituras seguintes (devido ao ".")
    FILE *arquivo;
    struct produto tab_produto[TF];
    processar_informacoes(arquivo, tab_produto);
    return 0;
}



