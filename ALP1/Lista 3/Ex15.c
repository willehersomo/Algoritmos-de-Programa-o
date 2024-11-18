#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
int idade;
printf ("Insira a idade da pessoa: ");
scanf ("%d", &idade);
switch(idade){
case 0 ... 18:
printf ("Essa pessoa deverá pagar R$180\n");
break;
case 19 ... 30:
printf ("Essa pessoa deverá pagar R$240\n");
break;
case 31 ... 45:
printf ("Essa pessoa deverá pagar R$300\n");
break;
case 46 ... 59:
printf ("Essa pessoa deverá pagar R$340\n");
break;
case 60 ... 65:
printf ("Essa pessoa deverá pagar R$400\n");
break;
default:
printf ("Essa deverá pagar R$610\n");
}
}
