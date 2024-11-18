#include <stdio.h>
#include <locale.h>
#define TF 30

void apresentar_cupom(int codigos[], float valores_unitarios[], int quantidades[], int n)
{
    printf("Cupom de compra:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Código: %d\n", codigos[i]);
        printf("Valor unitário: %.2f\n", valores_unitarios[i]);
        printf("Quantidade: %d\n", quantidades[i]);
        printf("Total do item: %.2f\n", valores_unitarios[i] * quantidades[i]);
    }
}

void apresentar_resumo(int codigos[], float valores_unitarios[], int quantidades[], int n)
{
    int qtd_itens = 0;
    float valor_total = 0;
    for (int i = 0; i < n; i++)
    {
        qtd_itens += quantidades[i];
        valor_total += valores_unitarios[i] * quantidades[i];
    }
    printf("Quantidade de itens comprados: %d\n", qtd_itens);
    printf("Valor total da compra: %.2f\n", valor_total);
    printf("Quantidade de diferentes produtos: %d\n", n);
}

void apresentar_produtos_valor_superior(int codigos[], float valores_unitarios[], int quantidades[], int n, float valor)
{
    printf("Produtos com valor superior a %.2f:\n", valor);
    for (int i = 0; i < n; i++)
    {
        if (valores_unitarios[i] > valor)
        {
            printf("Código: %d\n", codigos[i]);
            printf("Valor unitário: %.2f\n", valores_unitarios[i]);
            printf("Quantidade: %d\n", quantidades[i]);
            printf("Total do item: %.2f\n", valores_unitarios[i] * quantidades[i]);
        }
    }
}

void apresentar_informacoes_produto(int codigos[], float valores_unitarios[], int quantidades[], int n, int codigo)
{
    for (int i = 0; i < n; i++)
    {
        if (codigos[i] == codigo)
        {
            printf("Informações do produto com código %d:\n", codigo);
            printf("Quantidade comprada: %d\n", quantidades[i]);
            printf("Valor unitário: %.2f\n", valores_unitarios[i]);
            printf("Valor total do item: %.2f\n", valores_unitarios[i] * quantidades[i]);
            return;
        }
    }
    printf("Produto com código %d não encontrado.\n", codigo);
}

int main()
{
    setlocale(LC_ALL, "");
    int codigos[TF];
    float valores_unitarios[TF];
    int quantidades[TF];
    int n = 0;


    int adicionar_produto = 1;
    while (adicionar_produto)
    {
        char opcao;
        printf("Deseja adicionar um produto à compra? (s/n): ");
        scanf(" %c", &opcao);

        if (opcao == 'n' || opcao == 'N')
        {
            adicionar_produto = 0;
        }
        else if (n >= TF)
        {
            printf("A compra já tem o máximo de %d itens.\n", TF);
        }
        else
        {
            printf("Digite o código do produto: ");
            scanf("%d", &codigos[n]);
            printf("Digite o valor unitário do produto: ");
            scanf("%f", &valores_unitarios[n]);
            printf("Digite a quantidade comprada do produto: ");
            scanf("%d", &quantidades[n]);

            n++;
        }
    }


    apresentar_cupom(codigos, valores_unitarios, quantidades, n);


    apresentar_resumo(codigos, valores_unitarios, quantidades, n);


    float valor;
    printf("Digite o valor para apresentar os produtos com valor superior: ");
    scanf("%f", &valor);
    apresentar_produtos_valor_superior(codigos, valores_unitarios, quantidades, n, valor);


    int codigo;
    printf("Digite o código do produto para apresentar suas informações: ");
    scanf("%d", &codigo);
    apresentar_informacoes_produto(codigos, valores_unitarios, quantidades, n, codigo);

    return 0;
}
