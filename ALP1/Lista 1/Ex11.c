#include <stdio.h>
#include <locale.h>

void main()
{
float salario;
setlocale (LC_ALL, "");
printf ("Qual o sal�rio do funcion�rio?\n");
scanf ("%f", &salario);
float salarioaumento= salario+(salario*0.15);
printf ("Seu sal�rio somente com o aumento foi de R$%.2f\n", salarioaumento);
float salariofinal= salarioaumento-(salarioaumento*0.08);
printf ("No entanto, seu sal�rio final, descontando os impostos, foi de R$%.2f\n", salariofinal);
}

