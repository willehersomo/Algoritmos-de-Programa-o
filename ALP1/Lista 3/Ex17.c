#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
    int X, Y;
    setlocale (LC_ALL, "");
    printf ("Insira a localiza��o de X: ");
    scanf ("%d", &X);
    printf ("Insira a localiza��o de Y: ");
    scanf ("%d", &Y);
    if (X==0 && Y==0)
    {
        printf ("O ponto est� na origem!\n");
    }
    if (Y==0 && X!=0)
    {
        printf ("O ponto est� sobre o eixo X\n");
    }
    if (X==0 && Y!=0)
    {
        printf ("O ponto est� sobre o eixo Y\n");
    }
    if (X!=0 && Y!=0)
    {
        if (X>0 && Y>0)
        {
            printf("O ponto est� no primeiro quadrante\n");
        }
        else if (X<0 && Y>0)
        {
            printf("O ponto est� no segundo quadrante\n");
        }
        else if (X<0 && Y<0)
        {
            printf("O ponto est� no terceiro quadrante\n");
        }
        else if (X>0 && Y<0)
        {
            printf("O ponto est� no quarto quadrante\n");
        }
    }
}
