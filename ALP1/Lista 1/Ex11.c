#include <stdio.h>
#include <locale.h>

void main()
{
float salario;
setlocale (LC_ALL, "");
printf ("Qual o salário do funcionário?\n");
scanf ("%f", &salario);
float salarioaumento= salario+(salario*0.15);
printf ("Seu salário somente com o aumento foi de R$%.2f\n", salarioaumento);
float salariofinal= salarioaumento-(salarioaumento*0.08);
printf ("No entanto, seu salário final, descontando os impostos, foi de R$%.2f\n", salariofinal);
}

