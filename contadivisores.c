#include <stdio.h>

int lerInteiroPositivo(){
    int n;
    do scanf("%d",&n); while(n<=0);
    return n;
}

/// Função que devolva a quantidade de divisores de um número
/// recebe um número num do tipo int (inteiro)
/// e devolve um int
int contarDivisores(int num){
    int c, i;
    c=0;
    for(i=1;i<=num;i++) 
        if (num % i == 0) c++;
            // % é o MOD (resto da divisão)
            //       RESTO
            // c++ é equivalente a c=c+1
    return c;
}



int main(){
    int n,s;

    printf("Introduza inteiro positivo : ");
    n=lerInteiroPositivo();

    printf("A quantidade de divisores é : %d \n",contarDivisores(n));

    if (contarDivisores(n)==2) printf("Primo\n");
    else                      printf("Não Primo\n");

    getchar();
    return 0;
}


