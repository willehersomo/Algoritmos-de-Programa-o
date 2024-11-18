#include <stdio.h>
#include <locale.h>
#include <math.h>

void main()
{
float conta, carlos, andre, felipe, totalcarlosandre;
setlocale ("LC_ALL", "");
printf("Digite o valor da conta: ");
scanf("%f", &conta);
totalcarlosandre = floor(conta / 3.0) * 2.0;
felipe = conta - totalcarlosandre;
if (fmod(totalcarlosandre, 1.0) != 0.0)
    {
        felipe += fmod(totalcarlosandre, 1.0) * 3.0;
        totalcarlosandre = floor(totalcarlosandre);
    }

carlos = andre = totalcarlosandre / 2.0;
printf("Carlos pagará: R$%.2f\n", carlos);
printf("André pagará: R$%.2f\n", andre);
printf("Felipe pagará: R$%.2f\n", felipe);
}

//eu fiquei cerca de 1 hora só pesquisando formas para resolver esse exercicio em específico, aaaaaaaaa, mas enfim deu certo, mereço um pontinho a mais :)
