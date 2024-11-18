#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TF 30

struct registros
{
    char nome_usuario[100];
    char nome_usuario_completo[100];
    char senha_criptografada[20];
    char diretorio[30];
    char shell[50];
    char UID[20];
    char GID[20];
};

void abrir_arquivo(FILE **arquivo)
{
    *arquivo = fopen("../passwd-exerc3.txt", "r");
}

void voltar_ao_inicio(FILE *arquivo)
{
    rewind(arquivo);
}

void fechar_arquivo(FILE *arquivo)
{
    fclose(arquivo);
}

void ler_informacoes(FILE *arquivo, struct registros tab_registros[])
{
    abrir_arquivo(&arquivo);

    if (arquivo == NULL)
    {
        printf("Falha ao abrir o arquivo\n");
    }
    else
    {
        int i = 0;
        char linha[256];
        char *inicio, *fim;

        while (fgets(linha, sizeof(linha), arquivo))
        {
            int j = 0;
            inicio = linha;

            while (j < 7)
            {
                fim = strchr(inicio, ':');
                if (fim != NULL)
                {
                    *fim = '\0';
                }

                char *pos;
                if ((pos = strchr(inicio, '\n')) != NULL)
                    *pos = '\0';

                switch (j)
                {
                case 0:
                    strcpy(tab_registros[i].nome_usuario, inicio);
                    break;
                case 1:
                    strcpy(tab_registros[i].senha_criptografada, inicio);
                    break;
                case 2:
                    strcpy(tab_registros[i].UID, inicio);
                    break;
                case 3:
                    strcpy(tab_registros[i].GID, inicio);
                    break;
                case 4:
                    strcpy(tab_registros[i].nome_usuario_completo, inicio);
                    break;
                case 5:
                    strcpy(tab_registros[i].diretorio, inicio);
                    break;
                case 6:
                    strcpy(tab_registros[i].shell, inicio);
                    break;
                }

                if (fim != NULL)
                {
                    inicio = fim + 1;
                }

                j++;
            }

            if (strlen(tab_registros[i].diretorio) == 0)
            {
                strcpy(tab_registros[i].diretorio, "(vazio)");
            }

            if (strlen(tab_registros[i].nome_usuario_completo) == 0)
            {
                strcpy(tab_registros[i].nome_usuario_completo, "(vazio)");
            }

            if (strlen(tab_registros[i].shell) == 0)
            {
                strcpy(tab_registros[i].shell, "(vazio)");
            }

            i++;
        }

        fechar_arquivo(arquivo);
    }
}

int contar_linhas(FILE *arquivo)
{
    int valido = 0;
    char c;
    int cont = 0;
    abrir_arquivo(&arquivo);
    voltar_ao_inicio(arquivo);

    while (valido != 1)
    {
        c = fgetc(arquivo);
        if (c == EOF)
        {
            cont++;
            valido = 1;
        }
        else if (c == '\n')
        {
            cont++;
        }
    }

    fechar_arquivo(arquivo);

    return cont;
}

int validar_inteiro()
{
    int i;
    int valido = 1;
    while (valido != 0)
    {
        scanf("%d", &i);
        if (i < 0)
        {
            printf("Digite um número positivo: ");
            valido = 1;
        }
        else
        {
            valido = 0;
        }
    }
    return i;
}

void preencher_usuario(struct registros tab_registros[], int tl_usuarios)
{
    printf("Digite o nome do usuário: \n");
    scanf(" %99[^\n]", tab_registros[tl_usuarios].nome_usuario);
    printf("Digite a senha criptografada: \n");
    scanf(" %19[^\n]", tab_registros[tl_usuarios].senha_criptografada);

    printf("Digite o número do ID do usuário: \n");
    scanf(" %19s", tab_registros[tl_usuarios].UID);

    printf("Digite o número do ID do grupo em que o usuário está inserido: \n");
    scanf(" %19s", tab_registros[tl_usuarios].GID);

    printf("Digite o nome completo do usuário: \n");
    scanf(" %99[^\n]", tab_registros[tl_usuarios].nome_usuario_completo);
    printf("Digite o diretório de origem: \n");
    scanf(" %29[^\n]", tab_registros[tl_usuarios].diretorio);
    printf("Digite o login de shell: \n");
    scanf(" %49[^\n]", tab_registros[tl_usuarios].shell);

    printf("Usuário adicionado com sucesso\n");
}

void adicionar_usuario(struct registros tab_registros[], int *tl_usuarios)
{
    if (*tl_usuarios < TF)
    {
        preencher_usuario(tab_registros, *tl_usuarios);
        (*tl_usuarios)++;
    }
    else
    {
        printf("Capacidade máxima de usuários, não é possível adicionar\n");
    }
}

void menu_users(struct registros tab_registros[], int tl_usuarios)
{
    int i;
    printf("Ordem de inserção:\n");
    for (i = 0; i < tl_usuarios; i++)
    {
        printf("%d-%s\n", i, tab_registros[i].nome_usuario);
    }
    printf ("\n");
}

int validar_pesquisa(int tl_usuarios)
{
    int valido;
    int i;
    scanf("%d", &i);
    if (i < 0)
    {
        valido = -1;
    }
    else if (i >= tl_usuarios)
    {
        valido = -1;
    }
    else
    {
        valido = i;
    }
    return valido;
}

void apresentar_pesquisa(struct registros tab_registros[], int opcao)
{
    printf ("%s:%s:%s:%s:%s:%s:%s\n", tab_registros[opcao].nome_usuario, tab_registros[opcao].senha_criptografada, tab_registros[opcao].UID, tab_registros[opcao].GID,tab_registros[opcao].nome_usuario_completo, tab_registros[opcao].diretorio, tab_registros[opcao].shell );
    printf("Nome do usuário: %s\n", tab_registros[opcao].nome_usuario);
    printf("Senha criptografada: %s\n", tab_registros[opcao].senha_criptografada);
    printf("UID: %s\n", tab_registros[opcao].UID);
    printf("GID: %s\n", tab_registros[opcao].GID);
    printf("Nome completo do usuário: %s\n", tab_registros[opcao].nome_usuario_completo);
    printf("Diretório: %s\n", tab_registros[opcao].diretorio);
    printf("Shell: %s\n", tab_registros[opcao].shell);
    printf("\n");
}

void pesquisar_usuario(struct registros tab_registros[], int tl_usuarios)
{
    int opcao;
    printf("Escolha o número referente ao usuário (ordem de inserção):\n");
    menu_users(tab_registros, tl_usuarios);
    opcao = validar_pesquisa(tl_usuarios);
    if (opcao == -1)
    {
        printf("Número inválido\n");
    }
    else
    {
        apresentar_pesquisa(tab_registros, opcao);
    }
}

int menu_alterar()
{
    int opcao;
    printf("Escolha uma opçãoo:\n");
    printf("1. Alterar nome do usuário\n");
    printf("2. Alterar senha criptografada \n");
    printf("3. Alterar ID do usuário\n");
    printf("4. Alterar ID do grupo\n");
    printf("5. Alterar nome completo do usuário\n");
    printf("6. Alterar diretório do usuário\n");
    printf("7. Alterar login do shell do usuário\n");
    printf("0. Voltar\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    return opcao;
}

void executar_opcao(struct registros tab_registros[], int opcao)
{
    int escolha;
    do
    {
        escolha = menu_alterar();
        switch (escolha)
        {
        case 1:
            printf("Digite o nome do usuário: \n");
            scanf(" %99[^\n]", tab_registros[opcao].nome_usuario);
            printf("Mudança feita\n");
            break;
        case 2:
            printf("Digite a senha criptografada: \n");
            scanf(" %19[^\n]", tab_registros[opcao].senha_criptografada);
            printf("Mudança feita\n");
            break;
        case 3:
            printf("Digite o número do ID do usuário: \n");
            scanf(" %9s", tab_registros[opcao].UID);
            printf("Mudança feita\n");
            break;
        case 4:
            printf("Digite o número do ID do grupo em que o usuário está inserido: \n");
            scanf(" %9s", tab_registros[opcao].GID);
            printf("Mudança feita\n");
            break;
        case 5:
            printf("Digite o nome completo do usuário: \n");
            scanf(" %99[^\n]", tab_registros[opcao].nome_usuario_completo);
            printf("Mudança feita\n");
            break;
        case 6:
            printf("Digite o diretório do usuário: \n");
            scanf(" %29[^\n]", tab_registros[opcao].diretorio);
            printf("Mudança feita\n");
            break;
        case 7:
            printf("Digite o login do shell do usuário: \n");
            scanf(" %49[^\n]", tab_registros[opcao].shell);
            printf("Mudança feita\n");
            break;
        case 0:
            printf("Processo encerrado\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
        }

    } while (escolha != 0);
}

void modificar_usuario(struct registros tab_registros[], int tl_usuarios)
{
    int opcao;
    printf("Escolha o número referente ao usuário (ordem de inserção):\n");
    menu_users(tab_registros, tl_usuarios);
    opcao = validar_pesquisa(tl_usuarios);
    if (opcao == -1)
    {
        printf("Número inválido\n");
    }
    else
    {
        do
        {
            system("cls");
            executar_opcao(tab_registros, opcao);
        } while (opcao != 0);
    }
}

void excluir_usuario(struct registros tab_registros[], int *tl_usuarios)
{
    int opcao;
    printf("Escolha o número referente ao usuário (ordem de inserção):\n");
    menu_users(tab_registros, *tl_usuarios);
    opcao = validar_pesquisa(*tl_usuarios);
    if (opcao == -1)
    {
        printf("Número inválido\n");
    }
    else
    {
        for (int i = opcao; i < *tl_usuarios - 1; ++i)
        {
            tab_registros[i] = tab_registros[i + 1];
        }
        (*tl_usuarios)--;
        printf("Usuário excluido\n");
    }
}

void listar_usuarios(struct registros tab_registros[], int tl_usuarios)
{
    for (int i = 0; i < tl_usuarios; i++)
    {
        apresentar_pesquisa(tab_registros, i);
        printf("----------------------------\n");
    }
}

void exportar_dados(FILE *destino, struct registros tab_registros[], int tl_usuarios)
{
    destino = fopen("../dados.txt", "w");
    if (destino == NULL)
    {
        printf("Arquivo inexistente\n");
    }
    else
    {
        for (int i = 0; i < tl_usuarios; i++)
        {
            fprintf(destino, "%s:%s:%s:%s:%s:%s:%s\n", tab_registros[i].nome_usuario, tab_registros[i].senha_criptografada, tab_registros[i].UID, tab_registros[i].GID, tab_registros[i].nome_usuario_completo, tab_registros[i].diretorio, tab_registros[i].shell);
        }
    }
    fclose(destino);
    printf("Exportação completa, favor conferir dados.txt\n");
    printf("Finaizando programa\n");
};

int menu()
{
    int op;
    do
    {
        printf("CONFIGURAÇÕES LINUX USERS: \n");
        printf("ESCOLHA:\n");
        printf("1 - Adicionar usuário\n");
        printf("2 - Pesquisar usuário\n");
        printf("3 - Modificar usuário\n");
        printf("4 - Remover usuário\n");
        printf("5 - Listar usuários\n");
        printf("6 - Exportar dados para dados.txt e fechar programa\n");

        printf("Digite a opção: ");
        scanf("%d", &op);
        printf("\n");

        if (op < 1 || op > 6)
        {
            printf("Opção inválida!!!\n");
        }
    } while (op < 1 || op > 6);

    return op;
}

int main()
{
    setlocale(LC_ALL, "");
    FILE *arquivo;
    FILE *destino;
    struct registros tab_registros[TF];
    ler_informacoes(arquivo, tab_registros);
    int tl_usuarios = contar_linhas(arquivo);
    int opcao;

    do
    {
        system("cls");
        opcao = menu();

        switch (opcao)
        {
        case 1:
            adicionar_usuario(tab_registros, &tl_usuarios);
            break;

        case 2:
            pesquisar_usuario(tab_registros, tl_usuarios);
            break;

        case 3:
            modificar_usuario(tab_registros, tl_usuarios);
            break;

        case 4:
            excluir_usuario(tab_registros, &tl_usuarios);
            break;

        case 5:
            listar_usuarios(tab_registros, tl_usuarios);
            break;
        case 6:
            exportar_dados(destino, tab_registros, tl_usuarios);
            break;

        default:
            break;
        }
        system("pause");
    } while (opcao != 6);

    return 0;
}
