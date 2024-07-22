#include<stdio.h>

int main()
{
    /// daqui para cima é o : INICIO

    int n, a, s;

    do
    {
        printf("Introduza inteiro não negativo ");
        scanf("%d",&n);
    }while(n<0);

    s = 0;
    while(n>0)
    {
        a = n % 10;
        n = n / 10;
        s = s + a;   // equivalente a s += a;
    }

    printf("A soma dos dígitos é : %d",s);

    /// daqui para baixo é o : FIM
    getchar();
    return 0;
}
