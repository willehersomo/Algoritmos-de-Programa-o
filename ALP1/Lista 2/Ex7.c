#include <stdio.h>
#include <locale.h>

void main ()
{
float dist, pedagios, horamotorista, VM, KMvalor;
setlocale (LC_ALL, "");
printf ("Digite a dist�ncia total percorrida em KM: ");
scanf ("%f", &dist);
printf ("Digite o valor total dos ped�gios: ");
scanf ("%f", &pedagios);
printf ("Digite o valor da hora do motorista por KM percorrido: ");
scanf ("%f", &horamotorista);
printf ("Declare a velocidade m�dia do ve�culo: ");
scanf ("%f", &VM);
printf ("Declare o valor a ser cobrado por km percorrido: ");
scanf ("%f", &KMvalor);
float frete= (KMvalor*dist)+(pedagios)+((dist/VM)*horamotorista);
printf ("O valor do frete ser� R$%.2f\n", frete);

}
