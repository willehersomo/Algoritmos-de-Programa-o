#include <stdio.h>
#include <locale.h>

void main ()
{
float base, altura, area;
setlocale (LC_ALL,"");
printf ("Qual a base do seu triângulo?\n");
scanf ("%f", &base);
printf ("e a altura?\n");
scanf ("%f", &altura);
area= (base*altura)/2;
printf ("A área de seu triângulo é de %.2f cm²\n", area);
}
