#include <stdio.h>
#include <locale.h>
#define TF 5

void apresentar_cupom(float valores[])
{
    printf("Cupom de compra:\n");
    for (int i = 0; i < TF; i++)
    {
        printf("Item %d: %.2f\n", i + 1, valores[i]);
    }
}

void apresentar_total_compra(float valores[])
{
    float total = 0;
    for (int i = 0; i < TF; i++)
    {
        total += valores[i];
    }
    printf("Total da compra: %.2f\n", total);
}

void apresentar_valor_produto_mais_caro(float valores[])
{
    float maior = valores[0];
    for (int i = 1; i < TF; i++)
    {
        if (valores[i] > maior)
        {
            maior = valores[i];
        }
    }
    printf("Valor do produto mais caro: %.2f\n", maior);
}

void apresentar_numero_item_produto_mais_barato(float valores[])
{
    float menor = valores[0];
    int menorzirto = 0;
    for (int i = 1; i < TF; i++)
    {
        if (valores[i] < menor)
        {
            menor = valores[i];
            menorzirto = i;
        }
    }
    printf("Número do item do produto mais barato: %d\n", menorzirto + 1);
}

int main()
{
    setlocale (LC_ALL, "");
    float valores[TF];


    for (int i = 0; i < TF; i++)
    {
        printf("Digite o valor do produto %d: ", i + 1);
        scanf("%f", &valores[i]);
    }


    apresentar_cupom(valores);


    apresentar_total_compra(valores);


    apresentar_valor_produto_mais_caro(valores);


    apresentar_numero_item_produto_mais_barato(valores);

    return 0;
}
