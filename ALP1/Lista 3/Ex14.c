#include <locale.h>
#include <stdio.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
float peso, altura;
printf ("Insira a altura do indivíduo: ");
scanf ("%f", &altura);
printf ("Insira o peso do indivíduo: ");
scanf ("%f", &peso);
float IMC= peso/pow(altura, 2);
if (IMC < 20) {
printf("O indivíduo está abaixo do peso\n");
}else if (IMC < 25) {
printf("O indivíduo está com peso normal\n");
} else if (IMC < 30) {
printf("O indivíduo está sobrepeso\n");
} else if (IMC < 40) {
printf("O indivíduo está com obesidade\n");
} else {
printf("O indivíduo está com obesidade mórbida\n");
}
}
