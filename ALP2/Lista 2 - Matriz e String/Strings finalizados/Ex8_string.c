#include <stdio.h>
#include <string.h>

#define TF 201

void preencher_nome(char nome[]) {
    scanf(" %200[^\n]", nome);
}

void preencher_sobrenome(char sobrenome[]) {
    scanf(" %200[^\n]", sobrenome);
}

void preencher_titulo(char titulo[]) {
    scanf(" %200[^\n]", titulo);
}

void preencher_editora(char editora[]) {
    scanf(" %200[^\n]", editora);
}

void preencher_cidade(char cidade[]) {
    scanf(" %200[^\n]", cidade);
}

void preencher_ano(char ano[]) {
    scanf(" %200[^\n]", ano);
}

void trabalhar_com_nome(char nome[]) {
    if (nome[0] >= 'a' && nome[0] <= 'z') {
        nome[0] = nome[0] - 32;
    }
    for (int i = 1; i < strlen(nome); i++) {
        if (nome[i] >= 'A' && nome[i] <= 'Z') {
            nome[i] = nome[i] + 32;
        }
    }
}

void trabalhar_com_sobrenome(char sobrenome[]) {
    for (int i = 0; i < strlen(sobrenome); i++) {
        if (sobrenome[i] >= 'a' && sobrenome[i] <= 'z') {
            sobrenome[i] = sobrenome[i] - 32;
        }
    }
}

void trabalhar_com_titulo(char titulo[]) {
    if (titulo[0] >= 'a' && titulo[0] <= 'z') {
        titulo[0] = titulo[0] - 32;
    }
    for (int i = 1; i < strlen(titulo); i++) {
        if (titulo[i] == ' ') {
            if (titulo[i + 1] >= 'a' && titulo[i + 1] <= 'z') {
                titulo[i + 1] = titulo[i + 1] - 32;
            }
        }
    }
}

void trabalhar_com_editora(char editora[]) {
    if (editora[0] >= 'a' && editora[0] <= 'z') {
        editora[0] = editora[0] - 32;
    }
    for (int i = 1; i < strlen(editora); i++) {
        if (editora[i] == ' ') {
            if (editora[i + 1] >= 'a' && editora[i + 1] <= 'z') {
                editora[i + 1] = editora[i + 1] - 32;
            }
        }
    }
}

void trabalhar_com_cidade(char cidade[]) {
    if (cidade[0] >= 'a' && cidade[0] <= 'z') {
        cidade[0] = cidade[0] - 32;
    }
    for (int i = 1; i < strlen(cidade); i++) {
        if (cidade[i] == ' ') {
            if (cidade[i + 1] >= 'a' && cidade[i + 1] <= 'z') {
                cidade[i + 1] = cidade[i + 1] - 32;
            }
        }
    }
}


void trabalhar_com_ABNT(char ABNT[], char nome[], char sobrenome[], char titulo[], char editora[], char cidade[], char ano[]) {
    int tl = 0;
    for (int i = 0; i < strlen(sobrenome); i++, tl++) {
        ABNT[tl] = sobrenome[i];
    }
    ABNT[tl++] = ',';
    ABNT[tl++] = ' ';
    for (int i = 0; i < strlen(nome); i++, tl++) {
        ABNT[tl] = nome[i];
    }
    ABNT[tl++] = '.';
    ABNT[tl++] = ' ';
    for (int i = 0; i < strlen(titulo); i++, tl++) {
        ABNT[tl] = titulo[i];
    }
    ABNT[tl++] = ':';
    ABNT[tl++] = ' ';
    for (int i = 0; i < strlen(editora); i++, tl++) {
        ABNT[tl] = editora[i];
    }
    ABNT[tl++] = ',';
    ABNT[tl++] = ' ';
    for (int i = 0; i < strlen(cidade); i++, tl++) {
        ABNT[tl] = cidade[i];
    }
    ABNT[tl++] = ',';
    ABNT[tl++] = ' ';
    for (int i = 0; i < strlen(ano); i++, tl++) {
        ABNT[tl] = ano[i];
    }
    ABNT[tl++] = '.';

    ABNT[tl] = '\0';
}

void apresentar_ABNT(char ABNT[]) {
    printf("%s", ABNT);
}

int main() {
    char nome[TF];
    char sobrenome[TF];
    char titulo[TF];
    char editora[TF];
    char cidade[TF];
    char ano[TF];
    char ABNT[TF];

    printf("Digite o nome do autor: \n");
    preencher_nome(nome);
    printf("Digite o sobrenome do autor: \n");
    preencher_sobrenome(sobrenome);
    printf("Digite o titulo da publicação: \n");
    preencher_titulo(titulo);
    printf("Digite o nome da Editora: \n");
    preencher_editora(editora);
    printf("Digite a cidade de publicação: \n");
    preencher_cidade(cidade);
    printf("Digite o ano de publicação: \n");
    preencher_ano(ano);

    trabalhar_com_nome(nome);
    trabalhar_com_sobrenome(sobrenome);
    trabalhar_com_titulo(titulo);
    trabalhar_com_editora(editora);
    trabalhar_com_cidade(cidade);
    trabalhar_com_ABNT(ABNT, nome, sobrenome, titulo, editora, cidade, ano);
    apresentar_ABNT(ABNT);

    return 0;
}
