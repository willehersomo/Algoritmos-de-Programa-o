#include <stdio.h>
#include <locale.h>

void main ()
{
float valorcombustivel, dinheiro, qntcombustivel;
setlocale (LC_ALL, "");
printf ("Quanto que você pretende gastar em combustível?\n", &dinheiro);
scanf ("%f", &dinheiro);
printf ("Qual o valor do litro do combustível no estabelecimento que você abastecerá?\n");
scanf ("%f", &valorcombustivel);
qntcombustivel= dinheiro/valorcombustivel;
printf ("Com esse valor, você abastecerá cerca de %.2f litro(s) do seu tanque\n", qntcombustivel);
}
