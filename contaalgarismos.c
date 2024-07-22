#include<stdio.h>

/// Func return positive N
int lerInteiroPositivo(){
    int n;
    do scanf("%d",&n); while(n<=0);
    return n;
}

int contaAlgarismos(int n){
    int a,c;
    c=0;
    while(n>0){
        a=n%10; // desnecessário
        n=n/10;
        c=c+1;
    }
    return c;
}

int main(){
    int N,Q;

    /// Read number
    printf("Int número inteiro positivo ? "); N=lerInteiroPositivo();
    /// Calcule N
    Q=contaAlgarismos(N);

    /// Result
    printf("O número %d tem %d algarismos.\n",N,Q);

    getchar();
    return 0;
}
