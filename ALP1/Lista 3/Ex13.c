#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale(LC_ALL,"");
int extra, falta;
printf ("Digite o n�mero de minutos extras do funcion�rio: ");
scanf ("%d", &extra);
printf ("Digite o n�mero de minutos referentes a faltas do funcion�rio: ");
scanf ("%d", &falta);
float extrah= (float)extra/60;
float faltah= (float)falta/60;
int H= ((extra)-(2/3*(falta)));
printf ("O funcion�rio acumulou %.2f horas extras e %.2f horas em faltas\n", extrah, faltah);
switch(H){
case 0 ... 599:
printf ("Ganhando R$100 em pr�mio\n");
break;
case 600 ... 1200:
printf ("Ganhando R$200 em pr�mio\n");
break;
case 1201 ... 1800:
printf ("Ganhando R$300 em pr�mio\n");
break;
case 1801 ... 2400:
printf ("Ganhando R$400 em pr�mio\n");
break;
default:
printf ("Ganhando R$500 em pr�mio\n");
}
}
