#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
setlocale (LC_ALL, "");
int senha;
printf ("Insira a senha: ");
scanf ("%i", &senha);
if (senha==2023)
{
printf ("Acesso concedido!\n");
}
else
{
printf ("Acesso negado!\nMotivo: senha incorreta.\n");
}
}
