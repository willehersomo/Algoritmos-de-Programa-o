#include <stdio.h>
#include <locale.h>
#define TF 8

void apresentar_situacao_disciplinas(int matriculas[])
{
    for (int i = 0; i < TF; i++)
    {
        printf("Disciplina %d: ", i + 1);
        if (matriculas[i] >= 40)
        {
            printf("Lotada\n");
        }
        else
        {
            printf("Há vagas\n");
        }
    }
}

void apresentar_media_matriculas(int matriculas[])
{
    int total = 0;
    for (int i = 0; i < TF; i++)
    {
        total += matriculas[i];
    }
    float media = (float)total / TF;
    printf("Média de matrículas nas disciplinas: %.2f\n", media);
}

void apresentar_total_matriculas(int matriculas[])
{
    int total = 0;
    for (int i = 0; i < TF; i++)
    {
        total += matriculas[i];
    }
    printf("Total de matrículas nas disciplinas: %d\n", total);
}

int main()
{
    setlocale (LC_ALL, "");
    int matriculas[TF];


    for (int i = 0; i < TF; i++)
    {
        printf("Digite a quantidade de alunos matriculados na disciplina %d: ", i + 1);
        scanf("%d", &matriculas[i]);
    }


    apresentar_situacao_disciplinas(matriculas);


    apresentar_media_matriculas(matriculas);


    apresentar_total_matriculas(matriculas);

    return 0;
}
