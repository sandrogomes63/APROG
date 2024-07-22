#include<stdio.h>

int main()
{                /// vetor para guardar números inteiros
    int v[10];   ///    reservo 10 casas, da nº 0 à nº 9
                 /// no lugar do 10 NÃO SE PODE pôr uma variável
    int n=8;     /// só vou usar 8 casas, da nº 0 à nº 7

    /// Ler o vetor v
    for(int i=0;i<n;i++)
    {
        printf("Introduza o %dº elemento ", i+1);
        scanf("%d",&v[i]);   // O & é do scanf...
    }
    // scanf("%d",&v); está completamante MAL !

    /// Escrever o vetor v
    printf("[ ");
    for(int i=0;i<n;i++) printf("%d ",v[i]);
    printf("]\n");    // printf("%d",v); está completamante MAL !

    getchar();
    return 0;
}
