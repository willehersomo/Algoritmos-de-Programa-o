#include <locale.h>
#include <stdio.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
int num;
printf("Insira o n�mero: ");
scanf("%d", &num);
if (num == 0) {
printf("VALOR NULO\n");
} else if (num % 2 == 0) {
printf("Este n�mero � par!\n");
} else {
printf("Este n�mero � �mpar!\n");
}
}
