#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
float preco;
int cod;
printf ("Insira o pre�o do produto: ");
scanf ("%f", &preco);
printf ("Insira o c�digo do produto: ");
scanf ("%d", &cod);
printf ("O pre�o do seu produto �: R$%.2f\n", preco);
switch (cod){
case 1 ... 5:
printf ("Sua proced�ncia �: SUL\n");
break;
case 6 ... 7:
printf ("Sua proced�ncia �: NORTE\n");
break;
case 8 ... 10:
printf ("Sua proced�ncia �: CENTRO-OESTE\n");
break;
case 11 ... 20:
printf ("Sua proced�ncia �: SUDESTE\n");
break;
case 21 ... 25:
printf ("Sua proced�ncia �: NORDESTE\n");
break;
default:
printf ("INV�LIDO\n");
break;
}
}


