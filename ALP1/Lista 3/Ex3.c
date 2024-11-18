#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
float salario;
printf ("Insira o salário do funcionário: ");
scanf ("%f", &salario);
if (salario<=2500){
float reajuste= salario+(salario*0.15);
printf ("O salário reajustado do funcionário é de: R$%.2f\n", reajuste);}
if (salario>2500){
float reajuste= salario+(salario*0.10);
printf ("O salário reajustado do funcionário é de: R$%.2f\n", reajuste);
}
}
