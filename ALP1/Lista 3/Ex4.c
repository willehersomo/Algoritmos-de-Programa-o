#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale(LC_ALL, "");
float altura;
int sexo;
printf ("Digite sua altura em metros (UTILIZE V�RGULA PARA SEPARA��O DE DECIMAIS): \n");
scanf ("%f", &altura);
printf("Especifique seu sexo biol�gico:\nSe homem, digite 1\nSe mulher, digite 2\n");
scanf ("%d", &sexo);
if (sexo==1){
float ideal= (72.7*altura)-58;
printf ("Seu peso ideal �: %.2fKG\n", ideal);
}
else if (sexo==2) {
float ideal= (62.1*altura)-44.7;
printf ("Seu peso ideal �: %.2fKG\n", ideal);
}
else {
printf ("Inv�lido");
}
}
