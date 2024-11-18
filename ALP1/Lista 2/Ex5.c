#include <stdio.h>
#include <locale.h>

void main()
{
float salario, venda;
setlocale(LC_ALL, "");
printf ("Digite o salário do vendedor: ");
scanf ("%f", &salario);
printf ("Digite o valor total de suas vendas: ");
scanf ("%f", &venda);
float comissao= venda*0.05;
printf ("A comissão do vendedor equivale a R$%.2f\n", comissao);
float salariofinal= salario+comissao;
printf ("O salário final do vendedor é de R$%.2f\n", salariofinal);
}
