#include <stdio.h>
#include <stdlib.h>
#define ERRO 1e-3

// calcula a função de X
float FdeX(int *coeficientes, int n, float X);
// função de potência
float pot(double base, int potencia);
// função fatorial
float fat(float n);
// polinomio de Taylor
float Taylor(int coeficiente, float x, int j);
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

        // 3ª entrada no programa
        int consultas = -1; // quantidade valores de 'x' a serem testados
        while (consultas < 0 || consultas > 100) scanf("%d", &consultas); // determina a quantidade de consultas serão feitas

        // ultimas entradas dependentes da 3ª
        float *valoresDeConsulta = malloc(consultas * sizeof(float));           // aloca a memória para os valores de 'x'
        testeDeAlocacao(valoresDeConsulta);                                     // testa se a alocação foi efetiva
        for (int i = 0; i < consultas; i++) scanf("%f", &valoresDeConsulta[i]); // salva os valores a serem testados


        ///////////////////////////////////         saídas do programa        //////////////////////////////////////


        for (int i = 0; i < consultas; i++) // fazendo os testes em relação a quantidade de X inseridos
        {
            float taylor = 0;                                         // parâmetro de início do polinômio de Taylor
            float fdex = FdeX(coeficientes, n, valoresDeConsulta[i]); // valor da função F(x)
            for (int j = 0; j <= n; j++)                              // temporário o parâmetro
            {
                taylor += Taylor(coeficientes[j], valoresDeConsulta[i], j);
                printf("%d %lf %lf\n", j + 1, taylor, fdex);

                if (taylor - fdex <= ERRO && taylor - fdex > 0) break; // critério de parada quando  > 0
                if (taylor == fdex) break;
            }
            putchar('\n');
        }
        free(coeficientes);
        free(valoresDeConsulta);
    }
    return 0;
}

// polinomio de Taylor
float Taylor(int coeficiente, float x, int j)
{
    return ((fat(j) * coeficiente) * (pot(x, j) / fat(j)));
}

// calcula a função de X --> F(x)
float FdeX(int *coeficientes, int n, float X) // ok
{
    float FdeX = 0;
    for (int i = 0; i <= n; i++) FdeX += coeficientes[i] * pot(X, i); // produto escalar dos coeficientes e vetorX
    return FdeX;
}

// função de potência
float pot(double base, int potencia) // ok
{
    if (potencia == 0) return 1;
    else
    {
        double base_orig = base;
        for (int i = 1; i < potencia; i++)base *= base_orig;
        return base;
    }
}

// função fatorial
float fat(float n)
{
    return (n == 0 ? 1 : n * fat(n - 1));
}

// verifica se a alocação de memória funcionou
void testeDeAlocacao(void *ptr)
{
    if (ptr == NULL) exit(1);
}