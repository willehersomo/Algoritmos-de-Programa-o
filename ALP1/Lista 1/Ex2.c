#include <stdio.h>
#include <locale.h>

void main ()
{

    int vacalo, ferraduras;
    setlocale (LC_ALL, "");
    printf ("Quantos cavalos você comprou?\n");
    scanf ("%d", &vacalo);
    ferraduras = vacalo*4;
    printf ("Você vai precisar de %d ferraduras\n", ferraduras);
}
