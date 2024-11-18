#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
float n1, n2, n3;
printf ("Insira a primeira nota: ");
scanf ("%f", &n1);
printf ("Insira a segunda nota: ");
scanf ("%f", &n2);
printf ("Insira a terceira nota: ");
scanf ("%f", &n3);
float media= (n1+n2+n3)/3;
printf ("Sua média é: %.2f\n", media);
if (media>=6){
printf ("APROVADO\n");
}
else if (media<6){
printf ("REPROVADO");
}
}
