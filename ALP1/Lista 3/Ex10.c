#include <stdio.h>
#include <locale.h>
#include <math.h>

void main (){
setlocale (LC_ALL, "");
int n1, n2;
printf ("Insira o primeiro n�mero: ");
scanf ("%d", &n1);
printf ("Insira o segundo n�mero: ");
scanf ("%d", &n2);
if (n1>n2){
int x= n1;
n1=n2;
n2=x;
}
printf ("Em ordem, os n�meros s�o: %d e %d\n", n1, n2);
}
