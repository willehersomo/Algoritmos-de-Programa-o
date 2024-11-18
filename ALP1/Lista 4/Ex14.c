#include <stdio.h>
#include <locale.h>

void main()
{
    setlocale (LC_ALL,"");
    float saldo = 0.0, valor;
    int acao;

    do
    {
        printf("Tecle:\n");
        printf("1. Para consultar saldo\n");
        printf("2. Para sacar determinado valor\n");
        printf("3. Para fazer dep�sito\n");
        printf("4. Para sair\n");
        scanf("%d", &acao);

        if (acao == 1)
        {
            printf("Seu saldo � de: R$%.2f\n", saldo);
        }
        else if (acao == 2)
        {
            printf("Digite valor a ser retirado: ");
            scanf("%f", &valor);

            if (valor <= saldo)
            {
                saldo -= valor;
                printf("Saque efetuado\n");
            }
            else
            {
                printf("Saldo insuficiente\n");
            }
        }
        else if (acao == 3)
        {
            printf("Digite valor a ser depositado: ");
            scanf("%f", &valor);
            saldo += valor;
            printf("Deposito efetuado\n");
        }
        else if (acao == 4)
        {
            printf("Agradecemos a prefer�ncia!\n");
        }
        else
        {
            printf("A��o inv�lida\n");
        }

    } while (acao != 4);
}
