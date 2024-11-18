#include <stdio.h>
#include <locale.h>
#include "produtos.h"
#include "vendas.h"
#include "auxiliar.h"

#define TF  20
#define NOME 101

//Autores do código:
//Breno Wille Bezerra Correia
//Natany do Prado Carvalho


int menu ()
{
    int op;
    do
    {   printf ("MERCADINHO DA ESQUINA \n");
        printf ("ESCOLHA:\n");
        printf ("1 - Incluir produto\n");
        printf ("2 - Alterar produto\n");
        printf ("3 - Excluir Produto não vendido\n");
        printf ("4 - Pesquisar pelo código do produto\n");
        printf ("5 - Adicionar mais produtos ao estoque\n");
        printf ("6 - Apresentar dados de todos os produtos\n");
        printf ("7 - Apresentar balanço do estoque\n");
        printf ("8 - Apresentar produtos com menos de 5 unidades\n");
        printf ("9 - Incluir venda\n");
        printf ("10 - Apresentar dados de todas as vendas de um determinado produto\n");
        printf ("11 - Apresentar relação de todas as vendas em uma determinada data\n");
        printf ("12 - Apresentar quantidade vendida de cada produtos\n");
        printf ("13 - Total arrecadado em um mês\n");
        printf ("0 - Fechar Programa\n");


        printf("Digite a opção: ");
        scanf("%d", &op);
        printf ("\n");

        if (op < 0 || op > 13)
        {
            printf("Opcao inválida!!!\n");
        }
    }
    while (op < 0 || op > 13);

    return op;
}


int main ()
{
    setlocale (LC_ALL, "");
    struct produtos tab_produtos [TF];
    struct vendas tab_vendas [TF];
    int tl_vendas=0;
    int tl_produtos=0;
    int codigo_selecionado;
    int opcao;
    do
    {
        system("cls");
        opcao = menu();
        switch(opcao)
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
            adicionar_produtos_estoque (tab_produtos, tl_produtos);
            break;
        case 6:
            apresentar_todos_produtos_informacao (tab_produtos, tl_produtos);
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
            apresentar_vendas_produto (tab_vendas, tab_produtos, tl_produtos, tl_vendas);
            break;

        case 11:
            apresentar_vendas_dia (tab_vendas, tab_produtos, tl_produtos, tl_vendas);
            break;
        case 12:
            apresentar_vendas_todos_produtos(tab_produtos, tab_vendas, tl_produtos, tl_vendas);
            break;
        case 13:
            apresentar_vendas_mes(tab_vendas, tab_produtos, tl_produtos, tl_vendas);
            break;

        default:
            break;

        }
        system("pause");
    }
    while (opcao != 0);
    return 0;

}
