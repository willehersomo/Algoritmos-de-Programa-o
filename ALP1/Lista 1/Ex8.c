#include <stdio.h>
#include <locale.h>

void main ()
{
int anos, meses, dias;
setlocale (LC_ALL, "");
printf ("Quantos anos voc� tem?\n");
scanf ("%i", &anos);
meses= anos*12;
printf ("Voc� j� desperdi�ou %i meses da sua vida\n", meses);
dias= anos*365;
printf ("Sendo %i dias\n", dias);
}
