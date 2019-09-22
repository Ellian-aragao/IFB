#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void)
{
    // 1ª entrada no programa
    int n; // grau do polinomio
    scanf("%d", &n);
    if (n >= 0 && n <= 6) // verifica se o grau esta no espaço amostral
    {
        // 2ª entrada no programa
        float *coeficientes = malloc((n + 1) * sizeof(float)); // aloca memória para os coeficientes da função  "Ai"
        testeDeAlocacao(coeficientes);                     // testa se a alocação foi efetiva
        for (int i = 0; i <= n; i++)                       // salva os coeficientes no vetor de coeficientes
        {
            float aux;
            scanf("%f", &aux);
            if (aux >= -10 && aux <= 10) coeficientes[i] = aux; // analisa se os coeficientes estão dentro do espaço amostral
            else i--;
        }
        
        // 3º entrada do programa
        float limite[2]; // limites primário, inferior e superior   (l, m, r)
        scanf("%f %f",&limite[0],&limite[1]);


        /////////////////////////////////////           saída do programa       /////////////////////////////////////////////


        printf("\n%f\n",verificador(limite, coeficientes, n));
        free(coeficientes);
    }
    return 0;
}