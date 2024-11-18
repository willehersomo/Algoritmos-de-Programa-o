#include <stdio.h>
#include <locale.h>
#define TF 10

struct disciplinas
{
    int qnt_alunos;
    int qnt_materias[TF];
    float nota_1[TF][TF];
    float nota_2[TF][TF];
    float frequencia[TF][TF];
    char sigla[TF][5];
    char disciplina[TF][100];
    char curso[TF][100];
    char nomes[TF][100];
};

void abrir_arquivo_disciplina(FILE **arquivo)
{
    *arquivo = fopen("../disciplinas-exerc1.txt", "r");
}

void fechar_arquivo_disciplina(FILE *arquivo)
{
    fclose(arquivo);
}

void ler_informacoes(FILE *arquivo, struct disciplinas tab_disciplinas[])
{
    fscanf(arquivo, "%d", &tab_disciplinas[0].qnt_alunos);

    for (int i = 0; i < tab_disciplinas[0].qnt_alunos; i++)
    {
        fscanf(arquivo, " %[^\n] %[^\n] %d", tab_disciplinas[i].nomes[0], tab_disciplinas[i].curso[0], &tab_disciplinas[i].qnt_materias[0]);

        for (int j = 0; j < tab_disciplinas[i].qnt_materias[0]; j++)
        {
            fscanf(arquivo, " %[^\n] %s %f %f %f", tab_disciplinas[i].disciplina[j], tab_disciplinas[i].sigla[j],
                   &tab_disciplinas[i].nota_1[j][0], &tab_disciplinas[i].nota_2[j][0], &tab_disciplinas[i].frequencia[j][0]);
        }
    }
}

void apresentar_informacoes(struct disciplinas tab_disciplinas[])
{
    printf("Quantidade de alunos: %d\n", tab_disciplinas[0].qnt_alunos);
    printf ("---------------------------------------\n");

    for (int i = 0; i < tab_disciplinas[0].qnt_alunos; i++)
    {
        printf("Nome do aluno: %s\nNome do curso: %s\n", tab_disciplinas[i].nomes[0], tab_disciplinas[i].curso[0]);
        printf("Matérias matriculadas: %d\n", tab_disciplinas[i].qnt_materias[0]);
        printf ("\n");
        for (int j = 0; j < tab_disciplinas[i].qnt_materias[0]; j++)
        {

            printf("Disciplina: %s\nSigla: %.5s\nNota 1. Bim: %.2f\nNota 2. Bim: %.2f\nFrequência: %.2f\n\n",
                   tab_disciplinas[i].disciplina[j], tab_disciplinas[i].sigla[j], tab_disciplinas[i].nota_1[j][0],
                   tab_disciplinas[i].nota_2[j][0], tab_disciplinas[i].frequencia[j][0]);

        }
        printf ("---------------------------------------\n");
    }
}

void processar_informacoes(FILE *arquivo, struct disciplinas tab_disciplinas[])
{
    abrir_arquivo_disciplina(&arquivo);
    if (arquivo == NULL)
    {
        printf("Falha ao processar\n");
    }
    else
    {
        ler_informacoes(arquivo, tab_disciplinas);
        apresentar_informacoes(tab_disciplinas);
    }
    fechar_arquivo_disciplina(arquivo);
}

int main()
{
    setlocale(LC_ALL, "english");//devido ao mesmo caso do exercicio de produtos
    FILE *arquivo;
    struct disciplinas tab_disciplinas[TF];
    processar_informacoes(arquivo, tab_disciplinas);
    return 0;
}
