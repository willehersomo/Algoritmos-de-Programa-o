/*Fazer um programa em linguagem c capaz de armazenar uma compra em um estabelecimento comercial,
onde para cada um dos produtos adquiridos preciso armazenar o código de barras, o valor unitário
e a quantidade comprada e permita:

Apresentar o cupom de compra contendo: código do produto, valor unitário, quantidade e total do item.
Apresentar ao final do cupom a quantidade de itens comprados, e o valor total da compra,
 além da quantidade de diferentes produtos;
Apresentar os produtos com valor superior a um determinado valor passado pelo usuário;
Com base no código do produto passado pelo usuário, apresentar a quantidade comprada,
o valor unitário e o valor total desse item.

OBS: cada compra pode ter no máximo 30 itens. */


#include <stdio.h>
#define TF 3

char ler_op()
{
    char opcao;
    do
    {
        printf("Deseja adicionar um produto à compra? (s/n): ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao); // transforma conteudo da variavel opcao em maiusculo
    }
    while (opcao!='N'&&opcao!='S');
    return opcao;
}


int ler (int codigos[], float valores_unitarios[], int quantidades[])
{
    char op;
    int adicionar_produto, tl=0;
    // entra lido
    op = ler_op();

    while (op!='N'&& tl<TF)
    {
        printf("Digite o código do produto: ");
        scanf("%d", &codigos[tl]);
        printf("Digite o valor unitário do produto: ");
        scanf("%f", &valores_unitarios[tl]);
        printf("Digite a quantidade comprada do produto: ");
        scanf("%d", &quantidades[tl]);
        tl++;
        // sai lido
        op = ler_op();
    }
    return tl;
}

int menu()
{
    int opcao;
    printf("\n~~~~~~Menu~~~~~~\n");
    printf("1. Adicionar produto\n");
    printf("2. Mostrar cupom de compra\n");
    printf("3. Produtos com valor superior a um determinado valor\n");
    printf("4. Informacoes de um produto por codigo\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

float calcularTotalItem( float vunitario, int qnt)
{
    return vunitario*qnt;
}

void exibircupom( int cod[], float vunitario[], int qnt[], int totalprodutos, float totalcompra)
{
    printf("\n\n ------Cupom de Compra------ \n\n");
    for (int i = 0; i < totalprodutos; i++)
    {
        printf("Codigo: %d, Valor Unitario: R$%.2f, Quantidade: %d, Total do item: R$%.2f\n", cod[i],
               vunitario[i], qnt[i],
               calcularTotalItem(vunitario[i], qnt[i]));
    }
    printf("Quantidade de itens comprados: %d", totalprodutos);
    printf("Valor total da compra: R$%.2f\n", totalcompra);
}

void apresentarAcimaLimite(float valor, int cod[], float vunitario[], int qnt[], int totalprodutos)
{
    for(int i=0; i < totalprodutos; i++)
    {
        if(vunitario[i] > valor)
        {
            printf("Codigo: %d, Valor Unitario: R$%.2f, Quantidade: %d, Total do Item: R$%.2f\n",
                   cod[i], vunitario[i], qnt[i], calcularTotalItem(vunitario[i],qnt[i]));
        }
    }
}


int apresentarCodigo (int codigo, int cod[], float vunitario[], int qnt[], int totalprodutos)
{
    int flag=0;
    for(int i=0; i < totalprodutos; i++)
    {
        if(cod[i] == codigo)
        {
            printf("Codigo: %d, Valor Unitario: R$%.2f, Quantidade: %d, Total do Item: R$%.2f\n",
                   cod[i], vunitario[i], qnt[i],
                   calcularTotalItem(vunitario[i], qnt[i]));
            i=totalprodutos; // forcar o i ir para o final para não percorrer o restante do for
            flag = 1; // para avisar que encontrou
        }
    }
    return flag;
}

void main()
{

    int resp, codbarras[TF], cod, i, totalprodutos = 0, quantidade[TF], opcao;
    float valorunitario[TF], totalcompra = 0, vlimite;

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            if(totalprodutos < TF)
            {
                totalprodutos = ler (codbarras,valorunitario,quantidade);
                totalcompra += calcularTotalItem(valorunitario[totalprodutos], quantidade[totalprodutos]);
            }
            else
            {
                printf("O carrinho esta cheio!!!");
            }
            break;
        case 2:
            exibircupom(codbarras, valorunitario, quantidade, totalprodutos, totalcompra);
            break;

        case 3:
            printf("Infome o valor limite: ");
            scanf("%f", &vlimite);
            printf("\n------ Produtos com Valor Superior a %.2f -------\n", vlimite);
            apresentarAcimaLimite(vlimite, codbarras, valorunitario, quantidade, totalprodutos);
            break;
        case 4:
            printf("informe o codigo do produto: ");
            scanf("%d", &cod);
            resp= apresentarCodigo(cod, codbarras, valorunitario, quantidade, totalprodutos);
            if (resp==0)
            {
               printf("Produto não encontrado!!\n");
            }
            break;
        case 5:
            printf("Saindo do programa...");
            break;

        default:
            if (opcao!=5)
            {
                printf("Opcao invalida!!");
            }
            break;
        }
    }
    while (opcao != 5);

}
