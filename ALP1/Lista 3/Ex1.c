#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
float salario;
setlocale (LC_ALL, "");
printf ("Insira o sal�rio do funcion�rio: ");
scanf ("%f", &salario);
if (salario<1800.00)
{
float reajuste= salario+(salario*0.25);
printf ("O Reajuste salarial do funcion�rio � de: R$%.2f\n", reajuste);
}
else
{
printf ("O funcion�rio n�o tem direito ao reajuste, permanecendo o mesmo salario de: R$%.2f\n", salario);
}
}
