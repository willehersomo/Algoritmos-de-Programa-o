#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
float inicial;
setlocale (LC_ALL, "");
printf ("Insira o preço inicial (de custo) da venda da Empresa Malhada: ");
scanf ("%f", &inicial);
float vendamalhada = inicial+(inicial*0.5);
float vendaconceicao = vendamalhada+(vendamalhada*0.35);
float lucromalhada = vendamalhada-inicial;
float lucroconceicao = vendaconceicao-vendamalhada;
printf ("O valor da venda das roupas da empresa malhada é de: R$%.2f\n", vendamalhada);
printf ("Tendo o lucro de: R$%.2f\n", lucromalhada);
printf ("O valor da venda da Dona Conceição é de: R$%.2f\n", vendaconceicao);
printf ("Tendo o lucro de: R$%.2f\n", lucroconceicao);
}
