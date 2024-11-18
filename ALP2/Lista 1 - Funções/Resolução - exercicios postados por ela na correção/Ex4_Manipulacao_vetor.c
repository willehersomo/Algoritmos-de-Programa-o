#include <stdio.h>
#define TF 30


void apresentarMsg(char msg[])
{
    printf(msg);
}


// Apresenta o menu com as opções
void apresentar_menu()
{
    printf("\nSelecione uma das opções:\n1. Incluir um número no final do vetor.\n2. Incluir um número em uma determinada posição.\n3. Incluir um número no início do vetor.\n4. Excluir o primeiro elemento do vetor.\n5. Excluir o último elemento do vetor.\n6. Excluir um elemento de uma posição indicada.\n7. Apresentar o vetor inteiro.\n8. Excluir um determinado elemento.\n9. Localizar e apresentar a posição de um determinado elemento.\n10. Excluir os elementos de um intervalo.\n11. Encerrar o programa.\n");
}

// Lê o número a ser incluído
int ler_numero()
{
    int num;

    printf("\nInsira o número desejado: ");
    scanf("%d", &num);
    return num;
}

// Lê a posição desejada
int ler_posicao()
{
    int num;

    do
    {
        printf("\nInsira a posição desejada: ");
        scanf("%d", &num);
        if (num > 30 || num < 0)
        {
            printf("\nA posição inserida é inválida\n");
        }
    }
    while (num > 30 || num < 0);
    num -= 1;
    return num;
}

// Lê os limites do intervalo
int ler_intervalo()
{
    int num;

    do
    {
        printf("\nInsira um limite do intervalo: ");
        scanf("%d", &num);
        if (num > 30 || num < 0)
        {
            printf("\nA posição inserida é inválida\n");
        }
    }
    while (num > 30 || num < 0);
    num -= 1;
    return num;
}

// Determina a posição final atual do vetor
int determina_posicao(int original[30])
{
    int pos = -1;

    for (int i = 0; i < 30; i++)
    {
        if (original[i] == 1)
        {
            pos = i;
        }
    }
    return pos;
}

// Determina quantas posições estão disponíveis
int determina_disponibilidade(int original[30], int pos)
{
    int disponivel = 0;

    for (int i = pos; i < 30; i++)
    {
        if (original[i] == 0)
        {
            disponivel++;
        }
    }
    return disponivel;
}

// Determina se o intervalo está vazio
int intervalo_vazio(int original[30], int menor, int maior)
{
    int j = 0;

    for (int i = menor; i < maior; i++)
    {
        if (original[i] == 1)
        {
            j++;
        }
    }
    return j;
}



// Move os elementos no vetor uma posição para a direita
void mover_direita(int vetor[30], int original[30], int pos, int sub, int sub2)
{
    int sub3, sub4, dis;

    for (int i = pos + 1; i < 30; i++)
    {
        dis = determina_disponibilidade(original, i);
        if (dis != 0)
        {
            sub3 = vetor[i];
            vetor[i] = sub;
            sub = sub3;
            sub4 = original[i];
            original[i] = sub2;
            sub2 = sub4;
        }
    }
}

// Move os elementos no vetor uma posição para a esquerda
void mover_esquerda(int vetor[30], int original[30], int pos)
{
    for (int i = pos; i < 29; i++)
    {
        vetor[i] = vetor[i + 1];
        original[i] = original[i + 1];
    }
    vetor[29] = 0;
    original[29] = 0;
}

// Procura a posição lógica de um elemento determinado pelo usuário
int procurar_posicao(int vetor[30], int posicoes[30], int original[30])
{
    int i = 0, j = 0, num;
    num = ler_numero();
    for (i = 0; i < 30; i++)
    {
        if (vetor[i] == num && original[i] == 1)
        {
            posicoes[j] = i;
            j++;
        }
    }
    return j;
}

// Inclui um número no final do vetor
void incluir_final(int vetor[30], int original[30], int posicao[1])
{
    int num, pos, dis = 0;
    pos = posicao[0];
    dis = determina_disponibilidade(original, pos);
    if (dis != 0)
    {
        num = ler_numero();
        vetor[pos + 1] = num;
        original[pos + 1] = 1;
        posicao[0] = determina_posicao(original);
    }
    else
    {
        apresentarMsg("\nO vetor já atingiu o limite de 30 itens, ou não é possível inserir um item nessa posição, logo não é possível adcionar um número.\n");
    }
}

// Inclui um número em uma determinada posição definida pelo usuário
void incluir_na_posicao(int vetor[30], int original[30], int posicao[1])
{
    int num, pos, sub, sub2, dis = 0;

    pos = ler_posicao();
    dis = determina_disponibilidade(original, pos);
    if (dis != 0)
    {
        num = ler_numero();
        sub = vetor[pos];
        sub2 = original[pos];
        vetor[pos] = num;
        original[pos] = 1;
        mover_direita(vetor, original, pos, sub, sub2);
        posicao[0] = determina_posicao(original);
    }
    else
    {
        apresentarMsg("\nO vetor já atingiu o limite de 30 itens, ou não é possível inserir um item nessa posição, logo não é possível adcionar um número.\n");

    }
}  char msg[TF]="";

// Inclui um número no início do vetor
void incluir_inicio(int vetor[30], int original[30], int posicao[1])
{
    int num, sub, sub2, pos, dis = 0;

    pos = posicao[0];
    dis = determina_disponibilidade(original, 0);
    if (dis != 0)
    {
        num = ler_numero();
        sub = vetor[0];
        sub2 = original[0];
        vetor[0] = num;
        original[0] = 1;
        mover_direita(vetor, original, 0, sub, sub2);
        posicao[0] = determina_posicao(original);
    }
    else
    {
        apresentarMsg("\nO vetor já atingiu o limite de 30 itens, ou não é possível inserir um item nessa posição, logo não é possível adcionar um número.\n");

    }
}

// Exclui o primeiro elemento do vetor
void excluir_inicio(int vetor[30], int original[30], int posicao[1])
{
    int pos;

    pos = posicao[0];
    if (original[0] == 0)
    {
        apresentarMsg("\nA posição do vetor já está vazia.\n");
    }
    else
    {
        mover_esquerda(vetor, original, 0);
    }
    posicao[0] = determina_posicao(original);
}

// Exclui o último elemento do vetor
void excluir_final(int vetor[30], int original[30], int posicao[1])
{
    int pos;

    pos = posicao[0];
    if (original[pos] == 0)
    {
        apresentarMsg("\nA posição do vetor já está vazia.\n");
    }
    else
    {
        vetor[pos] = 0;
        original[pos] = 0;
    }
    posicao[0] = determina_posicao(original);
}

// Exclui um elemento de uma posição indicada pelo usuário
void excluir_posicao(int vetor[30], int original[30], int posicao[1])
{
    int pos, sub, sub2, dis = 0;

    pos = ler_posicao();
    if (original[pos] == 0)
    {
        apresentarMsg("\nA posição do vetor já está vazia.\n");
    }
    else
    {
        mover_esquerda(vetor, original, pos);
    }
    posicao[0] = determina_posicao(original);
}

// Apresenta o vetor inteiro
void apresentar_vetor(int vetor[30], int original[30])
{
    printf("\n");
    for (int i = 0; i < 30; i++)
    {
        if (original[i] == 1)
        {
            printf("%d ", vetor[i]);
        }
        else
        {
            printf("  ");
        }
    }
    printf("\n");
}

// Exclui um determinado elemento determinado pelo usuário
void excluir_elemento(int vetor[30], int original[30], int posicao[1])
{
    int total = 0, posicoes[30] = {};

    total = procurar_posicao(vetor, posicoes, original);
    if (total != 0)
    {
        for (int i = total - 1; i > -1; i--)
        {
            mover_esquerda(vetor, original, posicoes[i]);
        }
        posicao[0] = determina_posicao(original);
    }
    else
    {
        apresentarMsg("\nO elemento procurado não foi encontrado.\n");
    }
}

// Localiza e apresenta a posição de um determinado elemento do vetor
void apresentar_posicao(int vetor[30], int original[30])
{
    int total = 0, posicoes[30] = {};

    total = procurar_posicao(vetor, posicoes, original);
    if (total != 0)
    {
        for (int i = 0; i < total; i++)
        {
            printf("\nO número procurado está na %dª posição.\n", posicoes[i] + 1);
        }
    }
    else
    {
        apresentarMsg("\nO elemento procurado não foi encontrado.\n");
    }
}

// Exclui os elementos entre duas posições do vetor
void excluir_intervalo(int vetor[30], int original[30], int posicao[1])
{
    int pos1, pos2, intervalo, maior, menor, vazio;

    pos1 = ler_intervalo();
    pos2 = ler_intervalo();
    if (pos1 > pos2)
    {
        intervalo = pos1 - pos2;
        maior = pos1 - 1;
        menor = pos2 + 1;
    }
    else
    {
        intervalo = pos2 - pos1;
        maior = pos2 - 1;
        menor = pos1 + 1;
    }
    vazio = intervalo_vazio(original, menor, maior);
    if (vazio != 0)
    {
        for (int i = maior; i > menor - 1; i--)
        {
            if (original[i] == 1)
            {
                mover_esquerda(vetor, original, i);
            }
        }
    }
    else
    {
        printf("\nO intervalo já está vazio.\n");
    }
    posicao[0] = determina_posicao(original);
}

// Lê e executa a opção escohida pelo usuário
void ler_e_executar(int vetor[], int original[], int posicao[1])
{
    int opcao = 0;

    while (opcao != 11)
    {
        apresentar_menu();
        printf("\nInsira a opção desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            incluir_final(vetor, original, posicao);
            break;
        case 2:
            incluir_na_posicao(vetor, original, posicao);
            break;
        case 3:
            incluir_inicio(vetor, original, posicao);
            break;
        case 4:
            excluir_inicio(vetor, original, posicao);
            break;
        case 5:
            excluir_final(vetor, original, posicao);
            break;
        case 6:
            excluir_posicao(vetor, original, posicao);
            break;
        case 7:
            apresentar_vetor(vetor, original);
            break;
        case 8:
            excluir_elemento(vetor, original, posicao);
            break;
        case 9:
            apresentar_posicao(vetor, original);
            break;
        case 10:
            excluir_intervalo(vetor, original, posicao);
            break;
        case 11:
            apresentarMsg("\nPrograma encerrado.\n");

            break;
        default:
            apresentarMsg("\nOpção inválida.\n");
            break;
        }
    }
}

// Executa a parte principal do código
void main()
{
    int vetor[TF] = {}, posicao[1] = {-1}, opcao = 0, original[TF] = {};

    ler_e_executar(vetor, original, posicao);
}
