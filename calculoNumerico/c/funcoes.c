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
    return (limite[0] + (limite[1] - limite[0]) / 2);
}

float verificador(float *limite, float *coeficientes, int n)
{
    float media; // ponto médio
    int cont = 0; //  contador
    while (1) // loop infinito
    {
        media = pontoMedio(limite); // atribui novo valor ao ponto médio
        if (fabs(FdeX(coeficientes, n, media)) < ERRO) break; // ponto de parada em relação a precisão

        if (FdeX(coeficientes, n, media) * FdeX(coeficientes, n, limite[0]) < 0) // executa o T.V.M
        {/*
            if (fabs(media - limite[1]) < ERRO) // valor de erro maior que a diferença do ponto anterior com a média
            {
                puts("raiz não encontrada");
                exit(0);
            }
            */
            limite[1] = media; // salva novo limite
        }
        else
        {/*
            if (fabs(media - limite[0]) < ERRO) // valor de erro maior que a diferença do ponto anterior com a média
            {
                puts("raiz não encontrada");
                exit(0);
            }
            */
            limite[0] = media; // salva novo limite
        }

        // contador para tempo de execusão do algorítmo
        cont++;
        if (cont >= 1e4)
        {
            puts("raiz nao encontrada");
            exit(0);
        }
    }
    return media;
}

void bisseccao()
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
}

void taylor()
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
}

void epsilon()
{
    float epsilonF = 1;
    double epsilonD = 1;

    // código desenvolvido por mim
    while (epsilonF / 2 != 0) epsilonF /= 2;
    while (epsilonD / 2 != 0) epsilonD /= 2;

    // código desenvolvido pelo henrique e gustavo, resultado diferente e muito maior que o obtido por mim
    //while (epsilonF + 1 != 1) epsilonF /= 2;
    //while (epsilonD + 1 != 1) epsilonD /= 2;
    
    printf("epsilon float = %e\nepsilon double = %e\n",epsilonF,epsilonD);
    //printf("%e %e\n",FLT_MIN,DBL_MIN);
}

void limpartela()
{
    system("clear");
}