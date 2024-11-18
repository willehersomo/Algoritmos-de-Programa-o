#include <stdio.h>
#define TF3 20

typedef struct
{
    int tombo;
    char titulo[100];
    char autores[50];
    int ano;
    char situacao;
} livros;
//----------------------------------------------------------------------
//exercicio 2 - inicio
livros validar_tombo(int tombo_digitado)
{
    livros livro;
    int tombo_encontrado = 0;

    FILE *arquivo;
    arquivo = fopen("livros.dat", "rb");

    while (fread(&livro, sizeof(livros), 1, arquivo) == 1 && !tombo_encontrado)
    {
        if (tombo_digitado < 0 || (livro.tombo == tombo_digitado))
        {
            tombo_encontrado = 1;
        }
    }

    fclose(arquivo);

    if (tombo_encontrado || tombo_digitado < 0)
    {
        printf("Tombo existente ou dado menor que 0.\n");
        livro.tombo = -1;
    }

    return livro;
}

int validar_ano_publicado()
{
    int entrada;
    int controle = 0;
    do
    {
        scanf("%d", &entrada);
        if (entrada < 0)
        {
            printf("Apenas número positivo, digite novamente\n");
            controle = 0;
        }
        else
        {
            controle = 1;
        }

    } while (!controle);
    return entrada;
}

livros preencher_dados_livros()
{
    livros inserir;

    printf("Cadastro de livros\n");
    printf("------------------------------\n");

    printf("Tombo do livro: \n");
    scanf("%d", &inserir.tombo);

    livros tombo_existente = validar_tombo(inserir.tombo);

    if (tombo_existente.tombo != -1)
    {
        printf("Nome do livro: \n");
        scanf(" %99[^\n]", inserir.titulo);
        printf("Autor(es) do livro: \n");
        scanf(" %49[^\n]", inserir.autores);
        printf("Ano de publicação: \n");
        inserir.ano = validar_ano_publicado();
        inserir.situacao = 'D';
    }

    return inserir;
}

void incluir_dados_livros(livros inserir)
{
    FILE *arquivo;
    livros livro;
    int tombo_encontrado = 0;

    arquivo = fopen("livros.dat", "rb+");

    if (arquivo == NULL)
    {
        arquivo = fopen("livros.dat", "wb");
    }

    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo.\n");
    }
    else
    {
        while (fread(&livro, sizeof(livros), 1, arquivo) == 1)
        {
            if (livro.tombo == inserir.tombo)
            {
                tombo_encontrado = 1;
            }
        }

        if (!tombo_encontrado && inserir.tombo >= 0)
        {
            fwrite(&inserir, sizeof(livros), 1, arquivo);
            printf ("Livro cadastrado\n");
        }

        fclose(arquivo);
    }
}
//exercicio 2 - final
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//exercicio 4 - inicio
void apresentar_lista_livros()
{
    FILE *arquivo;
    livros livro;
    arquivo = fopen("livros.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Arquivo não lido\n");
    }
    else
    {
        printf("Lista de livros: \n");

        while (fread(&livro, sizeof(livros), 1, arquivo) == 1)
        {
            printf("Titulo: %s\n", livro.titulo);
            printf("Autores: %s\n", livro.autores);
            printf("Tombo: %d\n", livro.tombo);
            printf("Ano de publicação: %d\n", livro.ano);
            printf("Situação: %c\n", livro.situacao);
            printf("--------------------------\n");
        }
    }
    fclose(arquivo);
}
//exercicio 4 - final
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//exercicio 8 - inicio
void apresentar_lista_livros_disponiveis()
{
    FILE *arquivo;
    livros disponiveis;
    arquivo = fopen("livros.dat", "rb");
    if (arquivo == NULL)
    {
        printf("Arquivo não abriu\n");
    }
    else
    {

        printf("Lista de livros disponiveis: \n");
        printf("\n");

        while (fread(&disponiveis, sizeof(livros), 1, arquivo) == 1)
        {

            if (disponiveis.situacao == 'D')
            {
                printf("Titulo: %s\n", disponiveis.titulo);
                printf("Autores: %s\n", disponiveis.autores);
                printf("Tombo: %d\n", disponiveis.tombo);
                printf("Ano de publicação: %d\n", disponiveis.ano);
                printf("--------------------------\n");
            }
        }
    }
}
//exercicio 8 - final
//----------------------------------------------------------------------
//----------------------------------------------------------------------