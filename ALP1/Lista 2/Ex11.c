#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
float X1, X2, Y1, Y2;
setlocale (LC_ALL, "");
printf ("Digite o ponto ao qual X1 está localizado em sua reta X: ");
scanf ("%f", &X1);
printf ("Digite o ponto ao qual X2 está localizado em sua reta X: ");
scanf ("%f", &X2);
printf ("Digite o ponto ao qual Y1 está localizado em sua reta Y: ");
scanf ("%f", &Y1);
printf ("Digite o ponto ao qual Y2 está localizado em sua reta Y: ");
scanf ("%f", &Y2);
float XALL= (X2-X1);
float YALL= (Y2-Y1);
float ALL= (pow(XALL, 2))+(pow(YALL, 2));
float dist= sqrt(ALL);
printf ("A distância entre os dois pontos A e B é: %.2f", dist);


}
