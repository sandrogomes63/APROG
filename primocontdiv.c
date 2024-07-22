#include<stdio.h>

int main()
{
    /// daqui para cima é o : INICIO

    int n,c,i;

    printf("Introduza número inteiro");
    scanf("%d",&n);

    c=0;
    for(i=1;i<=n;i++)
    {
        if (n%i==0)  // % é o MOD
        {
            c=c+1;   // ou c++;
        }
    }

    if (c==2)
    {
        printf("Primo");
    }
    else
    {
        printf("Não Primo");
    }


    /// daqui para baixo é o : FIM
    getchar();
    return 0;
}
