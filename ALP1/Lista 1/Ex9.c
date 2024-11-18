#include <stdio.h>
#include <locale.h>

void main ()
{
int dia, mes, diasperdidos;
setlocale (LC_ALL, "");
printf ("insira o dia de hoje(de 1 a 30)\n");
scanf ("%i", &dia);
printf ("de qual o mês (de 1 a 12)?\n");
scanf ("%i", &mes);
diasperdidos= dia+(mes*30);
printf ("Você desperdiçou %i dias desde o inicio do ano\n", diasperdidos);

}
