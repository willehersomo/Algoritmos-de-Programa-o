#include <stdio.h>
#include <locale.h>
void main()
{
    float largura, comprimento, area, valor;
    setlocale (LC_ALL, "");
    printf("Qual a largura do seu terreno?\n");
    scanf("%f", &largura);
    printf("Qual o comprimento do seu terreno?\n");
    scanf ("%f", &comprimento);
    area=largura*comprimento;
    valor= area*250;
    printf ("Seu terreno tem %2.f M²\n", area );
    printf ("e possui o preço de R$ %2.f\n", valor );
}
