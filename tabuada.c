#include<stdio.h>

int main()
{
    // daqui para cima é o : INICIO

    int i,j;

    printf("Que tabuada quer ? ");
    scanf("%d",&j);

    printf("\nTabuada dos %d\n\n",j);
    // RepetirPara i=1 até 10 passo 1
    for(i=1; i<=10; i=i+1) // for(i=1; i<=10; i++)
    {
        printf("%d * %d = %d\n",j,i,j*i);
    }

    // daqui para baixo é o : FIM
    getchar();
    return 0;
}
