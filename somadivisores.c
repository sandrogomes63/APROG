#include <stdio.h>

int lerInteiroPositivo()
{
    int n;
    do scanf("%d",&n); while(n<=0);
    return n;
}
/// Função que devolva a quantidade de divisores de um número
int contaDivisores(int num)
{
    int c, i;
    c=0;
    for(i=1;i<=num;i++)    {        if (num%i==0)        {            c++;        }    }
    return c;
}/// Função que recebe um número e/// devolve 1 se for primo/// devolve 0 se for não primoint isPrimo(int n){    if (contaDivisores(n)==2)    {        return 1;    }    else    {        return 0;    }}/// Função que recebe um número e/// devolve 1 se for primo/// devolve 0 se for não primoint isPrimo2(int n){    return (contaDivisores(n)==2);}
int main()
{
    int n,s;
    printf("Introduza inteiro positivo : ");    n=lerInteiroPositivo();    s=contaDivisores(n);
    printf("A quantidade de divisores é : %d \n",s);    if (isPrimo(n)) printf("Primo\n");    else            printf("Não Primo\n");
    getchar();
    return 0;
}

