#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale(LC_ALL,"");
int extra, falta;
printf ("Digite o número de minutos extras do funcionário: ");
scanf ("%d", &extra);
printf ("Digite o número de minutos referentes a faltas do funcionário: ");
scanf ("%d", &falta);
float extrah= (float)extra/60;
float faltah= (float)falta/60;
int H= ((extra)-(2/3*(falta)));
printf ("O funcionário acumulou %.2f horas extras e %.2f horas em faltas\n", extrah, faltah);
switch(H){
case 0 ... 599:
printf ("Ganhando R$100 em prêmio\n");
break;
case 600 ... 1200:
printf ("Ganhando R$200 em prêmio\n");
break;
case 1201 ... 1800:
printf ("Ganhando R$300 em prêmio\n");
break;
case 1801 ... 2400:
printf ("Ganhando R$400 em prêmio\n");
break;
default:
printf ("Ganhando R$500 em prêmio\n");
}
}
