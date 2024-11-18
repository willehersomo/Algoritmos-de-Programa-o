#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
    int X, Y;
    setlocale (LC_ALL, "");
    printf ("Insira a localização de X: ");
    scanf ("%d", &X);
    printf ("Insira a localização de Y: ");
    scanf ("%d", &Y);
    if (X==0 && Y==0)
    {
        printf ("O ponto está na origem!\n");
    }
    if (Y==0 && X!=0)
    {
        printf ("O ponto está sobre o eixo X\n");
    }
    if (X==0 && Y!=0)
    {
        printf ("O ponto está sobre o eixo Y\n");
    }
    if (X!=0 && Y!=0)
    {
        if (X>0 && Y>0)
        {
            printf("O ponto está no primeiro quadrante\n");
        }
        else if (X<0 && Y>0)
        {
            printf("O ponto está no segundo quadrante\n");
        }
        else if (X<0 && Y<0)
        {
            printf("O ponto está no terceiro quadrante\n");
        }
        else if (X>0 && Y<0)
        {
            printf("O ponto está no quarto quadrante\n");
        }
    }
}
