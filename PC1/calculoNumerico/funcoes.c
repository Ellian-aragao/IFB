#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"
#define ERRO 1e-5 // erro para função verificadora

float Taylor(float coeficiente, float x, int i)
{
    return (coeficiente * pot(x, i));
}

float FdeX(float *coeficientes, int n, float X)
{
    float FdeX = 0;
    for (int i = 0; i <= n; i++) FdeX += coeficientes[i] * pot(X, i); // produto escalar dos vetores de coeficientes e um certo x
    return FdeX;
}

float pot(double base, int potencia)
{
    if (potencia == 0) return 1;
    else
    {
        double base_orig = base;
        for (int i = 1; i < potencia; i++) base *= base_orig;
        return base;
    }
}

void testeDeAlocacao(void *ptr)
{
    if (ptr == NULL) exit(1);
}

float pontoMedio(float *limite)
{
    return (limite[1] + (limite[2] - limite[1]) / 2);
}

float verificador(float *limite, float *coeficientes, int n)
{
    float media; // ponto médio
    while (1) // loop infinito
    {
        media = pontoMedio(limite); // atribui novo valor ao ponto médio
        if (fabs(FdeX(coeficientes, n, media)) < ERRO) break; // ponto de parada em relação a precisão

        if (FdeX(coeficientes, n, media) * FdeX(coeficientes, n, limite[1]) < 0) // executa o T.V.M
        {/*
            if (fabs(media - limite[1]) < ERRO) // valor de erro maior que a diferença do ponto anterior com a média
            {
                puts("raiz não encontrada");
                exit(0);
            }
*/
            limite[2] = media; // salva novo limite
        }
        else
        {/*
            if (fabs(media - limite[1]) < ERRO) // valor de erro maior que a diferença do ponto anterior com a média
            {
                puts("raiz não encontrada");
                exit(0);
            }
*/
            limite[1] = media; // salva novo limite
        }
    }
    return media;
}