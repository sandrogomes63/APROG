#include <stdio.h>

int collatz(int n){
    if(n%2==0){
        return n/2;
    }
    else{
        return 3*n+1;
    }
}

int main(){
    int n;
   
    printf("Introduza n : ");
    scanf("%d",&n);
    
    printf("\n%d ",n);
    while(n != 1){
        n = collatz(n);
        printf("--> %d ",n);
    }

    getchar();
    return 0;
}






