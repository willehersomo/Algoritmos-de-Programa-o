#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
float preco;
int cod;
printf ("Insira o preço do produto: ");
scanf ("%f", &preco);
printf ("Insira o código do produto: ");
scanf ("%d", &cod);
printf ("O preço do seu produto é: R$%.2f\n", preco);
switch (cod){
case 1 ... 5:
printf ("Sua procedência é: SUL\n");
break;
case 6 ... 7:
printf ("Sua procedência é: NORTE\n");
break;
case 8 ... 10:
printf ("Sua procedência é: CENTRO-OESTE\n");
break;
case 11 ... 20:
printf ("Sua procedência é: SUDESTE\n");
break;
case 21 ... 25:
printf ("Sua procedência é: NORDESTE\n");
break;
default:
printf ("INVÁLIDO\n");
break;
}
}


