#include<stdio.h>

int main()
{

    int n, d;

    do
    {
        printf("Introduza inteiro maior ou igual a 2 ");
        scanf("%d",&n);
    }while(n<2);

    d = 2;

    while( n > 1 )
    {
        if (n % d == 0)
        {
            printf("%d ",d);
            n = n / d;
        }
        else
        {
            d = d + 1; // equivalente a d++;
        }
    }

    getchar();
    return 0;
}
