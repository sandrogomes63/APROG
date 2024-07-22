/// Exemplo de implementação e utilização de
/// FUNÇÕES em C

/// Fatorial

#include <stdio.h>

/// Função que calcula e devolve o fatorial de um número

// notar as semelhançãs com a matemática :
// y = f(x)    // declaração ou cabeçalho da função f
               // x é a var independente ou de entrada da função f
               // y é a var dependente   ou de saída   da função f

// y = 3*x + 5 // implementação ou corpo  da função

int fatorial(int n)  // cabeçalho ou prototipo da função fatorial

//      int - tipo daquilo que a função devolve
//            neste caso um NÚMERO inteiro
//            SAÍDA ou OUTPUT da função fatorial
// fatorial - nome da função
//    int n - tipo daquilo que a função recebe
//            e nome que lhe dá (n)
//            ENTRADA ou INPUT da função fatorial
{
    int i,f;    f=1;    for(i=1;i<=n;i++) f=f*i;    return f;  // explicita o NÚMERO que a função devolve
               // SAÍDA ou OUTPUT da função fatorial}
// Esta função recebe um NÚMERO a que chama n
// Calcula (na var f) o fatorial de n e devolve esse NÚMERO


int main()
{
    int num;
    printf("Int inteiro positivo : ");
    scanf("%d",&num);

    printf("O fatorial de %d é : %d \n", num, fatorial(num));
    printf("              %d ! = %d \n", num, fatorial(num));

    getchar();
    return 0;
}






