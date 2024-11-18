#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void main ()


{
    setlocale(LC_ALL, "");
    int n1, n2;
    int i;


    printf ("Digite o número 1\n");
    scanf ("%d", &n1);
    printf ("Digite o número 1\n");
    scanf ("%d", &n2);

    srand(time(NULL));
    int s1, s2;


    while((s1!=n1||s2!=n2)&&(s1!=n2||s2!=n1))
    {
        i++;
        s1=rand()%75+1;
        s2=rand()%75+1;
        printf ("\n%d e %d\n", s1, s2);


    }
       printf ("\nNúmero de sorteios: %d\n", i);

}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 21/06 às 16:54


