#include <stdio.h>
#include <locale.h>
#define TF 30


void incluir_final(int v[], int *tl, int num)
{
    if (*tl < TF)
    {
        v[*tl] = num;
        (*tl)++;
        printf("Número %d incluído no final do vetor.\n", num);
    }
    else
    {
        printf("Vetor cheio. Não é possível incluir.\n");
    }
}


void incluir_posicao(int v[], int *tl, int num, int pos)
{
    if (*tl < TF)
    {
        if (pos >= 0 && pos <= *tl)
        {
            for (int i = *tl; i > pos; i--)
            {
                v[i] = v[i-1];
            }
            v[pos] = num;
            (*tl)++;
            printf("Número %d incluído na posição %d do vetor.\n", num, pos);
        }
        else
        {
            printf("Posição inválida. Não é possível incluir.\n");
        }
    }
    else
    {
        printf("Vetor cheio. Não é possível incluir.\n");
    }
}


void incluir_inicio(int v[], int *tl, int num)
{
    incluir_posicao(v, tl, num, 0);
}


void excluir_inicio(int v[], int *tl)
{
    if (*tl > 0)
    {
        int num = v[0];
        for (int i = 0; i < *tl - 1; i++)
        {
            v[i] = v[i+1];
        }
        (*tl)--;
        printf("Número %d excluído do início do vetor.\n", num);
    }
    else
    {
        printf("Vetor vazio. Não é possível excluir.\n");
    }
}


void excluir_final(int v[], int *tl)
{
    if (*tl > 0)
    {
        int num = v[*tl - 1];
        (*tl)--;
        printf("Número %d excluído do final do vetor.\n", num);
    }
    else
    {
        printf("Vetor vazio. Não é possível excluir.\n");
    }
}


void excluir_posicao(int v[], int *tl, int pos)
{
    if (*tl > 0)
    {
        if (pos >= 0 && pos < *tl)
        {
            int num = v[pos];
            for (int i = pos; i < *tl - 1; i++)
            {
                v[i] = v[i+1];
            }
            (*tl)--;
            printf("Número %d excluído da posição %d do vetor.\n", num, pos);
        }
        else
        {
            printf("Posição inválida. Não é possível excluir.\n");
        }
    }
    else
    {
        printf("Vetor vazio. Não é possível excluir.\n");
    }
}


void apresentar_vetor(int v[], int tl)
{
    printf("Vetor: ");
    for (int i = 0; i < tl; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}


void excluir_elemento(int v[], int *tl, int num)
{
    int pos = -1;
    for (int i = 0; i < *tl; i++)
    {
        if (v[i] == num)
        {
            pos = i;
        }
    }
    if (pos != -1)
    {
        excluir_posicao(v, tl, pos);
    }
    else
    {
        printf("Elemento %d não encontrado. Não é possível excluir.\n", num);
    }
}


void localizar_elemento(int v[], int tl, int num)
{
    int pos = -1;
    for (int i = 0; i < tl; i++)
    {
        if (v[i] == num)
        {
            pos = i;
        }
    }
    if (pos != -1)
    {
        printf("Elemento %d encontrado na posição %d do vetor.\n", num, pos);
    }
    else
    {
        printf("Elemento %d não encontrado.\n", num);
    }
}


void excluir_intervalo(int v[], int *tl, int inicio, int fim)
{
    if (*tl > 0)
    {
        if (inicio >= 0 && inicio < *tl && fim >= 0 && fim < *tl && inicio <= fim)
        {
            int n = fim - inicio + 1;
            for (int i = inicio; i < *tl - n; i++)
            {
                v[i] = v[i+n];
            }
            (*tl) -= n;
            printf("%d elementos excluídos do intervalo [%d, %d] do vetor.\n", n, inicio, fim);
        }
        else
        {
            printf("Posições inválidas. Não é possível excluir.\n");
        }
    }
    else
    {
        printf("Vetor vazio. Não é possível excluir.\n");
    }
}


int main()
{
    setlocale(LC_ALL, "");
    int v[TF];
    int tl = 0;
    int opcao, num, pos, inicio, fim;

    do
    {

        printf("\nMenu de operações com um vetor de inteiros:\n");
        printf("1 - Incluir um número no final do vetor\n");
        printf("2 - Incluir um número em uma determinada posição definida pelo usuário\n");
        printf("3 - Incluir um número no início do vetor\n");
        printf("4 - Excluir o primeiro elemento do vetor\n");
        printf("5 - Excluir o último elemento do vetor\n");
        printf("6 - Excluir um elemento de uma posição indicada pelo usuário\n");
        printf("7 - Apresentar o vetor inteiro (até o tl)\n");
        printf("8 - Excluir um determinado elemento determinado pelo usuário\n");
        printf("9 - Localizar e apresentar a posição de um determinado elemento do vetor\n");
        printf("10 - Excluir os elementos entre duas posições do vetor\n");
        printf("0 - Sair do programa\n");


        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf ("Digite o número a ser inserido no final do vetor:\n");
            scanf("%d", &num);
            incluir_final(v, &tl, num);
            break;
        case 2:
            printf ("Digite o número a ser inserido:\n");
            scanf("%d", &num);
            printf ("Em qual posição?\n");
            scanf ("%d", &pos);
            incluir_posicao(v, &tl, num, pos);
            break;
        case 3:
            printf ("Digite o número a ser inserido no inicio do vetor:\n");
            scanf("%d", &num);
            incluir_inicio(v, &tl, num);
            break;
        case 4:
            excluir_inicio(v, &tl);
            break;
        case 5:
            excluir_final(v, &tl);
            break;
        case 6:
            printf ("Deseja excluir o elemento de qual posição?\n");
            scanf("%d", &pos);
            excluir_posicao(v, &tl, pos);
            break;
        case 7:
            apresentar_vetor(v, tl);
            break;
        case 8:
            printf ("Deseja excluir qual elemento?\n");
            scanf("%d", &num);
            excluir_elemento(v, &tl, num);
            break;
        case 9:
            printf ("Qual elemento do vetor deseja localizar?\n");
            scanf("%d", &num);
            localizar_elemento(v, tl, num);
            break;
        case 10:
            printf ("Digite o incio do intervalo:\n");
            scanf("%d", &inicio);
            printf ("Digite o fim do intervalo: \n");
            scanf ("%d", &fim);
            excluir_intervalo(v, &tl, inicio, fim);
            break;
        case 0:
            printf("Programa encerrado\n");
            break;
        default:
            printf("Opção inválida, tente novamente!\n");
            break;
        }
    }
    while (opcao != 0);

    return 0;
}
