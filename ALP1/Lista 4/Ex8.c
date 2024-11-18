#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale (LC_ALL, "");
    int alunitos;
    printf ("Digite a quantidade de alunos na sala: ");
    scanf ("%d", &alunitos);
    float nota1[alunitos];
    float nota2[alunitos];
    int i, aprovados = 0, reprovados = 0;
    float tudo = 0.0;




    for (i = 0; i < alunitos; i++)
    {
        printf("Digite a nota do aluno %d no 1º bimestre: ", i + 1);
        scanf("%f", &nota1[i]);

        printf("Digite a nota do aluno %d no 2º bimestre: ", i + 1);
        scanf("%f", &nota1[i]);

        tudo += nota1[i] + nota2[i];
    }


    float mt = tudo / (alunitos * 2);


    for (i = 0; i < alunitos; i++)
    {
        float ma = (nota1[i] + nota2[i]) / 2;

        if (ma >= 6.0)
        {
            aprovados++;
        }
        else
        {
            reprovados++;
        }
    }


    float porcenapro = (float)aprovados / alunitos * 100;
    float percenrepro = (float)reprovados /alunitos * 100;


    printf("Resultados:\n");
    printf("Média da turma: %.2f\n", mt);
    printf("Total de aprovados: %d\n", aprovados);
    printf("Percentual de aprovados: %.2f%%\n", percenapro);
    printf("Total de reprovados: %d\n", reprovados);
    printf("Percentual de reprovados: %.2f%%\n", percenrepro);

}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 19/06 às 18:05.

