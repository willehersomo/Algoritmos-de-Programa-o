#include <locale.h>
#include <stdio.h>

void main ()
{
    setlocale (LC_ALL, "");
    int integrais=0, meias=0, criancas=0, idosos=0;
    float arrecadado=0.0;
    int pessoas;
    printf ("Insira a quantidade de pessoas que foram ao cinema: ");
    scanf ("%d", &pessoas);
    for (int i=1; i <=pessoas; i++)
    {
        int idade;
        printf ("Insira a idadde do meliante: ", i);
        scanf("%d", &idade);
        if (idade<12||idade>59)
        {
            meias++;
            if (idade<12)
            {
                criancas++;

            }
            if(idade>59)
            {
                idosos++;

            }
        }
        if (idade>=12&&idade<=59)
        {
            integrais++;
        }
        arrecadado=(meias*9.00)+(integrais*18.00);
    }
    printf ("Entradas integrais: %d\n", integrais);
    printf ("Entradas meias: %d\n", meias);
    printf ("Crianças na sessão: %d\n", criancas);
    printf ("Idosos na sessão: %d\n", idosos);
    printf ("Total arrecadado: R$%.2f\n", arrecadado);

}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, primeiro termo, no dia 19/06 às 19:13


