#include <stdio.h>
#include <locale.h>

void main ()
{
int nomorteano, nomortemes, nomortedia, dia, mes, ano;
setlocale (LC_ALL, "");
printf ("Que dia é hoje (de 1 a 30)?\n");
scanf ("%i", &dia);
printf ("de que mês (1 a 12)?\n");
scanf ("%i", &mes);
printf ("de que ano?\n");
scanf ("%i", &ano);
int diaspassados= (ano*365)+(mes*30)+dia;
printf ("Qual foi o dia do último aicdente?\n");
scanf ("%i", &nomortedia);
printf ("referente ao qual mês(de 1 a 12)?\n");
scanf ("%i", &nomortedia);
printf ("de qual ano?\n");
scanf ("%i", &nomorteano);
int diasnomorte=(nomorteano*365)+(nomortemes*30)+nomortedia;
int notragedia= diaspassados-diasnomorte;
printf ("Estamos há %i dias sem qualquer incidente ou morte dentro da empresa", notragedia);

}
