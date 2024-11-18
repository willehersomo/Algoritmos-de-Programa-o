#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
int idade;
printf ("Insira a sua idade: ");
scanf ("%d", &idade);
if (idade>=18){
printf ("Você é de maior!\n");
}
else if (idade<18){
printf ("Você é de menor!\n");
}
}
