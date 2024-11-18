#include <stdio.h>
#include <locale.h>

void main ()
{
int blusaqnt, noveloqnt;
float novelopreco, blusapreco;
setlocale (LC_ALL,"");
printf ("Quantas blusas você produz no dia?\n");
scanf ("%i", &blusaqnt);
printf ("Gastando quantos novelos\n");
scanf ("%i", &noveloqnt);
printf ("e qual o preço da unidade do novelo?\n");
scanf("%f", &novelopreco);
float novelo1blusa= (float) noveloqnt/blusaqnt;
printf ("É gasto %.2f novelos por blusa\n", novelo1blusa);
float novelospreco= noveloqnt*novelopreco;
blusapreco= novelospreco/blusaqnt;
printf ("O preço de uma única blusa é R$%.2f\n", blusapreco);



}
