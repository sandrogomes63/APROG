
#include <stdio.h>#include <locale.h>  // para funcionarem os acentos

/// Função que lê e valida um inteiro positivo
int lerInteiroPositivo()
{
    int n;
    do scanf("%d",&n); while(n<=0);
    return n;
}

/// Função que devolve a soma dos algarismos de um número
int somaAlgarismos(int num)
{
    int s,a;
    s=0;
    do
    {                   // % é o MOD ou RESTO da divisão
        a   = num % 10; // algarismo das unidades
        num = num / 10; // restante número
        s   = s + a;
    }while(num>0);
    return s;
}

int main()
{    setlocale(LC_ALL,"portuguese"); // para funcionarem os acentos
    int n,s;
    printf("Introduza inteiro positivo");    n=lerInteiroPositivo();    s=somaAlgarismos(n);
    printf("A soma dos algarismos é : %d \n",s);
    getchar();
    return 0;
}

