#include<stdio.h>

int main()
{
    /// daqui para cima é o : INICIO

    int x,a,b,c,t;

    x = rand() % 100 + 1;
    a = 1;
    b = 100;
    c = 0;
    do
    {
        printf("Introduza número entre %d e %d : ",a,b);
        scanf("%d",&t);
        c = c + 1;
        if (t>x)
        {
            b = t - 1;
        }
        if (t<x)
        {
            a = t + 1;
        }
    }while(t!=x);

    printf("Parabéns! Acertou em %d tentativas!",c);

    /// daqui para baixo é o : FIM
    getchar();
    return 0;
}
