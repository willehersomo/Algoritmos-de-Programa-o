/*1 -Fazer um programa em Linguagem C capaz de ler a quantidade de alunos matriculados nas 8 disciplinas do segundo semestre e apresentar:
        ◦ A situação de cada disciplina:
"Lotada" - para as disciplinas que tiverem número de inscritos maior ou igual a 40;
"Há vagas" para as disciplinas menores que 40 alunos
        ◦ Média de matrículas nas disciplinas;
        ◦ Total de matrículas nessas disciplinas;*/

#include<stdio.h>
#define T 8

void ler(int mat[])
{
    int i;
    for(i=0; i<T; i++)
    {
        printf("Digite a quantidade de alunos matriculados: \n");
        scanf("%d", &mat[i]);
    }
}

void calcular_matriculados(int matriculados[])
{
    int i;
    for(i=0; i<T; i++)
    {
        if(matriculados[i] >=40 )
        {
            printf("Turma lotada!\n", i+1);
        }
        else
        {
            printf("Ainda ha vagas na turma\n", i+1);
        }
    }
}

float calcular_media (int total)
{
    float media;
    media=(float)total/T;
    return media;
}

int apresentar_matricula(int matriculados[])
{

    int i, total = 0;
    for(i=0; i<T; i++)
    {
        total+= matriculados[i];
    }
    return total;

}
#include<stdio.h>
void main()
{
    int matriculados[T], i, total=0 ;
    float media;
    ler(matriculados);
    calcular_matriculados(matriculados);
    total = apresentar_matricula(matriculados);
    printf("A soma de alunos matriculados e de: %d\n", total);
    media = calcular_media(total);
    printf("A media de matriculados e de : %.2f\n", media);

}
