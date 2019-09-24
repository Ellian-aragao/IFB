#include <stdio.h>
#include <stdlib.h>

// alocar a quantidade de números relativo ao fibonacci
int *fib(int n);
// realiza o somatório da função de fib
float somatorio(int limite_inf, int limite_sup, int *fibonacci);
// atualização do tamanho do vetor
int* realoc_fib(int *fibonacci, int antigo_limitante, int novo_limitante);
// em caso de erro de alocação encerra o programa
void problemaDealocacao(int *vetor);

int main(void)
{
    int n; // pares de inteiros
    scanf("%d", &n);
    if (n >= 1 && n <= 100) // intervalo para os pares
    {
        int lim_infelior, lim_superior0, lim_superior; // limitantes
        int *fibonacci = NULL;                         // futuro vetor dos nuns de fib
        for (int i = n; i > 0; i--)
        {
            scanf("%d %d", &lim_infelior, &lim_superior0);

            if (i == n) // cria o vetor de fibonacci quando é a primeira iteração
            {
                lim_superior = lim_superior0;
                fibonacci = fib(lim_superior);
                problemaDealocacao(fibonacci);
            }
            else if (lim_superior0 > lim_superior) // verifica se o limite máximo foi alterado
            {
                fibonacci = realoc_fib(fibonacci, lim_superior, lim_superior0);
                problemaDealocacao(fibonacci);
                lim_superior = lim_superior0;
            }

            printf("[%d,%d], somatorio = %.0f\n", lim_infelior, lim_superior, somatorio(lim_infelior, lim_superior, fibonacci));
        }
        free(fibonacci);
    }
    return 0;
}

// alocar a quantidade de números relativo ao fibonacci
int *fib(int limite_sup) // corrigir sistema de alocação de memória para atingir fim desejado
{
    int *fibonacci = malloc(limite_sup * sizeof(int)); // aloca o vetor dos números de fibonacci
    fibonacci[0] = 1;                                  // valor do primeiro elemento
    fibonacci[1] = 1;                                  // valor do segundo elemento
    for (int i = 2; fibonacci[i - 1] < limite_sup; i++) fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]; // cálculo da sequência de fib
    return fibonacci;
}

// realiza o somatório da função de fib
float somatorio(int limite_inf, int limite_sup, int *fibonacci) // função está errada
{
    float soma = 0;
    for (int i = 0;fibonacci[i] >= limite_inf && fibonacci[i] <= limite_sup; i++) soma += fibonacci[i];
    return soma;
}

// atualização do tamanho do vetor
int* realoc_fib(int *fibonacci, int antigo_limitante, int novo_limitante)
{
    fibonacci = (int*)realloc(fibonacci, novo_limitante * sizeof(int));
    for (int i = antigo_limitante; i < novo_limitante; i++) fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]; // atualização
    return fibonacci;
}

// em caso de erro de alocação encerra o programa
void problemaDealocacao(int *vetor)
{
    if (vetor == NULL) exit(0);
}