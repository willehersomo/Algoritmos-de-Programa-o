#include <stdio.h>
#include <locale.h>

void main ()
{
int blusaqnt, noveloqnt;
float novelopreco, blusapreco;
setlocale (LC_ALL,"");
printf ("Quantas blusas voc� produz no dia?\n");
scanf ("%i", &blusaqnt);
printf ("Gastando quantos novelos\n");
scanf ("%i", &noveloqnt);
printf ("e qual o pre�o da unidade do novelo?\n");
scanf("%f", &novelopreco);
float novelo1blusa= (float) noveloqnt/blusaqnt;
printf ("� gasto %.2f novelos por blusa\n", novelo1blusa);
float novelospreco= noveloqnt*novelopreco;
blusapreco= novelospreco/blusaqnt;
printf ("O pre�o de uma �nica blusa � R$%.2f\n", blusapreco);



}
