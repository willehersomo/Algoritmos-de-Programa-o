#include <stdio.h>
#include <locale.h>

void main ()
{
int eletronico, pessoas, metros;
setlocale (LC_ALL,"");
printf ("Digite a quantidade de m� do ambiente: ");
scanf ("%i", &metros);
printf ("Digite a quantidade de equipamentos ligados: ");
scanf ("%i", &eletronico);
printf ("Digite a quantidade de pessoas dentro do ambiente: ");
scanf ("%i", &pessoas);
int ar= (metros*500)+(eletronico*300)+(pessoas*600);
printf ("A capacidade min�ma para seu ar refrigerar o ambiente ser� de %i BTUs\n", ar);

}
