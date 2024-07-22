#include<stdio.h>

/// Função que (nao recebe nada - não tem var de entrada)
/// e devolve um NÚMERO real (garantidamente positivo)
float lerRealPositivo()
{
    float x;
    do scanf("%f",&x); while(x<=0);
    return x;
}

/// Função recebe dois NÚMEROS reais.
/// ao primeiro, chama-lhe P (guarda na var P)
/// ao  segundo, chama-lhe A (guarda na var A)
/// Devolve o NÚMERO que é o resultado da expressão
float calcularIMC(float P,float A)
{
    return P/(A*A);
}

/// Função não devolve nada: escreve-se void
/// apenas escreve no ecran a classificação
/// recebe um NÚMERO real (tipo float) a que chama IMC
/// (guarda na var IMC)
void escreverClassificacaoIMC(float IMC)
{
    if (IMC < 19) printf("Magro\n");    else        if (IMC < 25) printf("Normal\n");        else            if (IMC < 30) printf("Excesso\n");            else          printf("Gordo\n");
    /// como a função é void não leva o comando return
}


int main()
{
    float P,A,IMC;

    /// Ler peso e altura    printf("Peso  (kg) ? ");  P=lerRealPositivo();    printf("Altura (m) ? ");  A=lerRealPositivo();

    /// Calcular IMC    IMC=calcularIMC(P,A);    printf("IMC é de %.2f kg/m^2 \n",IMC);

    /// Escrever Classificação
    escreverClassificacaoIMC(IMC);    printf("Peso deve estar entre %.2f kg e %.2f kg\n",19*A*A,25*A*A);
    getchar();
    return 0;
}

/// Normalmente as funções não lêem nada (não têm scanf)
///                    nem escrevem nada (não têm printf)
/// Apenas RECEBEM e DEVOLVEM

/// Exceções:
/// Função para ler um inteiro (tem que ter scanf)
/// Função para escrever por extenso (tem que ter printf)





