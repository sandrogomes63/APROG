#include <stdio.h>

int contaDivisores(int n)
{
    int c,i;
    c=0;
    for(i=1;i<=n;i++)
    {
        if (n % i == 0)
        {
            c++; // equivalente a c=c+1;
        }
    }
    return c;
}

int isPrime(int n)
{
    if(contaDivisores(n)==2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    printf("Int nº positivo maior ou igual a 2 : ");
    scanf("%d",&n);

    if (isPrime(n)==1)
    {
        printf ("Primo\n");
    }
    else
    {
        printf ("Não Primo\n");
    }

    getchar();
    return 0;
}

