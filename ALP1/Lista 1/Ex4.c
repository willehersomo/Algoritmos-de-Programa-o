#include <stdio.h>
#include <locale.h>

void main ()
{
int vacalo, ferraduras;
float tempo;
setlocale (LC_ALL, "");
printf ("Quantos cavalos voc� tem?\n");
scanf ("%i", &vacalo);
ferraduras= vacalo*4;
tempo= (float)ferraduras*15;
printf ("sera necess�rio %i ferraduras para equipar seus cavalos, podendo demorar cerca de %.2f minutos para trocar todas as ferraduras\n", ferraduras, tempo );
}
