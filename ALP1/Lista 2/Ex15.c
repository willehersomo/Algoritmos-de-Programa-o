#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
float saldo, deposito, renumeracao, meses;
setlocale (LC_ALL, "");
printf ("Digite o saldo na conta antes do deposito: ");
scanf ("%f", &saldo);
printf ("Digite o valor do depósito: ");
scanf ("%f", &deposito);
printf ("Digite o percentual de renumeração mensal do valor depositado: ");
scanf ("%f", &renumeracao);
printf ("Insira a quantidade de meses ao qual esse valor depositado ficou na sua conta: ");
scanf ("%f", &meses);
float valorganho= deposito+(deposito*(meses*(renumeracao/100)));
float valorfinal= saldo+valorganho;
printf ("O valor ganho com esse depósito acumulado em meses foi de: R$%.2f\n", valorganho);
printf ("E o valor total é: R$%.2f\n", valorfinal);
}
