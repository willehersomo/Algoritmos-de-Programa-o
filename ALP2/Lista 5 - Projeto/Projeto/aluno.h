#include <stdio.h>


typedef struct
{
    int prontuario;
    char nome[50];
    char curso[4];
} alunos;

//----------------------------------------------------------------------
//exercicio 1 - inicio
alunos validar_prontuario(int prontuario_digitado)
{
    alunos aluno;
    int aluno_encontrado = 0;

    FILE *arquivo;
    arquivo = fopen("alunos1.dat", "rb");

    while (fread(&aluno, sizeof(alunos), 1, arquivo) == 1 && !aluno_encontrado)
    {
        if (prontuario_digitado < 0 || (aluno.prontuario == prontuario_digitado))
        {
            aluno_encontrado = 1;
        }
    }

    fclose(arquivo);

    if (aluno_encontrado)
    {
        printf("Prontuário existente ou dado menor que 0\n");
        aluno.prontuario = -1;
    }

    return aluno;
}

alunos preencher_dados_aluno()
{
    alunos inserir;

    printf("Cadastro de alunos\n");
    printf("------------------------------\n");

    printf("Prontuário do aluno: \n");
    scanf("%d", &inserir.prontuario);

    alunos aluno_existente = validar_prontuario(inserir.prontuario);

    if (aluno_existente.prontuario != -1)
    {
        printf("Nome do aluno: \n");
        scanf(" %49[^\n]", inserir.nome);
        printf("Curso do aluno (sigla de 3 caracteres): \n");
        scanf(" %3[^\n]", inserir.curso);
    }

    return inserir;
}

void incluir_dados_alunos(alunos inserir)
{
    FILE *arquivo;
    alunos aluno;
    int aluno_encontrado = 0;

    arquivo = fopen("alunos1.dat", "rb+");

    if (arquivo == NULL)
    {
        arquivo = fopen("alunos1.dat", "wb");
    }

    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
    }
    else
    {
        while (fread(&aluno, sizeof(alunos), 1, arquivo) == 1)
        {
            if (aluno.prontuario == inserir.prontuario)
            {
                aluno_encontrado = 1;
            }
        }

        if (!aluno_encontrado && inserir.prontuario >= 0)
        {
            fwrite(&inserir, sizeof(alunos), 1, arquivo);
            printf ("Aluno cadastrado\n");
        }

        fclose(arquivo);
    }
}
//exercicio 1 - final
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//exercicio 3 - inicio
void apresentar_lista_alunos()
{
    FILE *arquivo;
    alunos aluno;

    arquivo = fopen("alunos1.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de alunos.\n");
    }
    else
    {
        printf("Dados dos alunos:\n");

        while (fread(&aluno, sizeof(alunos), 1, arquivo) == 1)
        {
            printf("Prontuário: %d\n", aluno.prontuario);
            printf("Nome: %s\n", aluno.nome);
            printf("Curso: %s\n", aluno.curso);
            printf("------------------------------\n");
        }

        fclose(arquivo);
    }
}
//exercicio 3 - final
//----------------------------------------------------------------------

