#include <stdio.h>
#include <string.h>

#define TF2 20

typedef struct
{
    int dia, mes;
    int dia_dev, mes_dev;
    int livro_tombo;
    int aluno_prontuario;
    char situacao;
    char curso;
} emprestimos;

//----------------------------------------------------------------------
// exercicio 5 - inicio
int validar_dia()
{
    int inteiro;
    int controle = 0;
    do
    {
        scanf("%d", &inteiro);
        if (inteiro < 0 || inteiro > 30)
        {
            printf("Dia entre 1 a 30!\n");
            controle = 0;
        }
        else
        {
            controle = 1;
        }
    } while (controle == 0);
    return inteiro;
}

int validar_mes()
{
    int inteiro;
    int controle = 0;
    do
    {
        scanf("%d", &inteiro);
        if (inteiro < 0 || inteiro > 12)
        {
            printf("Mês entre 1 a 12!\n");
            controle = 0;
        }
        else
        {
            controle = 1;
        }
    } while (controle == 0);
    return inteiro;
}

emprestimos validar_aluno_cadastro(emprestimos inserir, int ativo[])
{
    int aluno_encontrado = 0;
    int entrada;
    alunos aluno;

    FILE *arquivo;
    arquivo = fopen("alunos1.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de alunos.\n");
    }
    else
    {

        printf("Digite o prontuário do aluno: ");
        scanf("%d", &entrada);

        while (fread(&aluno, sizeof(alunos), 1, arquivo) == 1)
        {
            if (aluno.prontuario == entrada)
            {
                inserir.aluno_prontuario = entrada;
                aluno_encontrado = 1;
            }
        }

        if (!aluno_encontrado)
        {
            printf("Aluno não encontrado.\n");
        }
        else
        {
            ativo[0] += 1;
        }
    }

    fclose(arquivo);
    return inserir;
}

void atualizar_situacao_livro(int tombo)
{
    FILE *arquivo;
    arquivo = fopen("livros.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de livros.\n");
    }
    else
    {

        livros livro;
        int controle = 0;

        do
        {
            long int posicao_anterior = ftell(arquivo);
            int leitura = fread(&livro, sizeof(livros), 1, arquivo);

            if (leitura == 1)
            {
                if (livro.tombo == tombo)
                {
                    livro.situacao = 'E';

                    fseek(arquivo, posicao_anterior, SEEK_SET);
                    fwrite(&livro, sizeof(livros), 1, arquivo);
                    fseek(arquivo, 0, SEEK_END);

                    controle = 1;
                }
            }
            else
            {
                controle = 1;
            }
        } while (controle == 0);
    }
    fclose(arquivo);
}

emprestimos validar_tombo_emprestimo(emprestimos inserir, int ativo[])
{
    int entrada;
    int tombo_encontrado = 0;
    int livro_emprestado = 0;
    livros livro;

    FILE *arquivo;
    arquivo = fopen("livros.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de livros.\n");
    }
    else
    {
        printf("Digite o tombo do livro: ");
        scanf("%d", &entrada);

        while (fread(&livro, sizeof(livros), 1, arquivo) == 1)
        {
            if (livro.tombo == entrada)
            {
                if (livro.situacao == 'D')
                {
                    inserir.livro_tombo = entrada;
                    atualizar_situacao_livro(entrada);
                    inserir.situacao = 'P';
                    tombo_encontrado = 1;
                    livro_emprestado = 1;
                }
                else
                {
                    tombo_encontrado = 1;
                    livro_emprestado = 0;
                }
            }
        }

        if (tombo_encontrado)

        {
            if (!livro_emprestado)
            {
                printf("Livro já emprestado.\n");
            }
        }
        else
        {
            printf("Tombo não encontrado.\n");
        }

        if (livro_emprestado && tombo_encontrado)
        {
            ativo[0] += 1;
        }
    }

    fclose(arquivo);
    return inserir;
}

int calcular_dia_devolucao(emprestimos inserir)
{
    int dia_dev = inserir.dia + 7;

    if (dia_dev > 30)
    {
        dia_dev = dia_dev - 30;
    }

    return dia_dev;
}

int calcular_mes_devolucao(emprestimos inserir)
{
    int mes_dev = inserir.mes;

    if (inserir.dia + 7 > 30)
    {
        mes_dev = inserir.mes + 1;

        if (mes_dev > 12)
        {
            mes_dev = mes_dev - 12;
        }
    }

    return mes_dev;
}

emprestimos preencher_dados_emprestimos(int ativo[])
{
    emprestimos inserir;

    printf("Cadastro de empréstimos: \n");
    printf("Insira a data do empréstimo: \n");

    printf("Dia: ");
    inserir.dia = validar_dia();
    printf("Mês: ");
    inserir.mes = validar_mes();

    inserir = validar_aluno_cadastro(inserir, ativo);

    if (ativo[0] == 1)
    {
        inserir = validar_tombo_emprestimo(inserir, ativo);

        if (ativo[0] == 2)
        {
            inserir.dia_dev = calcular_dia_devolucao(inserir);
            inserir.mes_dev = calcular_mes_devolucao(inserir);
        }
        else
        {
            ativo[0] = 0;
        }
    }

    return inserir;
}

void incluir_dados_emprestimos(emprestimos inserir, int ativo[])
{
    FILE *arquivo;
    arquivo = fopen("emprestimos.dat", "ab");

    if (arquivo == NULL)
    {
        arquivo = fopen("emprestimos.dat", "wb");
    }

    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
    }
    else
    {
        if (ativo[0] == 2)
        {
            fwrite(&inserir, sizeof(emprestimos), 1, arquivo);
            printf("Emprestimo realizado\n");
            ativo[0] = 0;
        }
        fclose(arquivo);
    }
}
// exercicio 5 final
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// exercicio 6 - inicio
emprestimos validar_aluno_pesquisa()
{
    emprestimos pesquisar;
    int aluno_encontrado = 0;
    int entrada;
    alunos aluno;

    FILE *arquivo;
    arquivo = fopen("alunos1.dat", "rb");

    printf("Digite o prontuário do aluno: ");
    scanf("%d", &entrada);

    while (fread(&aluno, sizeof(alunos), 1, arquivo) == 1)
    {
        if (aluno.prontuario == entrada)
        {
            pesquisar.aluno_prontuario = entrada;
            aluno_encontrado = 1;
        }
    }

    if (!aluno_encontrado)
    {
        pesquisar.aluno_prontuario = -1;
    }

    fclose(arquivo);
    return pesquisar;
}

void apresentar_lista_emprestimos_aluno()
{
    FILE *arquivo;
    emprestimos pesquisar;

    pesquisar = validar_aluno_pesquisa();

    if (pesquisar.aluno_prontuario == -1)
    {
        printf("Aluno não encontrado.\n");
    }
    else
    {
        arquivo = fopen("emprestimos.dat", "rb");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo de empréstimos.\n");
        }
        else
        {
            emprestimos temp;
            int emprestimos_encontrados = 0;
            while (fread(&temp, sizeof(emprestimos), 1, arquivo) == 1)
            {
                if (temp.aluno_prontuario == pesquisar.aluno_prontuario)
                {
                    emprestimos_encontrados = 1;
                    printf("Lista de empréstimos do aluno %d: \n", temp.aluno_prontuario);
                    printf("Data de empréstimo: %d/%d\n", temp.dia, temp.mes);
                    printf("Tombo: %d\n", temp.livro_tombo);
                    printf("Situação: %c\n", temp.situacao);
                    printf("Data de devolução:%d/%d: \n", temp.dia_dev, temp.mes_dev);
                    printf("--------------------------\n");
                }
            }
            if (!emprestimos_encontrados)
            {
                printf("Não foram encontrados empréstimos para o aluno %d.\n", pesquisar.aluno_prontuario);
            }
        }
        fclose(arquivo);
    }
}

// exercicio 6 - final

//----------------------------------------------------------------------
//----------------------------------------------------------------------
// exercicio 7 - inicio

void listar_cursos(char cursos[TF2][4])
{
    FILE *arquivo;
    alunos l;
    int i = 0;
    int curso = 0;

    arquivo = fopen("alunos1.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Arquivo não encontrado\n");
    }
    else
    {
        printf("Cursos: \n");

        while (fread(&l, sizeof(alunos), 1, arquivo) == 1)
        {
            int controle = 0;
            for (int j = 0; j < curso; j++)
            {
                if (strcmp(l.curso, cursos[j]) == 0)
                {
                    controle = 1;
                }
            }

            if (!controle)
            {
                printf("%d - %s\n", i, l.curso);
                strcpy(cursos[curso], l.curso);
                curso++;
                i++;
            }
        }

        fclose(arquivo);
    }
}

int contar_cursos(char cursos[TF2][4])
{
    FILE *arquivo;
    alunos l;
    int i = 0;
    int cursos_encontrados = 0;

    arquivo = fopen("alunos1.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Arquivo não encontrado\n");
    }
    else
    {
        while (fread(&l, sizeof(alunos), 1, arquivo) == 1)
        {
            int controle = 0;
            for (int j = 0; j < cursos_encontrados; j++)
            {
                if (strcmp(l.curso, cursos[j]) == 0)
                {
                    controle = 1;
                }
            }

            if (!controle)
            {
                strcpy(cursos[cursos_encontrados], l.curso);
                cursos_encontrados++;
                i++;
            }
        }

        fclose(arquivo);
        return i;
    }
}


void atualizar_quantidade_emprestimos_curso(int quantidade_emprestimos[], char cursos[TF2][4], int curso)
{
    FILE *arquivo;
    emprestimos e;
    alunos a;
    int aluno_encontrado = 0;

    arquivo = fopen("emprestimos.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Arquivo não encontrado\n");
    }
    else
    {
        while (fread(&e, sizeof(emprestimos), 1, arquivo) == 1)
        {
            FILE *aluno_arquivo = fopen("alunos1.dat", "rb");
            aluno_encontrado = 0;

            while (fread(&a, sizeof(alunos), 1, aluno_arquivo) == 1)
            {

                if (a.prontuario == e.aluno_prontuario)
                {
                    if (strcmp(a.curso, cursos[curso]) == 0)
                    {
                        quantidade_emprestimos[curso]++;
                    }
                    aluno_encontrado = 1;
                }
            }
            fclose(aluno_arquivo);
            if (!aluno_encontrado)
            {
                printf("Aluno não encontrado\n");
            }
        }
        fclose(arquivo);
    }
}



void apresentar_quantidade_emprestimos_curso(int quantidade_emprestimos[])
{
    int opcao;
    char cursos[TF2][4];
    int tl=contar_cursos(cursos);
    listar_cursos(cursos);

    printf("Digite o numero correspondente ao curso: ");
    scanf("%d", &opcao);

    if (opcao >= 0 && opcao < tl)
    {
        quantidade_emprestimos[opcao] = 0;
        atualizar_quantidade_emprestimos_curso(quantidade_emprestimos, cursos, opcao);
        printf("A quantidade de empréstimos de livros para o curso %s é: %d\n", cursos[opcao], quantidade_emprestimos[opcao]);
    }
    else
    {
        printf("Opcao invalida.\n");
    }
}
// exercico 7 final
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// exercicio 9 - inicio
int preencher_dia_atual()
{
    int dia;
    printf("Dia atual: ");
    dia = validar_dia();
    return dia;
}

int preencher_mes_atual()
{

    int mes;
    printf("Mês atual: ");
    mes = validar_mes();
    return mes;
}

void coletar_data(int *dia_hoje, int *mes_hoje)
{
    printf("Insira a data: \n");
    *mes_hoje = preencher_mes_atual();
    *dia_hoje = preencher_dia_atual();
}

void coletar_atraso(int dia_hoje, int mes_hoje, livros *atrasados, int *contador)
{
    FILE *arquivo_emprestimos, *arquivo_livros;
    *contador = 0;
    emprestimos atraso_e;
    livros atraso_l;

    arquivo_emprestimos = fopen("emprestimos.dat", "rb");

    if (arquivo_emprestimos == NULL)
    {
        printf("Erro ao abrir o arquivo de empréstimos.\n");
    }
    else
    {
        while (fread(&atraso_e, sizeof(emprestimos), 1, arquivo_emprestimos) == 1)
        {
            if (atraso_e.situacao == 'P' && 
                ((mes_hoje > atraso_e.mes_dev) || 
                (mes_hoje == atraso_e.mes_dev && dia_hoje > atraso_e.dia_dev)))
            {
                arquivo_livros = fopen("livros.dat", "rb");
                
                if (arquivo_livros == NULL)
                {
                    printf("Erro ao abrir o arquivo de livros.\n");
                    fclose(arquivo_emprestimos);
                }
                else
                {
                    while (fread(&atraso_l, sizeof(livros), 1, arquivo_livros) == 1)
                    {
                        if (atraso_l.tombo == atraso_e.livro_tombo)
                        {
                            atrasados[*contador] = atraso_l;
                            (*contador)++;
                        }
                    }

                    fseek(arquivo_livros, 0, SEEK_SET);
                    fclose(arquivo_livros);
                }
            }
        }

        fclose(arquivo_emprestimos);
    }
}



void apresentar_lista_livros_atrasos()
{
    int dia_hoje, mes_hoje;
    dia_hoje = preencher_dia_atual();
    mes_hoje = preencher_mes_atual();

    livros atrasados[100];
    int contador;

    contador = 0;

    coletar_atraso(dia_hoje, mes_hoje, atrasados, &contador);

    printf("Lista de atrasados:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("Titulo: %s\n", atrasados[i].titulo);
        printf("Tombo: %d\n", atrasados[i].tombo);
        printf("---------------------\n");
    }
}

// exercicio 9 - final
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// exercicio 10 - inicio
void atualizar_situacao_emprestimo_devolucao(int tombo)
{
    FILE *arquivo;
    arquivo = fopen("emprestimos.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de empréstimos.\n");
    }
    else
    {
        emprestimos emprestimo;
        int controle = 0;

        do
        {
            long int posicao_anterior = ftell(arquivo);
            int leitura = fread(&emprestimo, sizeof(emprestimos), 1, arquivo);

            if (leitura == 1)
            {
                if (emprestimo.livro_tombo == tombo)
                {
                    emprestimo.situacao = 'D';

                    fseek(arquivo, posicao_anterior, SEEK_SET);
                    fwrite(&emprestimo, sizeof(emprestimos), 1, arquivo);

                    controle = 1;
                }
            }
            else
            {
                controle = 1;
            }
        } while (controle == 0);
    }
    fclose(arquivo);
}


void atualizar_situacao_livro_devolucao(int tombo)
{
    FILE *arquivo;
    arquivo = fopen("livros.dat", "rb+");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de livros.\n");
    }
    else
    {
        livros livro;
        int controle = 0;

        do
        {
            long int posicao_anterior = ftell(arquivo);
            int leitura = fread(&livro, sizeof(livros), 1, arquivo);

            if (leitura == 1)
            {
                if (livro.tombo == tombo)
                {
                    livro.situacao = 'D';

                    fseek(arquivo, posicao_anterior, SEEK_SET);
                    fwrite(&livro, sizeof(livros), 1, arquivo);

                    controle = 1;
                }
            }
            else
            {
                controle = 1;
            }
        } while (controle == 0);
    }
    fclose(arquivo);
}

emprestimos validar_tombo_devolucao(emprestimos inserir)
{
    int entrada;
    int livro_encontrado=0;
    livros livro;

    FILE *arquivo;
    arquivo = fopen("livros.dat", "rb");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo de livros.\n");
    }
    else
    {
        printf("Digite o tombo do livro: ");
        scanf("%d", &entrada);



        while (fread(&livro, sizeof(livros), 1, arquivo) == 1)
        {
            if (livro.tombo == entrada)
            {
                livro_encontrado=1;
                if (livro.situacao == 'E')
                {
                    int op;
                    int controle = 0;
                    printf("Tá pendente, quer devolver?\n1.Sim\n2.Não\n");
                    do
                    {
                        scanf("%d", &op);
                        if (op == 1)
                        {
                            inserir.livro_tombo = entrada;
                            atualizar_situacao_livro_devolucao(entrada);
                             atualizar_situacao_emprestimo_devolucao(entrada);  
                            inserir.situacao = 'D';
                            printf("Livro devolvido\n");
                            controle = 1;
                        }
                        else if (op == 2)
                        {
                            printf("Livro nao foi devolvido\n");
                            inserir.livro_tombo = -1;
                            controle = 1;
                        }
                        else
                        {
                            printf("Opção Inválida, digite entre 1 e 2\n");
                            controle = 0;
                        }
                    } while (controle == 0);
                }
                else
                {
                    printf("Já disponivel\n");
                    inserir.livro_tombo = -1;
                }
            }



        }
         if (!livro_encontrado)
         {
            printf ("Livro não cadastrado no sistema\n");
         }
    }
    fclose(arquivo);
    return inserir;
}

void devolucao()
{

    FILE *arquivo;
    emprestimos inserir;

    inserir = validar_tombo_devolucao(inserir);
    if (inserir.livro_tombo == -1)
    {
        printf("Processo encerrado\n");
    }
    else
    {

        arquivo = fopen("emprestimos.dat", "rb");
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo de empréstimos.\n");
        }
        else
        {

            fwrite(&inserir, sizeof(emprestimos), 1, arquivo);
        }
        fclose(arquivo);
    }
}
// exercicio 10 - final
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// exercicio 11- inicio
void contar_emprestimos_por_livro(int emprestimos_totais[TF3])
{
    FILE *arquivo_emprestimos;
    arquivo_emprestimos = fopen("emprestimos.dat", "rb");

    if (arquivo_emprestimos == NULL)
    {
        printf("Erro ao abrir o arquivo de empréstimos.\n");
    }
    else
    {
        emprestimos emprestimo;
        livros livro;

        for (int i = 0; i < TF3; i++)
        {
            emprestimos_totais[i] = 0;
        }

        while (fread(&emprestimo, sizeof(emprestimos), 1, arquivo_emprestimos) == 1)
        {
            FILE *arquivo_livros;
            arquivo_livros = fopen("livros.dat", "rb+");

            if (arquivo_livros == NULL)
            {
                printf("Erro ao abrir o arquivo de livros.\n");
            }
            else
            {
                while (fread(&livro, sizeof(livros), 1, arquivo_livros) == 1)
                {
                    if (livro.tombo == emprestimo.livro_tombo)
                    {
                        emprestimos_totais[livro.tombo - 1]++;
                    }
                }
            }

            fclose(arquivo_livros);
        }

        fclose(arquivo_emprestimos);
    }
}

void listar_emprestimos_quantidade_livro()
{
    int emprestimos_totais[TF2];
    contar_emprestimos_por_livro(emprestimos_totais);

    FILE *arquivo_livros;
    arquivo_livros = fopen("livros.dat", "rb");

    if (arquivo_livros == NULL)
    {
        printf("Erro ao abrir o arquivo de livros.\n");
    }
    else
    {
        livros livro;

        printf("Quantidade de empréstimos por livro:\n");

        while (fread(&livro, sizeof(livros), 1, arquivo_livros) == 1)
        {
            printf("Livro Tombo: %d\n", livro.tombo);
            printf("Quantidade Total de Empréstimos: %d\n", emprestimos_totais[livro.tombo - 1]);
            printf("--------------------------\n");
        }

        fclose(arquivo_livros);
    }
}
// exercicio 11 - final
//----------------------------------------------------------------------
