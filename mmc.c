
#include <stdio.h>

int lerInteiroPositivo()
{
    int n;
    do scanf("%d",&n); while(n<=0);
    return n;
}

/// Função que devolve o mínimo múltiplo comum entre 2 números
int mmc(int a, int b)
{
    int m;
    m=a;
    while (m%b!=0) m=m+a;
    return m;
}/// Função que devolve o máximo divisor comum entre 2 números
int mdc(int a, int b)
{
    int m;
    m=a;    while(a%m!=0 || b%m!=0) m--;
    return m;
}

int main()
{
    int a1,b1;
    printf("Int nº positivo : "); a1=lerInteiroPositivo();
    printf("Int nº positivo : "); b1=lerInteiroPositivo();
    printf("O mínimo múltiplo comum é : %d \n",mmc(a1,b1));
    printf("O máximo divisor  comum é : %d \n",mdc(a1,b1));
    getchar();
    return 0;
}

