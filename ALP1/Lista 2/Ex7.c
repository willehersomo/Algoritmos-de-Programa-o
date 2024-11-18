#include <stdio.h>
#include <locale.h>

void main ()
{
float dist, pedagios, horamotorista, VM, KMvalor;
setlocale (LC_ALL, "");
printf ("Digite a distância total percorrida em KM: ");
scanf ("%f", &dist);
printf ("Digite o valor total dos pedágios: ");
scanf ("%f", &pedagios);
printf ("Digite o valor da hora do motorista por KM percorrido: ");
scanf ("%f", &horamotorista);
printf ("Declare a velocidade média do veículo: ");
scanf ("%f", &VM);
printf ("Declare o valor a ser cobrado por km percorrido: ");
scanf ("%f", &KMvalor);
float frete= (KMvalor*dist)+(pedagios)+((dist/VM)*horamotorista);
printf ("O valor do frete será R$%.2f\n", frete);

}
