#include <stdio.h>

int lerPositivo()
{
    int n;
    do
    {
        scanf("%d",&n);
    }while(n<=0);
    return n;
}

int mdc(int a, int b)
{
    int m;
    m = a;
 // while(!(a % m == 0 && b % m == 0))
    while(a % m != 0 || b % m != 0)  //  || é OU
    {                                //  && é E
        m--;
    }
    return m;
}

int main()
{
    int a,b,m;
    printf("Introduza a : ");
    a=lerPositivo();
    printf("Introduza b : ");
    b=lerPositivo();

    /// Calcular mdc(a,b)    m=mdc(a,b);

    /// Escrever resultado    printf("mdc(%d,%d)=%d\n",a,b,m);
    getchar();
    return 0;
}


