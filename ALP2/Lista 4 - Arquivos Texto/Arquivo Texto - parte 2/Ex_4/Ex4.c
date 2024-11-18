#include <stdio.h>
#include <locale.h>

#define TF 10

struct dados
{
    char nome_produto[50];
    int qnt_vendida;
    float preco;
    int numero_nota;
    int itens_tipos;
    int total_unidades_vendidas;
    char CPF[15];
    char nome[50];
    float total_produto;
    float total_tudo;
};


void abrir_arquivo(FILE **arquivo, FILE **destino)
{
    *arquivo = fopen("notafiscal_origem.txt", "r");
    *destino = fopen("notafiscal_destino.txt", "w");
}

void fechar_arquivo(FILE *arquivo, FILE *destino)
{
    fclose(arquivo);
    fclose(destino);
}

/*void ler_dados(FILE *arquivo, struct dados tab_dados[])
{
    int i;
    fscanf(arquivo, "%d\n", &tab_dados[0].numero_nota);
    fscanf(arquivo, "%s %[^\n]\n%d\n", tab_dados[0].CPF, tab_dados[0].nome, &tab_dados[0].itens_tipos);
    for (i = 0; i < tab_dados[0].itens_tipos; i++)
    {
        fscanf(arquivo, " %[^\n]\n%d %f\n", tab_dados[i].nome_produto, &tab_dados[i].qnt_vendida, &tab_dados[i].preco);
    }
}*/


void ler_dados (FILE *arquivo, struct dados tab_dados[])
{
int i;

fscanf (arquivo, "%d\n", &tab_dados[0].numero_nota);
fscanf (arquivo, "%s ", tab_dados[0].CPF); //espaço após leitura

//%s só lê uma única palavra
//para ler uma palavra separada por espaços
//ou utiliza o fgets (se deseja ler o restante da linha) ou %[^?] - considere '?' como um caractere a ser definido. Se ler até quebra de linha %[^\n]. Até dois pontos [^':'].
//visto que O segundo metódo é considerado gambiarra, irei implementar o fgets a partir do ponto em que o arquivo está

fgets (tab_dados[0].nome, sizeof(tab_dados[0].nome), arquivo);
fscanf (arquivo, "%d\n", &tab_dados[0].itens_tipos);
for (i=0;i<tab_dados[0].itens_tipos;i++)
{
fgets(tab_dados[i].nome_produto, sizeof(tab_dados[i].nome_produto), arquivo);
fscanf(arquivo, "%d %f\n", &tab_dados[i].qnt_vendida, &tab_dados[i].preco);
}

}


void linhas_duplas(FILE *destino)
{
    for (int i = 0; i < 50; i++)
    {
        fprintf(destino, "=");
    }
    fprintf(destino, "\n");
}

void espacos(FILE *destino)
{
    for (int i = 0; i < 35; i++)
        fprintf(destino, " ");
}

void linhas(FILE *destino)
{
    for (int i = 0; i < 50; i++)
    {
        fprintf(destino, "-");
    }
    fprintf(destino, "\n");
}

void calcular_total_produto(struct dados tab_dados[])
{
    for (int i = 0; i < tab_dados[0].itens_tipos; i++)
    {
        tab_dados[i].total_produto = tab_dados[i].qnt_vendida * tab_dados[i].preco;
    }
}

void calcular_total_vendido(struct dados tab_dados[])
{
    for (int i = 0; i < tab_dados[0].itens_tipos; i++)
    {
        tab_dados[0].total_unidades_vendidas += tab_dados[i].qnt_vendida;
    }
}

void calcular_total_tudo(struct dados tab_dados[])
{
    for (int i = 0; i < tab_dados[0].itens_tipos; i++)
    {
        tab_dados[0].total_tudo += tab_dados[i].total_produto;
    }
}

void calcular(struct dados tab_dados[])
{
    calcular_total_produto(tab_dados);
    calcular_total_vendido(tab_dados);
    calcular_total_tudo(tab_dados);
}

void exportar_dados(FILE *destino, struct dados tab_dados[])
{
    fprintf(destino, "Nota fiscal de Venda - nr.: %d\n", tab_dados[0].numero_nota);
    linhas_duplas(destino);
    fprintf(destino, "Cliente: %s\nCPF: %s\n", tab_dados[0].nome, tab_dados[0].CPF);
    linhas_duplas(destino);
    fprintf(destino, "Produtos:\nSeq Nome");
    espacos(destino);
    fprintf(destino, "QTE    Preco    Total\n");
    linhas (destino);
    for (int i = 0; i < tab_dados[0].itens_tipos; i++)
    {
        fprintf(destino, "%3d %-30s %5d %8.2f %8.2f\n",
                i+1, tab_dados[i].nome_produto, tab_dados[i].qnt_vendida, tab_dados[i].preco, tab_dados[i].total_produto);
    }
    linhas_duplas(destino);
    fprintf(destino, "Quantidade de itens vendidos ...: %d\nQuantidade total de produtos ...: %d\nValor total da venda............: R$ %.2f\n", tab_dados[0].itens_tipos, tab_dados[0].total_unidades_vendidas, tab_dados[0].total_tudo);
    linhas_duplas(destino);
}


void processar(struct dados tab_dados[])
{
    FILE *arquivo;
    FILE *destino;
    abrir_arquivo(&arquivo, &destino);
    if (arquivo == NULL || destino == NULL)
    {
        printf("Arquivos n�o encontrados\n");
    }
    else
    {
        ler_dados(arquivo, tab_dados);
        calcular(tab_dados);
        exportar_dados(destino, tab_dados);
        printf("Nota fiscal gerada\n");
    }
    fechar_arquivo(arquivo, destino);
}

int main()
{
    setlocale(LC_ALL, "english");//para leitura do "."
    struct dados tab_dados[TF];
    processar(tab_dados);
    return 0;
}
