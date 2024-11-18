#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
float salario;
setlocale (LC_ALL, "");
printf ("Insira o salário do funcionário: ");
scanf ("%f", &salario);
if (salario<1800.00)
{
float reajuste= salario+(salario*0.25);
printf ("O Reajuste salarial do funcionário é de: R$%.2f\n", reajuste);
}
else
{
printf ("O funcionário não tem direito ao reajuste, permanecendo o mesmo salario de: R$%.2f\n", salario);
}
}
