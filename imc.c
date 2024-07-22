#include <stdio.h>

int main()
{
    float p,a,imc;

    printf("Introduza peso em kg: ");
    scanf("%f",&p);
    printf("Introduza altura em m: ");
    scanf("%f",&a);

    imc = p/(a*a);  // em C não existe o ^
    printf("O IMC é : %f \n",imc);

    if (imc<19)
    {
        printf("Magro\n");
    }
    else
    {
        if (imc<25)
        {
            printf("Normal\n");
        }
        else
        {
            if (imc<30)
            {
                printf("Excesso\n");
            }
            else
            {
                printf("Gordo\n");
            }
        }
    }
    getchar();
    return 0;
}