#include <stdio.h>
#include <stdlib.h>

void Taylor();
// calcula a função de X
float FdeX(int *coeficientes, float X, int n);
// função de potência
float pot(float base, int potencia);
// função fatorial
float fat(float n);

int main(void)
{
    // 1ª entrada no programa
    int n; // grau do polinomio
    scanf("%d", &n);
    if (n >= 0 && n <= 6) // verifica se o grau esta no espaço amostral
    {

        // 2ª entrada no programa
        int *coeficientes = malloc(n * sizeof(int)); // aloca memória para os coeficientes da função
        for (int i = 0; i <= n + 1; i++) // salva os coeficientes no vetor de coeficientes
        {
            int aux;
            scanf("%d",&aux);
            if (aux >= -10 && aux <= 10) coeficientes[i] = aux; // analisa se os coeficientes estão dentro do espaço amostral
            else i--;
        }


        // 3ª entrada no programa
        int consultas = -1; // quantidade valores de 'x' a serem testados
        while (consultas < 0 || consultas > 100) scanf("%d",&consultas); // determina a quantidade de consultas serão feitas


        // ultimas entradas dependentes da 3ª
        float *valoresDeConsulta = malloc(consultas * sizeof(float)); // aloca a memória para os valores de 'x'
        for (int i = 0; i <= consultas; i++) scanf("%f",&valoresDeConsulta[i]); // determina quais valores serão testados


        float *dx = malloc((n + 1) * sizeof(float)); // vetor de derivadas do polinomio


        /* terminar esse código hoje */
        for (int i = n + 1; i > 0; i--) dx[i] = i - 1; // continuar testando o pensamento quanto derivação


        free(coeficientes);
        free(valoresDeConsulta);
    }

    return 0;
}

// polinomio de Taylor
void Taylor()
{

}

// calcula a função de X
float FdeX(int *coeficientes, float X, int n)
{
    float FdeX = 0;
    for (int i = 0; i <= n; i++) FdeX += coeficientes[i] * pot(X,i); // produto escalar dos coeficientes e vetorX
    return FdeX;
}

// função de potência
float pot(float base, int potencia)
{
    for (int i = 1; i < potencia; i++) base *= base;
    return base;
}

// função fatorial
float fat(float n)
{
    return (n == 0 ? 1 : n * fat(n-1));
}