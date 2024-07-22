#include <stdio.h>

int main()
{
    int n;  // declarar var n do tipo inteiro
    printf("Introduza numero inteiro: ");
    scanf("%d",&n);     //  %d é o modificador para inteiro - Ler(n)
    if ( n % 2 == 0 )   //  n MOD 2 = 0
    {
        printf("Par\n");
    }
    else
    {
        printf("Impar\n");
    }
    getchar();
    return 0;
}