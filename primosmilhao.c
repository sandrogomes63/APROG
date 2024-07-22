#include <stdio.h>

int contaDivisores(int n)
{
    int c,i;
    c=0;
    for(i=1;i<n;i++)
    {
        if (n % i == 0)
        {
            c++;
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
    for (n=1; n<=1000000; n++)
    {
        if (isPrime(n)==1)
        {
            printf ("%d\n",n);
        }
    }
    getchar();
    return 0;
}

