#define TF 20
#define NOME 101


struct vendas
{
    int codigo_produto;
    int dia;
    int mes;
    int ano;
    int qnt_vendido;
};

//----------------------------------------------------------------------------------------------------------------------
//exercicio 9 - inicio

int ler_dia()
{
    int dia;
    printf("Digite o dia: ");
    dia = ler_inteiro();
    return dia;
}

int validar_dia(int dia, int mes, int ano)
{
    int dia_valido = 1;

    if (! (dia >= 1 && dia <= 31))
    {
        printf("Dia inválido. Insira um valor entre 1 e 31.\n");
        dia_valido = 0;
    }
    else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    {
        printf("Dia inválido para este mês. Insira um valor entre 1 e 30.\n");
        dia_valido = 0;
    }
    else if (mes == 2)
    {
        if ((ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)))
        {
            if (dia > 29)
            {
                printf("Dia inválido para fevereiro em ano bissexto. Insira um valor entre 1 e 29.\n");
                dia_valido = 0;
            }
        }
        else if (dia > 28)
        {
            printf("Dia inválido para fevereiro. Insira um valor entre 1 e 28.\n");
            dia_valido = 0;
        }
    }
    else if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31)
    {
        printf("Dia inválido para este mês. Insira um valor entre 1 e 31.\n");
        dia_valido = 0;
    }

    return dia_valido;
}


int coletar_dia(int ano, int mes)
{
    int dia;
    int valido = 1;

    do
    {
        dia = ler_dia();
        valido = validar_dia(dia, mes, ano);
    }
    while (valido!=1);

    return dia;
}

int ler_mes()
{
    int mes;
    printf("Digite o mês: ");
    mes = ler_inteiro();
    return mes;
}

int validar_mes(int mes)
{
    int mes_valido = 1;

    if (mes < 1 || mes > 12)
    {
        printf("Mês inválido. Insira um valor entre 1 e 12.\n");
        mes_valido = 0;
    }

    return mes_valido;
}

int coletar_mes()
{
    int mes;
    int valido = 1;

    do
    {
        mes = ler_mes();
        valido = validar_mes(mes);
    }
    while (valido!=1);

    return mes;
}

int ler_ano()
{
    int ano;
    printf("Digite o ano: ");
    ano = ler_inteiro();
    return ano;
}

int validar_ano(int ano)
{
    int ano_valido = 1;

    if (ano <= 0)
    {
        printf("Ano inválido. Insira um valor maior ou igual a 0.\n");
        ano_valido = 0;
    }

    return ano_valido;
}

int coletar_ano()
{
    int ano;
    int valido = 1;

    do
    {
        ano = ler_ano();
        valido = validar_ano(ano);
    }
    while (valido!=1);

    return ano;
}

void preencher_tabela_data(struct vendas tab_vendas[], int tl_vendas)
{
    int ano=coletar_ano();
    int mes=coletar_mes();
    int dia=coletar_dia(ano, mes);
    tab_vendas[tl_vendas].ano = ano;
    tab_vendas[tl_vendas].mes = mes;
    tab_vendas[tl_vendas].dia = dia;
}

int ler_quantidade_vendida()
{
    int quantidade;
    printf("Digite a quantidade de produtos a ser vendida: ");
    quantidade = ler_inteiro();
    return quantidade;
}

int validar_quantidade(struct produtos tab_produtos[], int tl_produtos, int codigo, int quantidade)
{
    int quantidade_valida = 1;
    int posicao = encontrar_posicao_produto(tab_produtos, tl_produtos, codigo);
    int estoque = tab_produtos[posicao].estoque;

    if (quantidade < 1 || quantidade > estoque)
    {
        printf("Quantidade inválida. Insira um valor entre 1 e %d.\n", estoque);
        quantidade_valida = 0;
    }

    return quantidade_valida;
}

int coletar_quantidade_vendida(struct produtos tab_produtos[], int tl_produtos, int codigo)
{
    int quantidade;
    int valido = 1;

    do
    {
        quantidade = ler_quantidade_vendida();
        valido = validar_quantidade(tab_produtos, tl_produtos, codigo, quantidade);
    }
    while (valido == 0);

    return quantidade;
}

float calcular_total_venda(struct produtos tab_produtos[], int tl_produtos, int codigo, int quantidade)
{
    int posicao = encontrar_posicao_produto(tab_produtos, tl_produtos, codigo);
    float preco_unitario = tab_produtos[posicao].preco;
    float total_venda = preco_unitario * quantidade;

    tab_produtos[posicao].estoque -= quantidade;

    return total_venda;
}

int selecionar_produto_venda (struct produtos tab_produtos[], int tl_produtos)
{
    int op;
    int valido = 1;
    int produto_encontrado;

    printf ("Digite o código do produto com que deseja trabalhar: \n");
    op=ler_inteiro();
    produto_encontrado = 0;
    for (int i=0; i<tl_produtos; i++)
    {
        if (tab_produtos[i].codigo==op)
        {
            produto_encontrado = 1;
        }
    }
    if (!produto_encontrado)
    {
        op=-1;
    }
    return op;
}



void incluir_venda(struct produtos tab_produtos[], struct vendas tab_vendas[], int tl_produtos, int *tl_vendas)
{

    if (tl_produtos > 0)
    {

        if (*tl_vendas < TF)
        {


            int codigo = selecionar_produto_venda(tab_produtos, tl_produtos);
            if (codigo==-1)
            {

                printf ("Produto inexistente\n");
            }
            else
            {

                int quantidade = coletar_quantidade_vendida(tab_produtos, tl_produtos, codigo);

                tab_vendas[*tl_vendas].codigo_produto = codigo;
                tab_vendas[*tl_vendas].qnt_vendido = quantidade;

                preencher_tabela_data(tab_vendas, *tl_vendas);
                (*tl_vendas)++;



                float total_venda = calcular_total_venda(tab_produtos, tl_produtos, codigo, quantidade);
                printf("Total da venda: R$ %.2f\n", total_venda);
            }
        }
        else
        {
            printf("A tabela de vendas está cheia.\n");
        }

    }
    else
    {
        printf ("Nenhum produto incluido, impossvel realizar venda\n");
    }
}


//exercicio 9 - final
//----------------------------------------------------------------------------------------------------------------------

//exercicio 10 - inicio

void imprimir_data_produto(int dia, int mes, int ano)
{
    printf("Data: %d/%d/%d\n", dia, mes, ano);
}

void imprimir_quantidade_vendida(int qnt_vendido)
{
    printf("Quantidade vendida: %d\n", qnt_vendido);
}

void imprimir_valor_venda(float valor_venda)
{
    printf("Valor total: %.2f\n", valor_venda);
}

void preencher_tabela_vendas(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas, int codigo)
{
    for (int i = 0; i < tl_vendas; i++)
    {
        if (tab_vendas[i].codigo_produto == codigo)
        {
            imprimir_data_produto(tab_vendas[i].dia, tab_vendas[i].mes, tab_vendas[i].ano);
            imprimir_quantidade_vendida(tab_vendas[i].qnt_vendido);

            float valor_venda = tab_vendas[i].qnt_vendido * tab_produtos[encontrar_posicao_produto(tab_produtos, tl_produtos, codigo)].preco;
            imprimir_valor_venda(valor_venda);
        }
    }
}

float calcular_valor_total_vendas(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas, int codigo)
{
    float valor_total_vendas = 0;

    for (int i = 0; i < tl_vendas; i++)
    {
        if (tab_vendas[i].codigo_produto == codigo)
        {
            valor_total_vendas += tab_vendas[i].qnt_vendido * tab_produtos[encontrar_posicao_produto(tab_produtos, tl_produtos, codigo)].preco;
        }
    }

    return valor_total_vendas;
}


void apresentar_vendas_produto(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas)
{
    if (tl_vendas > 0)
    {
        int codigo = selecionar_produto_venda(tab_produtos, tl_produtos);
        if (codigo==-1)
        {

            printf ("Produto inexistente\n");
        }
        else
        {


            printf("Vendas do Produto %d:\n", codigo);

            preencher_tabela_vendas(tab_vendas, tab_produtos, tl_produtos, tl_vendas, codigo);

            float valor_total_vendas = calcular_valor_total_vendas(tab_vendas, tab_produtos, tl_produtos, tl_vendas, codigo);

            printf("Valor total de vendas para o Produto %d: %.2f\n", codigo, valor_total_vendas);
        }
    }

    else
    {
        printf ("Nenhuma venda\n");
    }
}

//exercicio 10 - final

//----------------------------------------------------------------------------------------------------------------------

//exercicio 11 - inicio

float calcular_total_venda2(struct vendas venda, struct produtos tab_produtos[], int tl_produtos)
{
    float valor_venda_produto = 0.0;

    for (int j = 0; j < tl_produtos; j++)
    {
        if (tab_produtos[j].codigo == venda.codigo_produto)
        {
            valor_venda_produto = venda.qnt_vendido * tab_produtos[j].preco;
        }
    }

    return valor_venda_produto;
}


void apresentar_vendas_em_data(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas, int dia, int mes, int ano)
{
    float valor_venda_dia = 0.0;

    for (int i = 0; i < tl_vendas; i++)
    {
        if (tab_vendas[i].dia == dia && tab_vendas[i].mes == mes && tab_vendas[i].ano == ano)
        {
            valor_venda_dia += calcular_total_venda2(tab_vendas[i], tab_produtos, tl_produtos);
        }
    }

    printf("Valor total das vendas nessa data: %.2f\n", valor_venda_dia);
}

void apresentar_detalhes_vendas_por_data(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas, int dia, int mes, int ano)
{
    printf("Detalhes das vendas na data %02d/%02d/%04d:\n", dia, mes, ano);

    for (int i = 0; i < tl_vendas; i++)
    {
        if (tab_vendas[i].dia == dia && tab_vendas[i].mes == mes && tab_vendas[i].ano == ano)
        {
            int codigo_produto = tab_vendas[i].codigo_produto;
            int quantidade_vendida = tab_vendas[i].qnt_vendido;
            float valor_venda_produto = calcular_total_venda2(tab_vendas[i], tab_produtos, tl_produtos);

            printf("Código do produto: %d\n", codigo_produto);
            printf("Quantidade vendida: %d\n", quantidade_vendida);
            printf("Total de vendas do produto: %.2f\n", valor_venda_produto);
            printf("\n");
        }
    }
}

void apresentar_vendas_dia(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas)
{
    int dia, mes, ano;
    ano=coletar_ano();
    mes=coletar_mes();
    dia=coletar_dia(ano, mes);

    apresentar_detalhes_vendas_por_data(tab_vendas, tab_produtos, tl_produtos, tl_vendas, dia, mes, ano);
    apresentar_vendas_em_data(tab_vendas, tab_produtos, tl_produtos, tl_vendas, dia, mes, ano);
}

//exercicio 11- final
//----------------------------------------------------------------------------------------------------------------------

//exercicio 12- inicio

int calcular_quantidade_total_vendida(struct vendas tab_vendas[], int tl_vendas, int codigo_produto)
{
    int total_vendido = 0;
    for (int j = 0; j < tl_vendas; j++)
    {
        if (tab_vendas[j].codigo_produto == codigo_produto)
        {
            total_vendido += tab_vendas[j].qnt_vendido;
        }
    }
    return total_vendido;
}

void apresentar_vendas_todos_produtos(struct produtos tab_produtos[], struct vendas tab_vendas[], int tl_produtos, int tl_vendas)
{
    if (tl_vendas>0)
    {
        for (int i = 0; i < tl_produtos; i++)
        {
            int total_vendido = calcular_quantidade_total_vendida(tab_vendas, tl_vendas, i + 1);
            printf("Quantidade vendida produto %d: %d\n", i + 1, total_vendido);
        }
    }
    else
    {
        printf ("Nenhuma venda\n");
    }
}

//exercicio 12 - final

//----------------------------------------------------------------------------------------------------------------------

//exercicio 13 - inicio

void apresentar_detalhes_vendas_por_mes(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas, int mes, int ano)
{
    printf("Detalhes das vendas no mês %02d/%04d:\n", mes, ano);

    for (int i = 0; i < tl_vendas; i++)
    {
        if (tab_vendas[i].mes == mes && tab_vendas[i].ano == ano)
        {
            int codigo_produto = tab_vendas[i].codigo_produto;
            int quantidade_vendida = tab_vendas[i].qnt_vendido;
            float valor_venda_produto = calcular_total_venda2(tab_vendas[i], tab_produtos, tl_produtos);

            printf("Código do produto: %d\n", codigo_produto);
            printf("Quantidade vendida: %d\n", quantidade_vendida);
            printf("Total de vendas do produto: %.2f\n", valor_venda_produto);
            printf("\n");
        }
    }
}

void apresentar_vendas_em_mes(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas, int mes, int ano)
{
    float valor_venda_mes = 0.0;

    for (int i = 0; i < tl_vendas; i++)
    {
        if (tab_vendas[i].mes == mes && tab_vendas[i].ano == ano)
        {
            valor_venda_mes += calcular_total_venda2(tab_vendas[i], tab_produtos, tl_produtos);
        }
    }

    printf("Valor total das vendas no mês %02d/%04d: %.2f\n", mes, ano, valor_venda_mes);
}



void apresentar_vendas_mes(struct vendas tab_vendas[], struct produtos tab_produtos[], int tl_produtos, int tl_vendas)
{
    int mes, ano;
    mes = coletar_mes();
    ano = coletar_ano();

    apresentar_detalhes_vendas_por_mes(tab_vendas, tab_produtos, tl_produtos, tl_vendas, mes, ano);
    apresentar_vendas_em_mes(tab_vendas, tab_produtos, tl_produtos, tl_vendas, mes, ano);
}

//exercicio 13 - final


//----------------------------------------------------------------------------------------------------------------------

//exercicio 3 - inicio

void excluir_produto_se_nao_vendido(struct produtos tab_produtos[], struct vendas tab_vendas[], int *tl_produtos, int tl_vendas)
{
    int codigo_a_excluir = selecionar_produto(tab_produtos, *tl_produtos);
    int posicao = encontrar_posicao_produto(tab_produtos, *tl_produtos, codigo_a_excluir);
    int produto_foi_vendido = 0;
    for (int j = 0; j < tl_vendas && !produto_foi_vendido; j++)
    {
        if (tab_vendas[j].codigo_produto == codigo_a_excluir && tab_vendas[j].qnt_vendido > 0)
        {
            produto_foi_vendido = 1;
        }
    }

    if (produto_foi_vendido)
    {
        printf("Produto com código %d não pode ser excluído, pois foi vendido.\n", codigo_a_excluir);
    }
    else
    {
        for (int k = posicao; k < (*tl_produtos) - 1; k++)
        {
            tab_produtos[k] = tab_produtos[k + 1];
        }
        (*tl_produtos)--;
        printf("Produto com código %d foi excluído.\n", codigo_a_excluir);
    }
}

//exercicio 3 - final
//----------------------------------------------------------------------------------------------------------------------


