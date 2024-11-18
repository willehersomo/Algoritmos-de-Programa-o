#include <stdio.h>
#include <string.h>
#include <locale.h>

#define NOME 51
#define LISTA 10


void ler_nomes(char nomes[LISTA][NOME])
{
    int i;
    printf("Insira os nomes:\n");
    for (i = 0; i < LISTA; i++)
    {
        scanf(" %50[^\n]", nomes[i]);
    }
    system ("cls");

}


void apresentar_nome(char nomes[LISTA][NOME])
{
    int i;
    printf("Nomes listados:\n");
    for (i = 0; i < LISTA; i++)
    {
        printf("%s\n", nomes[i]);
    }
}


int determinar_pessoas_iniciais(char nomes[LISTA][NOME])
{
    int i;
    int cont = 0;
    char caracter;
    printf("Digite a inicial que está procurando: \n");
    scanf(" %c", &caracter);
    for (i = 0; i < LISTA; i++)
    {
        if (nomes[i][0] == caracter || nomes[i][0] == caracter - 32)
        {
            cont++;
        }
    }
    return cont;
}


int qnt_ocorrencia(char nomes[LISTA][NOME], char caracter)
{
    int i, j;
    int cont = 0;
    for (i = 0; i < LISTA; i++)
    {
        for (j = 0; j < NOME; j++)
        {
            if (nomes[i][j] == caracter || nomes[i][j] == caracter - 32)
            {
                cont++;
            }
        }
    }
    return cont;
}

void procurar_string(char procurar[NOME])
{
    printf ("Insira o string que deseja encontrar: \n");
    scanf (" %50[^\n]", procurar);
}

void apresentar_todos_os_nomes_string(char nomes[LISTA][NOME], char procurar[NOME])
{
    int i;
    int len = strlen(procurar);
    printf("Nomes que contêm a sequência '%s':\n", procurar);
    for (i = 0; i < LISTA; i++)
    {
        if (strstr(nomes[i], procurar) != NULL)
        {
            printf("%s\n", nomes[i]);
        }
    }
}

int maior_nome(char nomes[LISTA][NOME])
{
    int i, linha;
    int maior_tamanho = 0;

    for (i = 0; i < LISTA; i++)
    {
        int tamanho_atual = strlen(nomes[i]);

        if (tamanho_atual > maior_tamanho)
        {
            maior_tamanho = tamanho_atual;
            linha=i;
        }
    }
    return linha;
}

void apresentar_primeiro(char nomes[LISTA][NOME])
{
    int i, j;

    for (i = 0; i < LISTA; i++)
    {
        printf("\nPrimeiro nome: ");
        for (j = 0; j < NOME && nomes[i][j] != ' ' && nomes[i][j] != '\0'; j++)
        {
            printf("%c", nomes[i][j]);
        }
    }
}

void apresentar_segundo(char nomes[LISTA][NOME])
{
    int i, j;

    for (i = 0; i < LISTA; i++)
    {
        printf("\nSegundo nome: ");

        int ultimo_espaco = -1;
        for (j = 0; j < NOME && nomes[i][j] != '\0'; j++)
        {
            if (nomes[i][j] == ' ')
            {
                ultimo_espaco = j;
            }
        }

        if (ultimo_espaco != -1)
        {
            for (j = ultimo_espaco + 1; j < NOME && nomes[i][j] != '\0'; j++)
            {
                printf("%c", nomes[i][j]);
            }
        }
    }
}

void mais_palavras(char nomes[LISTA][NOME])
{
    int i, j;
    int cont = 0;
    int maior = 0;
    int maior_nome=0;


    for (i = 0; i < LISTA; i++)
    {
        cont = 0;

        for (j = 0; j < NOME && nomes[i][j] != '\0'; j++)
        {
            if (nomes[i][j] == ' ')
            {
                cont++;
            }
        }


        if (cont > maior)
        {
            maior = cont;
        }
    }


    for (i = 0; i < LISTA; i++)
    {
        cont = 0;

        for (j = 0; j < NOME && nomes[i][j] != '\0'; j++)
        {
            if (nomes[i][j] == ' ')
            {
                cont++;
            }
        }


        if (cont == maior)
        {
            maior=cont;
            maior_nome=i;
        }
    }
    printf("Maior nome: %s\n", nomes[maior_nome]);
}







int main()
{
    setlocale (LC_ALL, "");
    char nomes[LISTA][NOME];
    char procurar[NOME];

    ler_nomes(nomes);
    printf ("\n");
    apresentar_nome(nomes);
    printf ("\n");

    int quantidade = determinar_pessoas_iniciais(nomes);
    printf("Quantidade de nomes que começam com a inicial desejada: %d\n", quantidade);
    printf ("\n");

    char caracter;
    printf("Digite o caractere que deseja contar: ");
    scanf(" %c", &caracter);
    printf ("\n");

    int quantidade2 = qnt_ocorrencia(nomes, caracter);
    printf("Quantidade de ocorrências desse caractere: %d\n", quantidade2);
    printf ("\n");


    procurar_string(procurar);
    printf ("\n");

    apresentar_todos_os_nomes_string(nomes, procurar);
    printf ("\n");


    int linha=maior_nome(nomes);
    printf ("Linha que contém o maior nome: %d\n", linha);
    printf ("\n");


    apresentar_primeiro(nomes);
    printf ("\n");

    apresentar_segundo(nomes);
    printf ("\n");

    mais_palavras (nomes);
    printf ("\n");


    return 0;
}
