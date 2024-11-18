#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#include "aluno.h"
#include "livro.h"
#include "emprestimo.h"

//Nome da dupla:
//Breno Wille
//Maristela Sakakibara

#define TF 20

int menu()
{

    int op;
    do
    {
        printf("BIBLIOTECA ANNA DÉAK\n");
        printf("1.  Incluir novo aluno\n");
        printf("2.  Incluir novos livros\n");
        printf("3.  Apresentar lista de alunos\n");
        printf("4.  Apresentar a situacao do livro\n");
        printf("5.  Iniciar um novo emprestimo\n");
        printf("6.  Apresentar os emprestimos de determinado aluno\n");
        printf("7.  Apresentar a quantidade de emprestimo de um determinado curso\n");
        printf("8.  Apresentar todos os dados dos livros disponiveis\n");
        printf("9.  Apresentar livros com atraso\n");
        printf("10. Devolução de um livro\n");
        printf("11. Total de emprestimo de cada livro\n");
        printf("0.  sair\n");

        printf("Digite a opção: \n");
        scanf("%d", &op);

        if (op < 0 || op > 11)
        {
            printf("Opção inválida\n");
        }

    } while (op < 0 || op > 11);
    return op;
}

int main()
{
    setlocale(LC_ALL, "");
    alunos a;
    livros l;
    emprestimos e;
    int ativo[1] = {0};
    int quantidade_emprestimos[TF]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int opcao;

    do
    {
        system("cls");
        opcao = menu();
        switch (opcao)
        {
        case 1:
            a = preencher_dados_aluno();
            incluir_dados_alunos(a);
            break;
        case 2:
            l = preencher_dados_livros();
            incluir_dados_livros(l);
            break;
        case 3:
            apresentar_lista_alunos();
            break;
        case 4:
            apresentar_lista_livros();
            break;
        case 5:
            e = preencher_dados_emprestimos(ativo);
            incluir_dados_emprestimos(e, ativo);
            break;
        case 6:
            apresentar_lista_emprestimos_aluno();
            break;
        case 7:
            apresentar_quantidade_emprestimos_curso(quantidade_emprestimos);
            break;
        case 8:
            apresentar_lista_livros_disponiveis();
            break;
        case 9:
            apresentar_lista_livros_atrasos();
            break;
        case 10:
            devolucao();
            break;
        case 11:
            listar_emprestimos_quantidade_livro();
            break;
        case 0:
            printf("Fechando programa\n");
            break;
        default:
            break;
        }

        system("pause");

    } while (opcao != 0);

    return 0;
}
