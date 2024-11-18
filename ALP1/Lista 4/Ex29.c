#include <stdio.h>
#include <locale.h>

void main ()
{
    setlocale (LC_ALL, "");
    int valor [10]= {0};
    int i, necessario, casos=0;
    for (i=0; i<10; i++)
    {
        printf ("Insira valor positivo %d: ", i+1);
        scanf("%d", &valor[i]);
        while (valor[i]<=0)
        {
            printf ("É positivo! tente novamente ", i+1);
            scanf ("%d", &valor[i]);
        }
    }
    for (i=0; i<9; i++)
    {
        printf ("-%d", valor [i]);

    }
    printf ("\n");
    printf("Insira o valor nacessário dentro do vetor: ");
    scanf ("%d", &necessario);

    for (i=0; i<9; i++)
    {
        if (valor[i]==necessario)
        {
            casos++;

        }
    }
    printf ("Quantidade de casos: %d\n", casos);


}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 21/06 às 16:54

