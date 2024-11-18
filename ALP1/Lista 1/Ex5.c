#include <stdio.h>
#include <locale.h>

void main ()
{
    float nota1, nota2, nota3, media;
    setlocale (LC_ALL, "");
    printf("qual foi sua primeira nota?\n");
    scanf ("%f", &nota1);
    printf("e a segunda nota?\n");
    scanf ("%f", &nota2);
    printf ("e a terceira?\n");
    scanf ("%f", &nota3);
    media= (nota1+nota2+nota3)/3;
    printf ("Sua média foi de %.2f\n", media);

}
