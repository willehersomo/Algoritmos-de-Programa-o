#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void main ()
{
   setlocale (LC_ALL, "");
    int palpite, tentativa=0, x;
    int limite=6;
    int yay=0;

    srand(time(NULL));

    x=rand()%100+1;

    printf ("Adivinhe um número entre 1 e 100\n");


    while (tentativa<limite && !yay)
    {
        printf ("%d-", tentativa+1);
        scanf ("%d", &palpite);

        if (palpite==x)
        {
            yay=1;
        }
        else
        {
            int dist=palpite-tentativa;
            if (dist<=10||dist>=-10)
            {
                printf ("quente!\n");
            }
            else
            {
                printf ("frio\n");
            }
            if (palpite<x)
            {
                printf ("Maior!\n");
            }
            else
            {
                printf ("Menor!\n");
            }
            tentativa++;
        }
    }
    if (yay)
    {
        printf ("Yay!!!!!!\n");

    }
    else
    {
        printf ("No Yay :(\n");
        printf ("Era %d", x);

    }
}


//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 21/06 às 15:27


