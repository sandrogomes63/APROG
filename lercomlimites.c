
#include <stdio.h>

int lerInteiro(int li, int ls)
{
    int n;    do
    {
        printf("Int inteiro entre %d e %d : ",li,ls);
        scanf("%d",&n);
    }while(n<li || n>ls);    return n;}

int main()
{
    int num;
    num = lerInteiro(1,100);
    printf("O número lido foi : %d \n", num);

    getchar();
    return 0;
}






