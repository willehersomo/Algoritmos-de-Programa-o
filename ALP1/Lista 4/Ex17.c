#include <stdio.h>
#include <locale.h>

void main (){
setlocale (LC_ALL, "");
float celular, granatual=0, granarestante=0, granaganha=0;
int trampo=0, horas=0;
char ativ;

printf ("Insira o valor do celular: ");
scanf ("%f", &celular);
printf ("Insira a grana atual de Maria: ");
scanf ("%f", &granatual);
if (granatual>=celular)
{
    printf ("Parab�ns!, nem precisa trampar!");
}
while (granatual<celular)
{
    printf ("\nSem grana para o celular!, v� trampar, escolha uma: \n");
    printf ("\nJ-Ajude seu Tio Jo�o!!!\n");
    printf ("\nC-Ajude a Dona Cleusa!!!\n");
    printf ("\nB-Ajude a Bia da Quitanda!!!\n");
    printf ("\nM-Ajude a sua m�e!!!\n");
    printf ("\nEscolha J, C, B ou M (mai�suculo)\n");
    scanf (" %c", &ativ);

    switch (ativ)
    {
    case 'J' || 'j':
        granatual+=50.0;
        granaganha+=50.0;
        trampo++;
        horas+=5;
        printf ("\nVoc� ajudou seu Tio Jo�o, voc� tem agora: R$%.2f\n", granatual);
        break;
    case 'C' || 'c':
        granatual+=120;
        granaganha+=120;
        trampo++;
        horas+=14;
        printf ("\nVoc� ajudou a Dona Cleusa, voc� tem agora: R$%.2f\n", granatual);
        break;
    case 'B'||'b':
        granatual+=60;
        granaganha+=60;
        trampo++;
        horas+=4;
        printf ("\nVoc� ajudou a Bia da Quitanda, voc� tem agora: R$%.2f\n", granatual);
        break;
    case 'M'||'m':
        granatual+=50;
        granaganha+=50;
        trampo++;
        horas+=3;
         printf ("\nVoc� ajudou a sua m�e, voc� tem agora: R$%.2f\n", granatual);
        break;
    default:
        printf ("\nOp��o inv�lida!!!\n");
        break;
    }
}

float desconto= celular*0.05;
float celularfinal=celular-desconto;
granarestante=granatual-celularfinal;

printf ("\nParb�ns! Agora voc� pode comprar seu celular!!!\n");
printf ("\nMaria realizou o total de %d tarefa(s)\n", trampo);
printf ("\nMaria investiu o total %d hora(s)\n", horas);
printf ("\nMaria ganhou cerca de R$%.2f realizando todo o trabalho\n", granaganha);
printf("\nNo final, apenas lhe restou R$%.2f\n com a compra do celular", granarestante);
}

//Este codigo foi elaborado por Breno Wille Bezerra Correia, da turma de BCC, primeiro termo, no dia 19/06 �s 22:22

