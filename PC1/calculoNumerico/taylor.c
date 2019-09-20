#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funcoes.h"
#define ERRO 1e-3

int main(void)
{
    // 1ª entrada no programa
    int n; // grau do polinomio
    scanf("%d", &n);
    if (n >= 0 && n <= 6) // verifica se o grau esta no intervalo correto
    {
        // 2ª entrada no programa
        float *coeficientes = malloc(n * sizeof(float));   // aloca memória para os coeficientes da F(x) e taylor
        testeDeAlocacao(coeficientes);                     // testa se a alocação foi efetiva
        for (int i = 0; i <= n; i++)                       // salva os coeficientes no vetor de coeficientes
        {
            float aux;
            scanf("%f", &aux);
            if (aux >= -10 && aux <= 10) coeficientes[i] = aux;  // analisa se os coeficientes estão dentro do intervalo
            else i--;                                            // volta o loop até um valor dentro do parâmetro
        }

        // 3ª entrada no programa
        int consultas = -1; // quantidade valores de 'x' a serem testados
        while (consultas < 0 || consultas > 100) scanf("%d", &consultas);       // determina a quantidade de consultas serão feitas

        // ultimas entradas dependentes da 3ª
        float *valoresDeConsulta = malloc(consultas * sizeof(float));           // aloca a memória para os valores de 'x'
        testeDeAlocacao(valoresDeConsulta);                                     // testa se a alocação foi efetiva
        for (int i = 0; i < consultas; i++) scanf("%f", &valoresDeConsulta[i]); // salva os valores a serem testados


        ///////////////////////////////////         saídas do programa        //////////////////////////////////////


        for (int i = 0; i < consultas; i++) // fazendo os testes em relação a quantidade de X inseridos
        {
            float taylor = 0;                                         // parâmetro de início do polinômio de Taylor
            float fdex = FdeX(coeficientes, n, valoresDeConsulta[i]); // valor da função F(x)
            for (int j = 0; j <= n; j++)
            {
                taylor += Taylor(coeficientes[j], valoresDeConsulta[i], j);  // aproximando do valor de F(x)
                printf("%d %lf %lf\n", j + 1, taylor, fdex);                 // exibição da "tabela"
                if (fabs(taylor - fdex) <= ERRO && taylor - fdex > 0) break; // critério de parada quando  > 0
            }
            putchar('\n');
        }
        free(coeficientes);
        free(valoresDeConsulta);
    }
    return 0;
}