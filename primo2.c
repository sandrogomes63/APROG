#include <stdio.h>

int contaDivisores(int n)
{
    int c=0,i;
    for(i=1;i<=n;i++) if (n % i == 0) c++;
    return c;
}

int isPrime(int n)
{
    return (contaDivisores(n)==2);
}

int main()
{
    int n;
    printf("Int nº positivo maior ou igual a 2 : ");
    scanf("%d",&n);

    if (isPrime(n)) printf ("Primo\n");
    else            printf ("Não Primo\n");

    getchar();
    return 0;
}

