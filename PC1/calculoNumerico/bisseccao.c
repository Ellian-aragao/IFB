#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ERRO 1e-3

// executa os testes para atualização dos limites e retorna um valor relativo ao ERRO
float verificador(float *limite, int *coeficientes, int n);
// faz o calculo do ponto médio
float pontoMedio(float *limite);
// calcula a função de X --> F(x)
float FdeX(int *coeficientes, int n, float X);
// função de potência
float pot(double base, int potencia);
// verifica se a alocação de memória funcionou
void testeDeAlocacao(void *ptr);

int main(void)
{
    // 1ª entrada no programa
    int n; // grau do polinomio
    scanf("%d", &n);
    if (n >= 0 && n <= 6) // verifica se o grau esta no espaço amostral
    {
        // 2ª entrada no programa
        int *coeficientes = malloc((n + 1) * sizeof(int)); // aloca memória para os coeficientes da função  "Ai"
        testeDeAlocacao(coeficientes);                     // testa se a alocação foi efetiva
        for (int i = 0; i <= n; i++)                       // salva os coeficientes no vetor de coeficientes
        {
            int aux;
            scanf("%d", &aux);
            if (aux >= -10 && aux <= 10) coeficientes[i] = aux; // analisa se os coeficientes estão dentro do espaço amostral
            else i--;
        }
        
        // 3º entrada do programa
        float limite[3]; // limites primário, inferior e superior   (l, m, r)
        scanf("%f %f",&limite[0],&limite[2]);
        limite[1] = limite[0];


        /////////////////////////////////////           saída do programa       /////////////////////////////////////////////


        printf("\n%f\n",verificador(limite, coeficientes, n));
        free(coeficientes);
    }
    return 0;
}

// executa os testes para atualização dos limites e retorna um valor relativo ao ERRO
float verificador(float *limite, int *coeficientes, int n)
{
    float media = pontoMedio(limite); // ponto médio
    while (1)
    {
        media = pontoMedio(limite);
        if (FdeX(coeficientes, n, media) * FdeX(coeficientes, n, limite[1]) < 0) limite[2] = media; // executa o T.V.M
        else limite[1] = media;
        if (fabs(FdeX(coeficientes, n, media)) < ERRO) break; // ponto de parada em relação a precisão
    }
    return media;    
}

// faz o calculo do ponto médio
float pontoMedio(float *limite)
{
    return (limite[1] + (limite[2] - limite[1]) / 2);
}

// calcula a função de X --> F(x)
float FdeX(int *coeficientes, int n, float X)
{
    float FdeX = 0;
    for (int i = 0; i <= n; i++) FdeX += coeficientes[i] * pot(X, i); // produto escalar dos coeficientes e vetorX
    return FdeX;
}

// função de potência
float pot(double base, int potencia)
{
    if (potencia == 0) return 1;
    else
    {
        double base_orig = base;
        for (int i = 1; i < potencia; i++)base *= base_orig;
        return base;
    }
}

// verifica se a alocação de memória funcionou
void testeDeAlocacao(void *ptr)
{
    if (ptr == NULL) exit(1);
}