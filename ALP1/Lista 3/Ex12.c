#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
int cod;
printf ("Insira o c�digo do funcion�rio: ");
scanf ("%d", &cod);
switch (cod){
case 1:
printf ("Seu cargo � de ESCRITU�RIO, tendo o percentual de aumento de 50%%\n");
break;
case 2:
printf ("Seu cargo � de SECRET�RIO, tendo o percentual de aumento de 35%%\n");
break;
case 3:
printf ("Seu cargo � de CAIXA, tendo o percentual de aumento de 20%%\n");
break;
case 4:
printf ("Seu cargo � de GERENTE, tendo o percentual de aumento de 10%%\n");
break;
default:
printf ("INV�LIDO!\n");
break;
}
}
