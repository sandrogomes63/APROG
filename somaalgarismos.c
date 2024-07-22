#include<stdio.h>

/// Função que soma os algarismos de um número
int somaalgarismos(int n)
{
    int s,a;
    s = 0;
    while (n>0)
    {
        a = n % 10;
        n = n / 10;
        s = s + a;
    }
    return s;
}

int main()
{
    int N,S;
    /// Ler numero N    printf("Int número inteiro positivo ? ");
    scanf("%d",&N);
    /// Calcular soma dos algarismos de N    S=somaalgarismos(N);
    /// Escrever resultado    printf("A soma dos algarismos de %d é %d.\n",N,S);
    getchar();
    return 0;
}
