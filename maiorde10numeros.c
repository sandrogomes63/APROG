#include<stdio.h>

int main()
{
    /// daqui para cima é o : INICIO

    int n,m,i;

    printf("Introduza o 1º inteiro");
    scanf("%d",&n);
    m = n;
    // RepetirPara i=2 até 10 passo 1
    for(i=2;i<=10;i++) // for(i=2;i<=10;i=i+1)
    {
        printf("Introduza o %dº inteiro",i);
        scanf("%d",&n);
        if ( n > m )
        {
            m = n;
        }
    }
    printf("O maior número foi %d",m);

    /// daqui para baixo é o : FIM
    getchar();
    return 0;
}
