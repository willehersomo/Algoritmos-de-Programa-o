#include <stdio.h>
#define TF 100

// Calcula o tamanho lógico do nome
int tamanho_nome(char nome[])
{
    int i = 0;

    while (nome[i] != '\n' && i < TF)
    {
        i++;
    }
    return i;
}

// Solicita o nome ao usuário e o armazena
void solicitar_nome(char nome[])
{
    printf("\nInsira o nome desejado: ");
    fflush(stdin);
    fgets(nome, TF, stdin);
}

// Conta a quantidade de palavras que formam o nome
int contar_palavras(char nome[], int tamanho)
{
    int qtd = 1; // considera a primeira palavra sem espaco

    for (int i = 0; i < tamanho; i++)
    {
        if (nome[i] == ' ')
        {
            qtd++;
        }
    }
    return qtd;
}

// Contar a quantidade de letras no nome (excluindo os espaços)
int contar_letras(char nome[], int tamanho)
{
    int qtd = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (nome[i] != ' ' && nome[i] != '\n')
        {
            qtd++;
        }
    }
    return qtd;
}

// Apresenta em diferentes linhas as palavras que formam o nome
void apresentar_palavras(char nome[], int tamanho)
{
    printf("\n");
    for (int i = 0; i < tamanho; i++)
    {
        while (nome[i] != ' ' && nome[i] != '\n')
        {
            printf("%c", nome[i]);
            i++;
        }
        printf("\n");
    }
}

// Verifica se as paalvras do nome iniciam com letra maiúscula
void ver_palavras_capitalizadas(char nome[], int tamanho)
{
    int nao = 0;

    if (nome[0] >= 97 && nome[0] <= 122)
    {
        nao++;
    }
    for (int i = 0; i < tamanho; i++)
    {
        if (nome[i] == ' ' && nome[i + 1] >= 97 && nome[i + 1] <= 122)
        {
            nao++;
        }
    }
    if (nao != 0)
    {
        printf("\nNem todas as palvras começam com letras maiúsculas, %d delas começam com letras minúsculas.\n", nao);
    }
    else
    {
        printf("\nTodas as palavras começam com letras maiúsculas.\n");
    }
}

// Transfere o nome para outro vetor sem espaços em branco
void  pegar_nome_sem_espacos(char nome[], char nome_sem_espacos[], int tamanho)
{
    int j = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (nome[i] != ' ' && nome[i] != '\0')
        {
            nome_sem_espacos[j] = nome[i];
            j++;
        }
    }
    nome_sem_espacos[j]='\0';
}

// Executa a parte principal do código
void main()
{
    int tamanho = 0, qtd;
    char nome[TF] = {}, nome_sem_espacos_var[TF]={};

    solicitar_nome(nome);
    tamanho = tamanho_nome(nome);
    qtd= contar_palavras(nome, tamanho);
    printf("\nA quantidade de palavras que formam esse nome é de: %d palavras.\n", qtd);
    qtd= contar_letras(nome, tamanho);
    printf("\nA quantidade de letras no nome é de: %d letras.\n", qtd);
    apresentar_palavras(nome, tamanho);
    ver_palavras_capitalizadas(nome, tamanho);
    pegar_nome_sem_espacos(nome, nome_sem_espacos_var, tamanho);
    printf("\nO nome sem espaços é:\n%s\n", nome_sem_espacos_var);
}
