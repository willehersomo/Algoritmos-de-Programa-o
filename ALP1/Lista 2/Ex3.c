#include <stdio.h>
#include <locale.h>

void main()
{
float n1, n2, n3;
setlocale (LC_ALL, "");
printf ("Digite sua primeira nota(trabalho bimestral): ");
scanf ("%f", &n1);
printf ("Digite sua segunda nota(trabalho pr�tico): ");
scanf ("%f", &n2);
printf ("Digite sua terceira nota(Simulado): ");
scanf ("%f", &n3);
float media=((n1*6)+ (n2*2)+(n3*2))/10;
printf ("Sua m�dia final �: %.2f\n", media);
}
