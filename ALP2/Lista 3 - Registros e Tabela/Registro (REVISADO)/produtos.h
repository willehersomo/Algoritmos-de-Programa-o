#define TF 20
#define NOME 101

struct produtos
{
    int codigo;
    char nome[NOME];
    float preco;
    int estoque;
};

int ler_inteiro();
float ler_float();

//----------------------------------------------------------------------------------------------------------------------
//exercicio 1 - inicio


void preencher_nome_produto(struct produtos tab_produtos[], int tl_produtos)
{
    scanf(" %100[^\n]", tab_produtos[tl_produtos].nome);

}

int ler_codigo()
{
    int codigo;
    printf("Digite o código do produto (ou 0 para cancelar): ");
    codigo=ler_inteiro();
    return codigo;
}

int validar_codigo(int codigo, struct produtos tab_produtos[], int tl_produtos)
{
    int codigo_valido = 0;
    int encontrou_duplicado = 0;

    if (codigo < 0)
    {
        printf("Código inválido, insira um valor maior que 0.\n");
    }
    else if (codigo > 0)
    {
        for (int i = 0; i < tl_produtos; i++)
        {
            if (codigo == tab_produtos[i].codigo)
            {
                printf("O código do produto já existe. Insira um novo código.\n");
                encontrou_duplicado = 1;
                i=tl_produtos;
            }
        }
        if (!encontrou_duplicado)
        {
            codigo_valido = 1;
        }
    }

    return codigo_valido;
}


int coletar_codigo_produto(struct produtos tab_produtos[], int tl_produtos)
{
    int codigo;
    int valido=0;
    do
    {
        codigo = ler_codigo();
        if(codigo!=0)
        {
            valido = validar_codigo(codigo, tab_produtos, tl_produtos);
        }
        else
        {
            valido=1;
        }
    }
    while(valido == 0);
    return codigo;
}

float ler_preco_produto()
{
    float preco;
    printf("Digite o preço do produto (use virgula para separar as casas): ");
    preco=ler_float();
    return preco;
}

float validar_preco(float preco)
{
    int preco_valido=1;
    if(preco<=0.0)
    {
        printf ("Valor inválido, insira maior que 0\n");
    }
    else
    {
        preco_valido=0;
    }
    return preco_valido;
}



float coletar_preco_produto()
{
    float preco;
    int valido = 1;
    do
    {
        preco = ler_preco_produto();
        valido = validar_preco(preco);
    }
    while (valido);
    return preco;
}

int ler_estoque_produto()
{
    int estoque;
    printf("Digite o estoque do produto: ");
    estoque=ler_inteiro();
    return estoque;
}

int validar_estoque(int estoque)
{
    int estoque_valido=1;
    if(estoque<=0)
    {
        printf ("Valor inválido, insira maior que 0\n");
    }
    else
    {
        estoque_valido=0;
    }
    return estoque_valido;
}



int coletar_estoque_produto()
{
    int estoque;
    int valido = 1;
    do
    {
        estoque = ler_estoque_produto();
        valido = validar_estoque(estoque);
    }
    while (valido);
    return estoque;
}

void preencher_tabela_produtos_existe(struct produtos tab_produtos[], int tl_produtos, int codigo)
{
    if (codigo != 0)
    {
        printf("Digite o nome do produto: ");
        preencher_nome_produto(tab_produtos, tl_produtos);
        tab_produtos[tl_produtos].preco = coletar_preco_produto();
        tab_produtos[tl_produtos].estoque = coletar_estoque_produto();
    }
    else
    {
        printf("Finalizado.\n");
    }
}

void incluir_produto(struct produtos tab_produtos[], int *tl_produtos)
{
    if (*tl_produtos < TF)
    {
        int codigo = coletar_codigo_produto(tab_produtos, *tl_produtos);
        if (codigo != 0)
        {
            tab_produtos[(*tl_produtos)].codigo = codigo;
            preencher_tabela_produtos_existe(tab_produtos, *tl_produtos, codigo);
            (*tl_produtos)++;
        }
        else
        {
            printf("Inserção cancelada.\n");
        }
    }
    else
    {
        printf("Não há como efetuar a inserção de mais produtos!\n");
    }
}

//exercicio 1 - final

//---------------------------------------------------------------------------------------------------------------------------------------------

//exercico 2 - inicio


int selecionar_produto (struct produtos tab_produtos[], int tl_produtos)
{
    int op;
    int valido = 1;
    int produto_encontrado;
    while (valido)
    {
        printf ("Digite o código do produto com que deseja trabalhar: \n");
        op=ler_inteiro();
        produto_encontrado = 0;
        for (int i=0; i<tl_produtos; i++)
        {
            if (tab_produtos[i].codigo==op)
            {
                produto_encontrado = 1;
                valido = 0;
            }
        }
        if (!produto_encontrado)
        {
            printf ("Inválido ou inexistente\n");
        }
    }
    return op;
}



int encontrar_posicao_produto (struct produtos tab_produtos[], int tl_produtos, int codigo)
{
    int posicao;
    for (int i=0; i<tl_produtos; i++)
    {
        if (tab_produtos[i].codigo==codigo)
        {
            posicao=i;
            i=tl_produtos;
        }
    }
    return posicao;
}


int menu_alterar()
{
    int opcao;
    printf("Escolha uma opção:\n");
    printf("1. Alterar nome do produto\n");
    printf("2. Alterar preço do produto\n");
    printf("3. Alterar estoque do produto\n");
    printf("0. Voltar ao menu\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    return opcao;
}

void executar_opcao(struct produtos tab_produtos[], int posicao, int opcao)
{
    switch (opcao)
    {
    case 1:
        printf("Digite o novo nome do produto: \n");
        preencher_nome_produto(tab_produtos, posicao);
        printf ("Mudança feita\n");
        break;
    case 2:
        tab_produtos[posicao].preco = coletar_preco_produto();
        printf ("Mudança feita\n");

        break;
    case 3:
        tab_produtos[posicao].estoque = coletar_estoque_produto();
        printf ("Mudança feita\n");
        break;
    case 0:
        break;
    default:
        printf("Opção inválida\n");
        break;
    }
}

void alterar_produto(struct produtos tab_produtos[], int tl_produtos)
{
    int codigo = selecionar_produto(tab_produtos, tl_produtos);
    int posicao = encontrar_posicao_produto(tab_produtos, tl_produtos, codigo);
    int opcao;
    do
    {
        system("cls");
        opcao = menu_alterar();
        executar_opcao(tab_produtos, posicao, opcao);
    }
    while (opcao != 0);
}

//exercicio 2 - final

//----------------------------------------------------------------------------------------------------------------------

//exercicio 4 - inicio

int pesquisar_produto_por_codigo(struct produtos tab_produtos[], int tl_produtos)
{
    int codigo = selecionar_produto(tab_produtos, tl_produtos);
    int posicao = encontrar_posicao_produto(tab_produtos, tl_produtos, codigo);
    return posicao;
}

void apresentar_produto(struct produtos tab_produtos[], int posicao)
{
    printf("Nome: %s\n", tab_produtos[posicao].nome);
    printf("Preço: %.2f\n", tab_produtos[posicao].preco);
    printf("Estoque: %d\n", tab_produtos[posicao].estoque);
}

void pesquisar_produto_pelo_codigo(struct produtos tab_produtos[], int tl_produtos)
{
    int posicao = pesquisar_produto_por_codigo(tab_produtos, tl_produtos);
    apresentar_produto(tab_produtos, posicao);
}

//exercicio 4 - final

//----------------------------------------------------------------------------------------------------------------------

//exercicio 5 - inicio


int obter_quantidade_comprada()
{
    int qnt;
    qnt = ler_estoque_produto();
    return qnt;
}

void atualizar_estoque(struct produtos tab_produtos[], int posicao, int quantidade_comprada)
{
    tab_produtos[posicao].estoque += quantidade_comprada;
}

void adicionar_produtos_estoque(struct produtos tab_produtos[], int tl_produtos)
{
    int codigo = selecionar_produto(tab_produtos, tl_produtos);
    int posicao = encontrar_posicao_produto(tab_produtos, tl_produtos, codigo);
    int quantidade_comprada = obter_quantidade_comprada();
    atualizar_estoque(tab_produtos, posicao, quantidade_comprada);
}

//exercicio 5 - final

//----------------------------------------------------------------------------------------------------------------------

//exercicio 6 - inicio

void apresentar_informacoes_produto(struct produtos produto)
{
    printf("Código %d\n", produto.codigo);
    printf("Nome: %s\n", produto.nome);
    printf("Preço: %.2f\n", produto.preco);
    printf("Estoque: %d\n", produto.estoque);
    printf("\n");
}

void apresentar_todos_produtos_informacao(struct produtos tab_produtos[], int tl_produtos)
{
    for (int i = 0; i < tl_produtos; i++)
    {
        apresentar_informacoes_produto(tab_produtos[i]);
    }
}

//exercicio 6 - final

//----------------------------------------------------------------------------------------------------------------------

//exercicio 7 - inicio

float calcular_valor_estoque_produto(struct produtos produto)
{
    return produto.preco * produto.estoque;
}

float calcular_valor_total_estoque(struct produtos tab_produtos[], int tl_produtos)
{
    float valor_total_estoque = 0.0;

    for (int i = 0; i < tl_produtos; i++)
    {
        valor_total_estoque += calcular_valor_estoque_produto(tab_produtos[i]);
    }

    return valor_total_estoque;
}

int calcular_estoque_total(struct produtos tab_produtos[], int tl_produtos)
{
    int estoque_total = 0;

    for (int i = 0; i < tl_produtos; i++)
    {
        estoque_total += tab_produtos[i].estoque;
    }

    return estoque_total;
}

void apresentar_valor_total_estoque_e_estoque_total(float valor_total_estoque, int estoque_total)
{
    printf("Total valor em estoque: %.2f\n", valor_total_estoque);
    printf("Produtos totais em estoque: %d\n", estoque_total);
}

void apresentar_informacoes_produto_com_valor_estoque(struct produtos produto)
{
    float valor_estoque = calcular_valor_estoque_produto(produto);
    printf("Código %d\n", produto.codigo);
    printf("Nome: %s\n", produto.nome);
    printf("Preço: %.2f\n", produto.preco);
    printf("Estoque: %d\n", produto.estoque);
    printf("Valor em estoque: %.2f\n", valor_estoque);
    printf("\n");
}

void calcular_e_apresentar_balanco_estoque(struct produtos tab_produtos[], int tl_produtos)
{
    float valor_total_estoque = calcular_valor_total_estoque(tab_produtos, tl_produtos);
    int estoque_total = calcular_estoque_total(tab_produtos, tl_produtos);
    for (int i = 0; i < tl_produtos; i++)
    {
        apresentar_informacoes_produto_com_valor_estoque(tab_produtos[i]);
    }
    apresentar_valor_total_estoque_e_estoque_total(valor_total_estoque, estoque_total);
}

//exercicio 7 - final

//----------------------------------------------------------------------------------------------------------------------

//exercicio 8 - inicio


int estoque_esta_abaixo_limite(int estoque, int limite)
{
    return estoque < limite;
}

void exibir_produto(struct produtos tab_produtos)
{
    printf("Código: %d\n", tab_produtos.codigo);
    printf("Estoque: %d\n", tab_produtos.estoque);
    printf("\n");
}

void apresentar_produtos_estoque_baixo(struct produtos tab_produtos[], int tl_produtos)
{
    int limite = 5;
    for (int i = 0; i < tl_produtos; i++)
    {
        if (estoque_esta_abaixo_limite(tab_produtos[i].estoque, limite))
        {
            exibir_produto(tab_produtos[i]);
        }
    }
}

//exercicio 8 - final
//----------------------------------------------------------------------------------------------------------------------


