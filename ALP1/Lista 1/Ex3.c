#include <stdio.h>
#include <locale.h>

void main ()
{
    float raio, area, pesopizza;
    printf ("Qual o raio da sua pizza?\n");
    scanf ("%f", &raio);
    setlocale (LC_ALL, "");
    area=(raio*raio)*3.14;
    pesopizza = area*10;
    printf ("A �rea da sua pizza � de %.2f cm�, pesando %.2f gramas\n", area, pesopizza );
}
