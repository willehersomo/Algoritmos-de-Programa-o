/*2 - Fazer um programa em linguagem C utilizando vetores, capaz de ler todos os valores de uma compra realizada em um supermercado
  e seja capaz de:
- Apresentar o cupom com todos os valores dos produtos comprados, com o numero sequencial do item;
- Apresentar o total da compra;
- O valor do produto mais caro;
- O numero do item do produto mais barato;

OBS: Considere que a compra sera sempre de 5 produtos. */

#include <stdio.h>
#define TF 5

void ler (float prod[])
{
    int i;
    for(i=0; i<TF; i++)
    {
        printf("\nDigite o valor do produto  %d - ", i + 1);
        scanf("%f", &prod[i]);
    }
}

void apresentar (float prod[])
{
    int i;
    for(i=0; i<TF; i++)
    {
        printf("\nProduto - %d - Valor: %.2f", i+1, prod[i]);
    }
}

float mais_caro (float vet[])
{
    int i;
    float maior = vet[0];

    for (i = 0; i < TF; i++)
    {

        if (vet[i] > maior)
        {
            maior = vet[i];
        }

    }
    return maior;
}

int mais_barato (float vet[])
{
    int i, menor, item;

    menor = vet[0];
    item = 0;

    for(i=0; i<TF; i++)
    {
        if(vet[i] < menor)
        {
            menor = vet[i];
            item = i;
        }
    }
    return item;
}


float calcular_total(float prod[])
{
    int i;
    float total=0;
    for(i=0; i<TF; i++)
    {
        total += prod[i];
    }
    return total;
}

void main()
{

    int i, menor;
    float produto[TF], total, maior;

    ler (produto);
    printf("\n----CUPOM----");
    apresentar (produto);
    maior = mais_caro(produto);
    menor = mais_barato(produto);
    total = calcular_total(produto);

    printf("\nTOTAL: %.2f\n", total);

    printf("\n\nProduto mais caro - preco: %.2f", maior);

    printf("\n\nCodigo do item mais barato - codigo: %d ", menor + 1);

}
