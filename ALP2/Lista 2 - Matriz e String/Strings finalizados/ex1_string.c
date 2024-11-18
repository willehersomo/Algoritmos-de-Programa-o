#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TF 101

void preencher_vetor_inicial(char string1[], int *tl1)
{
    printf("Digite a string: ");
    scanf(" %100[^\n]", string1);
    *tl1 = strlen(string1);
}

void apresentar_string1(char string[])
{
    printf("String1: %s", string);
    printf(".");
    printf("\n");
}

void apresentar_string2(char string2[])
{
    printf("String2: %s", string2);
    printf("\n");
}

void menu()
{
    printf ("Digite a opção: \n");
    printf ("A. Excluir caracter de uma determinada posição de uma string\n");
    printf ("B. Incluir um caracter em uma determinada posição de uma string\n");
    printf ("C. Copiar uma parte de uma string para dentro de outra, para isso deve-se conhecer a posição inicial e o final a ser copiada\n");
    printf ("D. Copiar a primeira palavra de uma string para outra string\n");
    printf ("E. Copiar a ultima palavra de uma string para outra string\n");
    printf ("F. Retirar os espaços em branco repetidos de uma string\n");
    printf ("G. Retirar os espaços em branco do final de uma string\n");
    printf ("H. Retirar os espaços em branco do início de uma string\n");
    printf ("I. Copiar o conteúdo de uma string para outra;\n");
    printf ("J. Apagar o conteúdo de uma string\n");
    printf ("K. Sair\n");
}

void excluir_caracter_posicao(char string[], int *tl1)
{
    int pos;
    printf("Digite a posição em que deseja excluir o caractere: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > *tl1 - 1)
    {
        printf("Posição inexistente ou inválida\n");
    }
    else
    {
        for (int i = pos; i < *tl1 - 1; i++)
        {
            string[i] = string[i + 1];
        }
        (*tl1)--;
        string[*tl1] = '\0';
        printf("Caractere excluído da posição %d\n", pos);
    }
}

void incluir_caracter_posicao(char string[], int *tl1)
{
    int pos;
    printf("Digite a posição em que deseja incluir o caractere: ");
    scanf("%d", &pos);
    if (pos < 0 || pos > *tl1)
    {
        printf("Posição inexistente ou inválida\n");
    }
    else
    {
        char caracter;
        printf("Qual caractere deseja inserir: ");
        scanf(" %c", &caracter);

        for (int i = (*tl1); i > pos; i--)
        {
            string[i] = string[i - 1];
        }
        string[pos] = caracter;
        (*tl1)++;
        printf("Caractere inserido na posição %d\n", pos);
    }
}

void copiar_string_para_outra(char string1[], char string2[], int *tl1, int *tl2)
{
    int pos_inicial, pos_final;
    printf("Determine o início (posição) do intervalo a ser copiado:\n");
    scanf("%d", &pos_inicial);
    if (pos_inicial < 0 || pos_inicial >= *tl1)
    {
        printf("Posição inexistente ou inválida na string 1\n");
    }
    else
    {
        printf("Determine o final (posição) do intervalo a ser copiado:\n");
        scanf("%d", &pos_final);
        if (pos_final < 0 || pos_final >= *tl1 || pos_final < pos_inicial)
        {
            printf("Posição inexistente ou inválida na string 1\n");
        }
        else
        {
            for (int i = pos_inicial, j = 0; i <= pos_final; i++, j++)
            {
                string2[*tl2 + j] = string1[i];
            }
            *tl2 += (pos_final - pos_inicial + 1);
            printf("Intervalo copiado com sucesso da string 1 para a string 2\n");
        }
    }
}

void copiar_ultima_palavra(char string1[], char string2[], int *tl1, int *tl2)
{
    int i = *tl1 - 1;
    int j = *tl2;
    while (i >= 0 && (string1[i] == ' ' || string1[i] == '\t' || string1[i] == '\n'))
    {
        i--;
    }
    if (i >= 0)
    {
        int fim = i;
        while (i >= 0 && string1[i] != ' ' && string1[i] != '\t' && string1[i] != '\n')
        {
            i--;
        }
        while (i < fim)
        {
            string2[j++] = string1[++i];
        }
        string2[j] = '\0';
        *tl2 = j;
        printf("Última palavra adicionada com sucesso à string2\n");
    }
    else
    {
        printf("Nenhuma palavra encontrada para copiar\n");
    }
}

void copiar_primeira_palavra_string(char string1[], char string2[], int *tl1, int *tl2)
{
    int i = 0;
    while (string1[i] != ' ' && string1[i] != '\0')
    {
        string2[(*tl2)++] = string1[i];
        i++;
    }
    printf("Primeira palavra copiada com sucesso para a string2\n");
}

void retirar_espacos_em_branco(char string1[], int *tl1)
{
    int i, j;
    for (i = 0, j = 0; i < *tl1; i++)
    {
        if (string1[i] != ' ' || (i > 0 && string1[i - 1] != ' '))
        {
            string1[j] = string1[i];
            j++;
        }
    }
    *tl1 = j;
    string1[j] = '\0';
    printf("Espaços em branco repetidos removidos com sucesso\n");
}

void retirar_espacos_em_branco_final(char string1[], int *tl1)
{
    int i = *tl1 - 1;
    while (i >= 0 && (string1[i] == ' ' || string1[i] == '\t' || string1[i] == '\n'))
    {
        string1[i] = '\0';
        i--;
    }
    *tl1 = i + 1;
    printf("Espaços em branco no final removidos com sucesso\n");
}

void retirar_espacos_em_branco_inicio(char string1[], int *tl1)
{
    int i = 0;
    while (string1[i] == ' ' || string1[i] == '\t' || string1[i] == '\n')
    {
        i++;
    }
    if (i > 0)
    {
        int j = 0;
        while (string1[i] != '\0')
        {
            string1[j] = string1[i];
            i++;
            j++;
        }
        string1[j] = '\0';
        *tl1 = j;
    }
    printf("Espaços em branco no início removidos com sucesso\n");
}

void copiar_conteudo_string(char string1[], int *tl1, char string2[], int *tl2)
{
    for (int i = 0; i < *tl1; i++)
    {
        string2[i] = string1[i];
    }
    *tl2 = *tl1;
    printf("Conteúdo da string 1 copiado com sucesso para a string 2\n");
}

void apagar_conteudo_string(char string1[], int *tl1)
{
    int i = 0;
    while (string1[i] != '\0')
    {
        string1[i] = '\0';
        i++;
    }
    *tl1 = 0;
    printf("Conteúdo da string apagado com sucesso.\n");
}

void selecionar(char op, char string1[], char string2[], int *tl1, int *tl2)
{
    do
    {
        apresentar_string1(string1);
        apresentar_string2(string2);
        menu();
        printf ("\n");


        printf("Digite a opção (A, B, C, D, E, F, G, H, I, J, K): ");
        scanf(" %c", &op);
        printf ("\n");


        switch (op)
        {
        case 'A':
        case 'a':
            excluir_caracter_posicao(string1, tl1);
                    printf ("\n");
            break;
        case 'B':
        case 'b':
            incluir_caracter_posicao(string1, tl1);
                    printf ("\n");
            break;
        case 'C':
        case 'c':
            copiar_string_para_outra(string1, string2, tl1, tl2);
                    printf ("\n");
            break;
        case 'D':
        case 'd':
            copiar_primeira_palavra_string(string1, string2, tl1, tl2);
                    printf ("\n");
            break;
        case 'E':
        case 'e':
            copiar_ultima_palavra(string1, string2, tl1, tl2);
                    printf ("\n");
            break;
        case 'F':
        case 'f':
            retirar_espacos_em_branco(string1, tl1);
                    printf ("\n");
            break;
        case 'G':
        case 'g':
            retirar_espacos_em_branco_final(string1, tl1);
                    printf ("\n");
            break;
        case 'H':
        case 'h':
            retirar_espacos_em_branco_inicio(string1, tl1);
                    printf ("\n");
            break;
        case 'I':
        case 'i':
            copiar_conteudo_string(string1, tl1, string2, tl2);
                    printf ("\n");
            break;
        case 'J':
        case 'j':
            apagar_conteudo_string(string1, tl1);
                    printf ("\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
                printf ("\n");
        }
    } while (op != 'K' && op != 'k');
        printf ("\n");
        }

int main()
{
    setlocale(LC_ALL, "");

    char string1[TF], string2[TF];
    int tl1 = 0, tl2 = 0;

    preencher_vetor_inicial(string1, &tl1);
    char op;
    selecionar(op, string1, string2, &tl1, &tl2);

    return 0;
}


