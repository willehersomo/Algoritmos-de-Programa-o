#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
float lab, av, exame;
setlocale(LC_ALL, "");
printf ("Insira a nota do laboratório: ");
scanf ("%f", &lab);
printf ("Insira a nota da avaliação: ");
scanf ("%f", &av);
printf ("Insira a nota do Exame final: ");
scanf ("%f", &exame);
float media= (lab*0.2)+(av*0.3)+(exame*0.5);
printf ("A média do aluno é de: %.2f\n", media);
if (media>=6){
printf ("O aluno está aprovado!");
}
else if (4< media&&media <6){
printf ("O aluno está em exame");
}
else if (media<4){
printf ("O aluno está reprovado!");
}
}
