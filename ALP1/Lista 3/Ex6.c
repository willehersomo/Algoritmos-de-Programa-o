#include <stdio.h>
#include <locale.h>
#include <math.h>

void main ()
{
float lab, av, exame;
setlocale(LC_ALL, "");
printf ("Insira a nota do laborat�rio: ");
scanf ("%f", &lab);
printf ("Insira a nota da avalia��o: ");
scanf ("%f", &av);
printf ("Insira a nota do Exame final: ");
scanf ("%f", &exame);
float media= (lab*0.2)+(av*0.3)+(exame*0.5);
printf ("A m�dia do aluno � de: %.2f\n", media);
if (media>=6){
printf ("O aluno est� aprovado!");
}
else if (4< media&&media <6){
printf ("O aluno est� em exame");
}
else if (media<4){
printf ("O aluno est� reprovado!");
}
}
