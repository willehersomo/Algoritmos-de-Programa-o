#include <stdio.h>
#include <locale.h>

void main()
{
float salario, venda;
setlocale(LC_ALL, "");
printf ("Digite o sal�rio do vendedor: ");
scanf ("%f", &salario);
printf ("Digite o valor total de suas vendas: ");
scanf ("%f", &venda);
float comissao= venda*0.05;
printf ("A comiss�o do vendedor equivale a R$%.2f\n", comissao);
float salariofinal= salario+comissao;
printf ("O sal�rio final do vendedor � de R$%.2f\n", salariofinal);
}
