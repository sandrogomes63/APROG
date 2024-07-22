#include <stdio.h>

int fatorial(int n)
{
    int f,i;
    f = 1;
    for (i=1; i<=n; i++)
    {
        f = f * i;
    }
    return f;
}

int main()
{
    int N,F;

    /// Ler numero N    printf("Int número inteiro positivo ? ");
    scanf("%d",&N);

    /// Calcular o fatorial de N    F=fatorial(N);

    /// Escrever resultado    printf("O fatorial de %d é %d.\n",N,F);
    getchar();
    return 0;
}


