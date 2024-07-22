#include <stdio.h>

int funcao(int a, int b)
{
    int r;
    r = a + b;
    return r;
}

int main()
{
    int x,y,z;

    x=3; y=4;

    z=funcao(x,y);

    printf("x = %d \n",x);
    printf("y = %d \n",y);
    printf("z = %d \n",z);

    getchar();
    return 0;
}
