#include <locale.h>
#include <stdio.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
float peso, altura;
printf ("Insira a altura do indiv�duo: ");
scanf ("%f", &altura);
printf ("Insira o peso do indiv�duo: ");
scanf ("%f", &peso);
float IMC= peso/pow(altura, 2);
if (IMC < 20) {
printf("O indiv�duo est� abaixo do peso\n");
}else if (IMC < 25) {
printf("O indiv�duo est� com peso normal\n");
} else if (IMC < 30) {
printf("O indiv�duo est� sobrepeso\n");
} else if (IMC < 40) {
printf("O indiv�duo est� com obesidade\n");
} else {
printf("O indiv�duo est� com obesidade m�rbida\n");
}
}
