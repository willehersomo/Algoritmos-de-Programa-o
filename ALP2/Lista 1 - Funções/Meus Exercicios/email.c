#include <stdio.h>
#include <locale.h>
#define TF 50



void apresentar_nome_usuario(char email[], char usuario[])
{
    int i;
    for (i = 0; i < TF && email[i] != '@'; i++)
    {
        usuario[i] = email[i];
    }
    usuario[i] = '\0';
}

void apresentar_servidor_email(char email[], char servidor[])
{
    int i, j, k;
    for (i = 0; i < TF && email[i] != '@'; i++);
    i++;
    for (j = i, k = 0; j < TF && email[j] != '\0'; j++, k++)
    {
        servidor[k] = email[j];
    }
    servidor[k] = '\0';
}

int verificar_email_valido(char email[])
{
    int valido = 1;

    int i;

    for (i = 0; i < TF && email[i] != '@'; i++);


    if (i == TF || i == 0)
    {
        valido = 0;
    }
    else
    {
        i++;
        int k;
        for (k = i; k < TF && email[k] != '\0'; k++);

        if (k == i)
        {
            valido = 0;
        }
        else
        {

            for (i = 0; i < TF && email[i] != '\0'; i++)
            {
                if (email[i] == ' ')
                {
                    valido = 0;
                }
            }

            int ponto = 0;
            for (i = 0; i < TF && email[i] != '\0'; i++)
            {
                if (email[i] == '.')
                {
                    ponto++;
                }
            }

            if (ponto == 0)
            {
                valido = 0;
            }
        }
    }

    return valido;
}

void separar_email(char email[], char usuario[], char servidor[])
{
    apresentar_nome_usuario(email, usuario);
    apresentar_servidor_email(email, servidor);
}

int verificar_email_brasil(char servidor[])
{
    int brasil = 0;
    int k;
    for (k = 0; k < TF && servidor[k] != '\0'; k++);

    if (k >= 3 && servidor[k-3] == '.' && servidor[k-2] == 'b' && servidor[k-1] == 'r')
    {
        brasil = 1;
    }

    return brasil;
}
void main()
{
    setlocale (LC_ALL, "");
    char email[TF+1];
    char usuario[TF+1];
    char servidor[TF+1];
    int valido;
    int brasil;

    printf("Digite seu e-mail: ");
    scanf("%s", email);

    apresentar_nome_usuario(email, usuario);
    apresentar_servidor_email(email, servidor);
    valido = verificar_email_valido(email);
    separar_email(email, usuario, servidor);
    brasil = verificar_email_brasil(servidor);

    printf("\n");

    if (valido)
    {
        printf("O nome do usuário do e-mail é: %s\n", usuario);
        printf("O nome do servidor do e-mail é: %s\n", servidor);

        if (brasil)
        {
            printf("O e-mail é do Brasil.\n");
        }
        else
        {
            printf("O e-mail não é do Brasil.\n");
        }
    }
    else
    {
        printf("O e-mail digitado é inválido.\n");
    }

}
