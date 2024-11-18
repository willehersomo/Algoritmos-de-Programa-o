#include <locale.h>
#include <stdio.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
int num;
printf("Insira o número: ");
scanf("%d", &num);
if (num == 0) {
printf("VALOR NULO\n");
} else if (num % 2 == 0) {
printf("Este número é par!\n");
} else {
printf("Este número é ímpar!\n");
}
}
