#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TF 50

void ler(char email[])
{
    printf("Digite seu e-mail: ");
    fgets(email, TF, stdin);
}

// Função para apresentar o nome de usuário do e-mail (antes do @)
void ApresentarUsuario(char email[]) // Não utilizei essa função ja que a função "SepararEmail" faz a mesma coisa"
{
    int i = 0;

    while (email[i] != '@')
    {
        printf("%c", email[i]);
        i++;
    }
}

// Função para apresentar o servidor do e-mail (depois do @)
void ApresentarServidor(char email[]) // Não utilizei essa função ja que a função "SepararEmail" faz a mesma coisa"
{
    int i = 0;

    while (email[i] != '@')
    {
        i++;
    }

    i++; // Pula o @

    while (email[i] != '\0')
    {
        printf("%c", email[i]);
        i++;
    }
}

// Função para validar o e-mail (deve ter @ e .)
int ValidarEmail(char email[])
{
    int i = 0, temArroba = 0, temPonto = 0;

    while (email[i] != '\0')
    {
        if (email[i] == '@')
        {
            temArroba = 1;
        }

        if (email[i] == '.')
        {
            temPonto = 1;
        }

        i++;
    }

    if (temArroba == 1 && temPonto == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// Função para separar o nome de usuário do servidor
void SepararEmail(char email[], char usuario[], char servidor[]) // Não entendi qual seria o uso dessa função ja que as 2 primeiras funções fazem a mesma coisa
{
    int i = 0, j = 0;

    while (email[i] != '@')
    {
        usuario[i] = email[i];
        i++;
    }

    usuario[i] = '\0'; // Adiciona o caractere nulo no final

    i++; // Pula o @



    while (email[i] != '\0')
    {
        servidor[j] = email[i];
        i++;
        j++;
    }

    servidor[j] = '\0'; // Adiciona o caractere nulo no final
}

// Função para verificar se o email é brasileiro (contém "br" no domínio)
int EmailBrasileiro(char email[])
{
    int i = 0, BR = 0;

    while (email[i] != '@')
    {
        i++;
    }

    i++; // Pula o @

    while (email[i] != '\0')
    {
        if (email[i] == 'b' && email[i + 1] == 'r')
        {
            BR = 1;
        }

        i++;
    }

    return BR;
}

void main()
{
    char email[TF], servidor[TF], usuario[TF];

    ler(email);

    if (ValidarEmail(email) == 1)
    {
        printf("\nE-mail valido!\n");

        SepararEmail(email, usuario, servidor);

        printf("\n\nUsuario: %s", usuario);
        printf("\nServidor: %s", servidor);

        if (EmailBrasileiro(email) == 1)
        {
            printf("\nE-mail brasileiro!");
        }
        else
        {
            printf("\nE-mail nao e brasileiro!");
        }
    }
    else
    {
        printf("\nE-mail invalido!");
    }

    return 0;
}
