#include <locale.h>
#include <math.h>
#include <stdio.h>

void main ()
{
    setlocale(LC_ALL, "");
    float peso;
    int idade;
    printf ("Insira a idade do paciente: ");
    scanf ("%d", &idade);
    printf ("Insira o peso do paciente: ");
    scanf ("%f", &peso);
    if (idade>=12)

    {
        switch ((int) peso)
        {
        case 0 ... 59:
            printf ("O paciente deve tomar 875MG, sendo 35 gotas");

            break;
        default:
            printf ("O paciente deve tomar 1000 MG, sendo 40 gotas");
            break;
        }
    }
    else if (idade<12)
    {
        switch ((int)peso)
    {
    case 0 ... 4:
        printf ("INVÁLIDO");
            break;
        case 5 ... 9:
            printf ("O paciente deve tomar 125 mg, sendo 5 gotas");
            break;
        case 10 ... 16:
            printf ("O paciente deve tomar 250 mg, sendo 10 gotas");
            break;
        case 17 ... 24:
            printf ("O paciente deve tomar 375 mg, sendo 15 gotas");
            break;
        case 25 ... 30:
            printf ("O paciente deve tomar 500 mg, sendo 20 gotas");
            break;
        default:
            printf ("O paciente deve tomar 750 mg, sendo 25 gotas");
        }
    }
}
