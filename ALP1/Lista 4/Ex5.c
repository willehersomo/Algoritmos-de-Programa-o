#include <stdio.h>
#include <math.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "");
    int i, t=7;
    float v=0, h=0, g=10;
    for (i=1; i<=t; i++)
    {
        v=g*i;
        h=0.5*g*pow(i,2);
        printf ("Segundo %d: Velocidade=%.2f e Distância= %.2f\n", i, v, h);
    }
}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 19/06 às 16:55.
