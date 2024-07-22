#include<stdio.h>

/// Um vetor é representado internamente como um endereço:
/// o endereço da posição 0 do vetor.
/// Donde, um vetor e um endereço são, internamente, a mesma coisa.
/// Daí que v[] é equivalente a *v///         v   é equivalente a &v[0]
/// Assim os vetores são sempre passados às funções por endereço ou referência
/// sem que o programador se tenha que preocupar com & e * .
/// Assim, as funções podem alterar os vetores da main que recebem.


/// função para ler um vetor de n elementos inteiros do teclado
void lerVetor(int v[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Introduza o %dº elemento ", i+1);
        scanf("%d",&v[i]);
    }
}

/// função para escrever um vetor no ecran
void escreverVetor(int v[], int n)
//void escreverVetor(int *v, int n)
{
    printf("[ ");
    for(int i=0;i<n;i++) printf("%d ",v[i]);
    printf("]\n");
}

int somarElementosDoVetor(int v[], int n)
{
    int s=0;
    for(int i=0;i<n;i++) s+=v[i];
    return s;
}

int maiorElementoDoVetor(int v[], int n)
{
    int m=v[0];
    for(int i=1;i<n;i++)
        if(v[i]>m) m=v[i];
    return m;
}

int posMaiorElemento(int v[], int n)
{
    int p=0;
    for(int i=1;i<n;i++)
        if(v[i]>v[p]) p=i;
    return p;
}

/// função para somas dois vetores u e v e colocar o resultado
/// no vetor w, todos de n elementos
void somarVetores(int u[],int v[], int w[], int n)
{
    for(int i=0;i<n;i++) w[i]=u[i]+v[i];
}

int main()
{
    int v[10]; //    reservo 10 casas, da nº 0 à nº 9
    int n=8;   // só vou usar 8 casas, da nº 0 à nº 7

    lerVetor(v,n);

    printf("Vetor lido v : \n");
    escreverVetor(v,n);

    printf("A soma dos elementos de v é : %d\n",somarElementosDoVetor(v,n));
    printf("O maior dos elementos de v é : %d\n",maiorElementoDoVetor(v,n));
    printf("A pos do maior elemento de v é : %d\n",posMaiorElemento(v,n));
    printf("O maior dos elementos de v é : %d\n",v[posMaiorElemento(v,n)]);

    int u[10]={9,8,7,6,5,4,3,2};
    int w[10];

    printf("Vetor u : \n");
    escreverVetor(u,n);
    printf("Vetor v : \n");
    escreverVetor(v,n);
    somarVetores(u,v,w,n);
    printf("Vetor soma w : \n");
    escreverVetor(w,n);



    getchar();
    return 0;
}
