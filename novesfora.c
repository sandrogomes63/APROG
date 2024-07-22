#include <stdio.h>

int lerPositivo()
{
    int n;
    do scanf("%d",&n); while(n<=0);
    return n;
}

int somaAlgarismos(int n)
{
    int a,s=0;
    while(n>0)
    {
        a = n % 10;
        n = n / 10;   // n /= 10;
        s = s + a;    // s += a;
    }
    return s;
}


int main()
{
    int num;
    printf("Int número inteiro positivo: ");
    num=lerPositivo();

    printf("%d",num);
    while(num>9)
    {
        num=somaAlgarismos(num);
        printf(" -> %d",num);
    }
    if (num==9) printf(" -> 0");
    getchar();
    return 0;
}


