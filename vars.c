#include <stdio.h>

int main()
{

    int idade;    // declaração de um inteiro
    char sexo;    // declaração de um carater
    float altura; // declaração de um float

    idade=23;
    sexo='F';
    altura=1.6;

    printf("A Sara tem %d anos.\n",idade);
    printf("A Sara mede %f metros.\n",altura);
    printf("A Sara é do sexo %c.\n",sexo);

    getchar();
    return 0;
}