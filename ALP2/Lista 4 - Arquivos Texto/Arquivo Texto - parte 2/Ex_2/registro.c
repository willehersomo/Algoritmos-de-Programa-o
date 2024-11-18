#include <stdio.h>
#include <locale.h>
#include "produtos.h"
#include "vendas.h"
#include "auxiliar.h"

#define TF  20
#define NOME 101

void exportar_dados_produtos(FILE *arquivo, struct produtos tab_produtos[], int tl_produtos)
{
    fprintf(arquivo, "-----------Dados dos produtos----------- \n");
    for (int i = 0; i < tl_produtos; i++)
    {
        fprintf(arquivo, "Código do produto: %d\nNome do produto: %s\nPreço: %.2f \nTotal em estoque: %d\n", tab_produtos[i].codigo, tab_produtos[i].nome, tab_produtos[i].preco, tab_produtos[i].estoque);
        fprintf(arquivo, "--------------\n");
    }
    fprintf(arquivo, "\n");
}

void exportar_dados_vendas(FILE *arquivo, struct vendas tab_vendas[], int tl_vendas)
{
    fprintf(arquivo, "----------Dados das vendas------------ \n");
    for (int i = 0; i < tl_vendas; i++)
    {
        fprintf(arquivo, "Código do produto: %d\nData da venda: %d/%d/%d\nQuantidade vendida: %d\n", tab_vendas[i].codigo_produto, tab_vendas[i].dia, tab_vendas[i].mes, tab_vendas[i].ano, tab_vendas[i].qnt_vendido);
        fprintf(arquivo, "--------------\n");
    }
}

void exportar_tabelas(struct produtos tab_produtos[], struct vendas tab_vendas[], int tl_produtos, int tl_vendas)
{
    FILE *arquivo = fopen("../dados.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao processar\n");
    }
    else
    {
        exportar_dados_produtos(arquivo, tab_produtos, tl_produtos);
        exportar_dados_vendas(arquivo, tab_vendas, tl_vendas);

        fclose(arquivo);
        printf("Dados exportados com sucesso.\n");
    }
}

void importar_dados_produtos(char linha[], struct produtos tab_produtos[], int *tl_produtos)
{
    sscanf(linha, "#%d/%[^'/']/%f/%d", &tab_produtos[*tl_produtos].codigo,
           tab_produtos[*tl_produtos].nome, &tab_produtos[*tl_produtos].preco,
           &tab_produtos[*tl_produtos].estoque);

    (*tl_produtos)++;
}

void importar_dados_vendas(char linha[], struct vendas tab_vendas[], int *tl_vendas)
{
    sscanf(linha, "*%d/%d-%d-%d/%d", &tab_vendas[*tl_vendas].codigo_produto,
           &tab_vendas[*tl_vendas].dia, &tab_vendas[*tl_vendas].mes,
           &tab_vendas[*tl_vendas].ano, &tab_vendas[*tl_vendas].qnt_vendido);

    (*tl_vendas)++;
}

void importar_tabelas(struct produtos tab_produtos[], struct vendas tab_vendas[], int *tl_produtos, int *tl_vendas)
{
    FILE *arquivo_2 = fopen("../dados_importar.txt", "r");

    if (arquivo_2 == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.\n");
    }
    else
    {
        char linha[256];
        while (fgets(linha, sizeof(linha), arquivo_2) != NULL)
        {
            char primeiro_char = linha[0];
            if (primeiro_char == '#')
            {
                importar_dados_produtos(linha, tab_produtos, tl_produtos);
            }
            else if (primeiro_char == '*')
            {   
                importar_dados_vendas(linha, tab_vendas, tl_vendas);
            }
        }
        fclose(arquivo_2);
        printf("Dados importados com sucesso.\n");
    }
}

int menu()
{
    int op;
    do
    {
        printf("MERCADINHO DA ESQUINA \n");
        printf("ESCOLHA:\n");
        printf("1 - Incluir produto\n");
        printf("2 - Alterar produto\n");
        printf("3 - Excluir Produto não vendido\n");
        printf("4 - Pesquisar pelo código do produto\n");
        printf("5 - Adicionar mais produtos ao estoque\n");
        printf("6 - Apresentar dados de todos os produtos\n");
        printf("7 - Apresentar balanço do estoque\n");
        printf("8 - Apresentar produtos com menos de 5 unidades\n");
        printf("9 - Incluir venda\n");
        printf("10 - Apresentar dados de todas as vendas de um determinado produto\n");
        printf("11 - Apresentar relação de todas as vendas em uma determinada data\n");
        printf("12 - Apresentar quantidade vendida de cada produtos\n");
        printf("13 - Total arrecadado em um mês\n");
        printf("14 - Exportar dados das tabelas para arquivo ""dados.txt""\n");
        printf("15 - Importar dados do arquivo ""dados_importar.txt""\n");
        printf("0 - Fechar Programa\n");

        printf("Digite a opção: ");
        scanf("%d", &op);
        printf("\n");

        if (op < 0 || op > 15)
        {
            printf("Opção inválida!!!\n");
        }
    }
    while (op < 0 || op > 15);

    return op;
}

int main()
{
    setlocale(LC_ALL, "");
    struct produtos tab_produtos[TF];
    struct vendas tab_vendas[TF];
    int tl_vendas = 0;
    int tl_produtos = 0;
    int codigo_selecionado;
    int opcao;
    do
    {
        system("cls");
        opcao = menu();
        switch (opcao)
        {
        case 1:
            incluir_produto(tab_produtos, &tl_produtos);
            break;

        case 2:
            alterar_produto(tab_produtos, tl_produtos);
            break;

        case 3:
            excluir_produto_se_nao_vendido(tab_produtos, tab_vendas, &tl_produtos, tl_vendas);
            break;

        case 4:
            pesquisar_produto_pelo_codigo(tab_produtos, tl_produtos);
            break;

        case 5:
            adicionar_produtos_estoque(tab_produtos, tl_produtos);
            break;
        case 6:
            apresentar_todos_produtos_informacao(tab_produtos, tl_produtos);
            break;
        case 7:
            calcular_e_apresentar_balanco_estoque(tab_produtos, tl_produtos);
            break;

        case 8:
            apresentar_produtos_estoque_baixo(tab_produtos, tl_produtos);
            break;
        case 9:
            incluir_venda(tab_produtos, tab_vendas, tl_produtos, &tl_vendas);
            break;
        case 10:
            apresentar_vendas_produto(tab_vendas, tab_produtos, tl_produtos, tl_vendas);
            break;

        case 11:
            apresentar_vendas_dia(tab_vendas, tab_produtos, tl_produtos, tl_vendas);
            break;
        case 12:
            apresentar_vendas_todos_produtos(tab_produtos, tab_vendas, tl_produtos, tl_vendas);
            break;
        case 13:
            apresentar_vendas_mes(tab_vendas, tab_produtos, tl_produtos, tl_vendas);
            break;

        case 14:
            exportar_tabelas(tab_produtos, tab_vendas, tl_produtos, tl_vendas);
            break;

        case 15:
            importar_tabelas(tab_produtos, tab_vendas, &tl_produtos, &tl_vendas);
            break;

        default:
            break;
        }
        system("pause");
    }
    while (opcao != 0);
    return 0;
}