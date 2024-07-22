#include <stdio.h>

int inverteNumero(int n){
    int ni,a;
    ni=0;
    while (n>0){
        a = n % 10;
        n = n / 10;
        ni = 10*ni + a;
    }
return ni;
}

int isCapicua(int n){
    if(n==inverteNumero(n)){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n;
    printf("Int nº positivo : ");
    scanf("%d",&n);

    if (isCapicua(n)==1){
        printf ("Capicua\n");
    }
    else{
        printf ("Não Capicua\n");
    }

getchar();
return 0;
}

