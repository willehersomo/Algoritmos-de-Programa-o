#include <stdio.h>
#include <locale.h>

void main ()
{
float valorcombustivel, dinheiro, qntcombustivel;
setlocale (LC_ALL, "");
printf ("Quanto que voc� pretende gastar em combust�vel?\n", &dinheiro);
scanf ("%f", &dinheiro);
printf ("Qual o valor do litro do combust�vel no estabelecimento que voc� abastecer�?\n");
scanf ("%f", &valorcombustivel);
qntcombustivel= dinheiro/valorcombustivel;
printf ("Com esse valor, voc� abastecer� cerca de %.2f litro(s) do seu tanque\n", qntcombustivel);
}
