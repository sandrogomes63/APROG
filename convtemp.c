#include <stdio.h>

float cel2far(float TC){
    float TF;
    TF = 9.0/5*TC+32;
    return TF;
}

int main(){

    float TC,TF; // Declaração de variáveis do tipo float

    printf("Introduza temperatura em º C : ");   // Escrever("...")
    scanf("%f",&TC);                             // Ler(TC)
    TF = cel2far(TC);                            // TF <- 9.0/5*TC+32
    printf("A temperatura em º F é : %f \n",TF); // Escrever("...")

    printf("57ºC é : %f \n",cel2far(57));
    printf("27ºC é : %f \n",cel2far(27));
    getchar();
    return 0;
}
