#include <locale.h>
#include <math.h>
#include <stdio.h>

void main ()
{
setlocale(LC_ALL, "");
int idade;
printf ("Digite a idade: ");
scanf ("%d", &idade);
switch (idade){
case 0 ... 4:
printf ("INDISPON�VEL");
break;
case 5 ... 7:
printf ("Sua categoria � a INFANTIL A\n");
break;
case 8 ... 10:
printf ("Sua categoria � a INFANTIL B\n");
break;
case 11 ... 13:
printf ("Sua categoria � a JUVENIL A\n");
break;
case 14 ... 17:
printf ("Sua categoria � a JUVENIL B\n");
break;
default:
printf ("Sua categoria � a ADULTO\n");
break;
}
}
