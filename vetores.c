#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

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
{
    printf("[ ");
    for(int i=0;i<n;i++) printf("%d ",v[i]);
    printf("]\n");
}


/// função para somar os elementos de um vetor
int somarVetor(int v[], int n)
{
    int s=0;
    for(int i=0;i<n;i++) s=s+v[i];  // ou s+=v[i];
    return s;
}

/// função para copiar um vetor v para um vetor u
void copiarVetor(int v[],int u[],int n)
{
    for(int i=0;i<n;i++) u[i]=v[i];
}

/// função para virar um vetor (inverter a ordem dos elementos)
void virarVetor(int v[],int n)
{
    int a;
    for(int i=0;i<n/2;i++)
    {
        a=v[n-1-i]; v[n-1-i]=v[i]; v[i]=a;
    }
}

/// função para rodar um vetor 1 casa para a direita
void rodarVetorDireita(int v[],int n)
{
    int a = v[n-1];
    for(int i=n-1;i>0;i--) v[i]=v[i-1];
    v[0]=a;
}

/// função para determinar o maior elemento de um vetor
int maiorElementoDoVetor(int v[],int n)
{
    int m = v[0];
    for(int i=1;i<n;i++) if (v[i]>m) m=v[i];
    return m;
}

/// função para determinar a posição do maior elemento de um vetor
int posicaoDoMaior(int v[],int n)
{
    int p=1;
    for(int i=1;i<n;i++) if (v[i]>v[p]) p=i;
    return p;
}

/// função para somar 2 vetores u e v colocando o resultado em w
void somar2vetores(int v[],int u[],int w[],int n)
{
    for(int i=0;i<n;i++) w[i]=u[i]+v[i];
}

/// função para somar k a um vetor
void somarKaUmVetor(int v[],int k,int n)
{
    for(int i=0;i<n;i++) v[i]=v[i]+k;
}

/// função para multiplicar um vetor por k
void multiplicarKporUmVetor(int v[],int k,int n)
{
    for(int i=0;i<n;i++) v[i]=k*v[i];
}

/// função para calcular o produto interno entre 2 vetores
int produtoInterno(int v[],int u[],int n)
{
    int s=0;
    for(int i=0;i<n;i++) s=s+v[i]*u[i];
    return s;
}

/// função para calcular a média dos n elementos do vetor v
float mediaDeUmVetor(int v[],int n)
{
    int s=0;
    for(int i=0;i<n;i++) s=s+v[i];  //  s+=v[i];
    return (float) s/n;             //  1.0*s/n;
    // (float) faz o cast da var s para um float
}

/// função para criar um vetor de n elementos com números à sorte entre 1 e k
void vetorASorte(int v[], int n, int k)
{
    for(int i=0;i<n;i++) v[i]=rand()%k+1;
    // rand() tira um número à sorte entre 0 e o máximo
    //                inteiro capaz de ser representado
    // rand()%k   resulta num numero à sorte entre 0 e k-1
    // rand()%k+1 resulta num numero à sorte entre 1 e k
}

/// função que devolve a soma dos n elementos de um vetor
int somarElementosDoVetor(int v[], int n)
{
    int s=0;
    for(int i=0;i<n;i++) s=s+v[i]; // s+=v[i];
    return s;
}

/// função que devolve a quantidade de elementos pares dos n elementos de um vetor
int quantElementosPares(int v[], int n)
{
    int c=0;
    for(int i=0;i<n;i++) if(v[i]%2==0) c++; // c=c+1;
 // for(int i=0;i<n;i++) c += !(v[i]%2);
    return c;
}

/// função que devolve a posição do elemento mais próximo
/// de 0 dos n elementos de um vetor
int posMinAbsVetor(int v[], int n)
{
    int p=1;  // A pos do maior elemento é 1
    for(int i=1;i<n;i++) if(abs(v[i])<abs(v[p])) p=i;
    // comparo com os elementos das restantes posições
    //  abs(n) é o módulo de n se n é um int   (da biblioteca math.h)
    // fabs(x) é o módulo de x se x é um float (da biblioteca math.h)
    return p;
}

/// função que "devolve" o maior e o menor elementos de um vetor
/// como "devolve" 2 números tem que se usar a passagem por endereço
void maiorEMenorElemento(int v[], int n, int * maior, int * menor)
{
    *maior=v[0]; *menor=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]>*maior) *maior=v[i];
        if(v[i]<*menor) *menor=v[i];
    }
}

int temRepetidos(int v[], int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(v[i]==v[j]) return 1;
    return 0; // Se n fez return antes é pq viu todos
              // os pares de elementos e não encontrou repetidos
}

int quantasVezes(int v[], int n, int k)
{
    int c=0;
    for(int i=0;i<n;i++)
        if(v[i]==k) c++;
    return c;
}

int temRepetidos2(int v[], int n)
{
    for(int i=n-2;i>0;i--)
        if(quantasVezes(v,i,v[i+1])>0) // 'engana' a função quantasVezes
            return 1;                  // indicando-lhe que v só tem i elementos
    return 0; // Se n fez return antes é pq viu todos
              // os pares de elementos e não encontrou repetidos
}

int contarComuns(int v[], int nv, int u[], int nu)
{
    int c=0;
    for(int i=0; i<nv; i++)
        if (quantasVezes(u, nu, v[i])>0) c++;
    return c;
}

int main()
{
    srand(time(0));  // para "aleatoriezar" ...

    int n;
    int v[10]; // reservo 10 casas, da nº 0 à nº 9
    int u[10];
    int w[10];

    n=8;         // só vou usar 8 casas, da nº 0 à nº 7

    //lerVetor(v,n);
    vetorASorte(v, 8, 20);

    printf("Vetor lido v : \n");
    escreverVetor(v,n);

    printf("A soma dos %d elementos do vetor é %d\n",n,somarVetor(v,n));

    copiarVetor(v,u,n);
    printf("Vetor copiado u : \n");
    escreverVetor(u,n);

    virarVetor(u,n);
    printf("Vetor virado u : \n");
    escreverVetor(u,n);

    rodarVetorDireita(u,n);
    printf("Vetor rodado u : \n");
    escreverVetor(u,n);

    printf("Maior elemento de u : %d \n",maiorElementoDoVetor(u,n));

    printf("Posição do maior elemento de u : %d \n",posicaoDoMaior(u,n));
    printf("Maior elemento de u : %d \n",u[posicaoDoMaior(u,n)]);

    somar2vetores(v,u,w,n);
    printf("Vetor soma w : \n");
    escreverVetor(w,n);

    somarKaUmVetor(w,-3,n);
    printf("Vetor w somado com -3: \n");
    escreverVetor(w,n);

    multiplicarKporUmVetor(w,10,n);
    printf("Vetor w multiplicado por 10: \n");
    escreverVetor(w,n);

    printf("Produto interno de u por v : %d \n",produtoInterno(u,v,n));

    printf("Média do vetor w : %.3f \n",mediaDeUmVetor(w,n));
    printf("Média 3 primeiros eltos de w : %.3f \n",mediaDeUmVetor(w,3));

    vetorASorte(v, 4, 20);
    escreverVetor(v, 4);
    if (temRepetidos(v,4)) printf("Tem Repetidos\n");
    else                    printf("Não Tem Repetidos\n");
    if (temRepetidos2(v,4)) printf("Tem Repetidos\n");
    else                     printf("Não Tem Repetidos\n");


    getchar();
    return 0;
}

/// Exercícios:

/// 0) Acrescentar na main código para testar as funções não testadas

/// Escrever as funções apropriadas e o respectivo código da main() para:

/// a) construir um vetor v com os n primeiros números naturais
///    por ordem crescente

/// b) obter um vetor w a partir de v tal que
///    w[i]=0 se v[i] for par
///    w[i]=1 se v[i] for ímpar

/// c) devolver o número de vezes que k aparece no vetor v de n elementos

/// d) devolver 1 se o vetor     tem números repetidos
///    devolver 0 se o vetor não tem números repetidos

/// e) devolver quantos números aparecem simultaneamente
///    nos vetores v1 (n1 elementos) e v2 (n2 elementos)

/// f) calcular e devolver a norma de um vetor w
///    norma de um vetor é a raiz quadrada da soma dos quadrados dos elementos

/// g) calcular e devolver o ângulo (em radianos) entre 2 vetores
///    angulo(u,v)=acos(produtoInterno(u,v)/(norma(u)*norma(v)))

/// h) criar um vetor f com os primeiros n elementos da sucessão de
///    Fibonacci

/// i) rodar k casas para a direita o vetor z
///    (repetir k vezes rodar uma casa)

/// j) rodar o vetor z 1 casa para a esquerda

/// k) trocar os elementos das posições p1 e p2 do vetor v

/// l) calcular a média e o desvio padrão dos elementos de v
///    sugestão: faça 3 funções:
///    1 - calcular só a média e devolver por valor
///    2 - calcular só o desvio padrão e devolver por valor
///        (usando a função anterior para o cálculo da média)
///    3 - calcular ambos (usando as 2 funções anteriores)
///        e devolver ambos por endereço

/// m) calcular um vetor t resultante da justaposição de x com y
///    (se x=[1 2 3 4 5] e y=[9 9 8 7 6 1], fica t=[1 2 3 4 5 9 9 8 7 6 1])
///    a função deve "arranjar maneira" de comunicar à main
///    o tamanho do vetor t obtido (alterar o valor de nt da main)...

/// n) acrescentar 7 zeros ao vetor w
///    (ao declarar w é necessário garantir que tem casas suficientes)
///    a função deve actualizar o valor da quantidade de elementos do vetor n,
///    logo, n tem que ser passado por referência ou endereço;

/// o) obter um vetor w, da mesma dimensão de v, em que:
///    w[0]   é  0 (o primeiro é zero)
///    w[n-1] é  0 (o último   é zero)
///    w[i]   é  1 se v[i] é um máximo local de v (maior q o à esq e q o à dir)
///    w[i]   é -1 se v[i] é um mínimo local de v (menor q o à esq e q o à dir)
///    w[i]   é  0 se v[i] não é máximo nem mínimo local de v
///    Um máx local é quando um valor é simultaneamente
///    maior do que o que está à sua esquerda e maior do que está à sua direita no vetor
///    Exemplo:
///    v = [ 1 3 6 5  3 4 5 6 8 9 5 ] resulta
///    w = [ 0 0 1 0 -1 0 0 0 0 1 0 ]

/// p) calcular o vetor z resultante da convolução
///    entre x (tamanho nx) e y (tamanho ny)
///    (muito difícil)
///    convolução:
///    z[k] = somatório_em_i ( x[i]*y[k-i] ), com i de 1 a k-1
///    notar que nz=nx+ny-1;

/// q) função para "desenhar" um vetor
///    Exemplo:
///    v=[4 8 3 5]
///    Resulta escrito (a função escreve) no ecran:
///
///    XXXX
///    XXXXXXXX
///    XXX
///    XXXXX

/// r) função que lê os coeficientes de um polinómio de grau g
///    para um vetor. (para um polinómio de grau 4 o vetor tem 5 elementos)
///    a(x) = a0*x^0 + a1*x^1+ a2*x^2 + ... + an*x^n

/// s) função para somar 2 polinómios guardados em vetores
///    conforme r)    p(x)=a(x)+b(x)
///    Notar que o grau de p é o maior dos graus de a e de b
///    Logo, gp=max(ga,gb)
///    gp tem que ser "comunicado" à main...
///    Exemplo:
///    a(x) = 3 + 4x + 0x^2 + 7x^3     --->  [ 3 4 0 7 ]  ga=3
///    b(x) = 5 + 1x + 2x^2            --->  [ 5 1 2 ]    gb=2
///    Resulta:
///    p(x) = 8 + 5x + 2x^2 + 7x^3     --->  [ 8 5 2 7 ]  gp=3

/// t) função para multiplicar 2 polinómios guardados em vetores
///    conforme r)    p(x)=a(x)*b(x)
///    Notar que o grau de p (gp) é a soma os graus de a (ga) e de b (gb)
///                                        gp = ga + gb
///    (  Como gp=np-1 , ga=na-1 e gb=nb-1  ----> np=na+nb-1    )

///    gp tem que ser "comunicado" à main
///    Exemplo:
///    a(x) = 3 + 4x                 --->  [ 3 4 ]       ga=1
///    b(x) = 5 + 0x + 2x^2          --->  [ 5 0 2 ]     gb=2
///    Resulta:
///    p(x) = 15 + 20x +6x^2 + 8x^3  --->  [15 20 6 8 ]  gp=3

/// u) na main, escrever código para visualizar graficamente
///    a soma e o produto de polinómios, representando os operandos e o resultado
///    (usando alínea q)



