#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
char notas[40];
int absoluta[5] = {0};
float relativa[5] = {0.0};
int i;
int TNotas = 40;
srand(time(NULL));


    for (i = 0; i < 40; i++)
    {

        int indice = rand() % 5;



        notas[i] = 'A' + indice;

    }


    for (i = 0; i < TNotas; i++)
    {
        absoluta[notas[i] - 'A']++;
    }


    for (i = 0; i < 5; i++)
    {
        relativa[i] = (float)absoluta[i] / TNotas;
    }


    printf("Nota\tFrequencia Absoluta\tFrequencia Relativa\n");

    for (i = 0; i < 5; i++)
    {
        printf("%c\t%d\t\t\t%.2f\n", 'A' + i, absoluta[i], relativa[i]);
    }


}
//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 22/06 às 19:25
