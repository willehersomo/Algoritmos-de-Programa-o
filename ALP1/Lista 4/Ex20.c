#include <stdio.h>
#include <locale.h>

void main ()
{
    setlocale (LC_ALL,"");
    int fichascheap=0;
    int fichasexpansive=0;
    int pessoas=0;
    float lucro=0;
    char escolha;
    printf ("Caos e tragédia, aproveite a festa :OO\n");

    while (escolha!='C')
    {
        printf ("\nSelecione:\n");
        printf ("\nA. Comprar fichas baratinhas, só 2 reaiszinhos\n");
        printf ("\nB. Comprar fichas caras, é 5 conto!!!\n");
        printf ("\nC. Sair\n");
        printf ("\nDigite sua escolha: \n");
        scanf (" %c", &escolha);

        if (escolha=='A')
        {
            int quant;
            printf ("\nQuantas fichas baratinhas você quer?\n");
            scanf ("%d", &quant);
            fichascheap+=quant;
            lucro+=2.00*quant;
            pessoas++;
        }
        if (escolha=='B')
        {
            int quant;
            printf ("\nQuantas fichas caríssimas você quer?\n");
            scanf ("%d", &quant);
            fichasexpansive+=quant;
            lucro+=5.00*quant;
            pessoas++;
        }
        if (escolha=='C')
        {
            printf ("Certo, nunca mais volte!\n");
        }
        if(escolha!='C' && escolha!='B' && escolha!='A') {

            printf ("\nOpção inválida\n");
        }
    }

    printf ("\nOlhe só: %d pessoa(s)!\n", pessoas);
    printf ("\nTolas, foi gasto 2 reais para cada uma das %d ficha(s) barata!\n", fichascheap);
    printf ("\nPior ainda! foi gasto 5 reais para cada uma das %d ficha(s) caras, hahahahahah!\n", fichasexpansive);
    printf ("\nConseguimos %.2f reaiszinhos com esses burrinhos:p\n", lucro);



}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 20/06 às 21:26
