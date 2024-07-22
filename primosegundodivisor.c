#include<stdio.h>

int main()
{
    int n,d;

    do
    {
        printf("Introduza inteiro maior ou igual a 2 : ");
        scanf("%d",&n);
    }while(n<2);

    d = 2;
    while(n % d != 0)
    {
        d = d + 1; // ou d++;
    }

    if (d==n)
    {
        printf("Primo !\n");
    }
    else
    {
        printf("Não Primo !\n");
    }

    getchar();
    return 0;
}
