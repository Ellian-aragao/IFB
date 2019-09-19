#include <stdio.h>
#include <stdlib.h>

// alocar a quantidade de números relativo ao fibonacci
int *fib(int n);
// realiza o somatório da função de fib
float somatorio(int limite_inf, int limite_sup, int *fibonacci);
// atualização do tamanho do vetor
void realoc_fib(int *fibonacci, int antigo_limitante, int novo_limitante);

int main(void)
{
    int n; // pares de inteiros
    scanf("%d", &n);
    if (n >= 1 && n <= 100)
    {
        puts("digite o par de inteiros limitantes do somatório, sendo o primeiro limite inferior e o segundo superior");
        int lim_infelior, lim_superior0, lim_superior; // limitantes
        int *fibonacci = NULL;                         // futuro vetor dos nuns de fib
        for (int i = n; i > 0; i--)
        {
            scanf("%d %d", &lim_infelior, &lim_superior0);

            if (i == n) // cria o vetor de fibonacci quando é a primeira iteração
            {
                lim_superior = lim_superior0;
                fibonacci = fib(lim_superior);
            }
            else if (lim_superior0 > lim_superior) // verifica se o limite máximo foi alterado
            {
                realoc_fib(fibonacci, lim_superior, lim_superior0);
                lim_superior = lim_superior0;
            }

            printf("para o par %d e %d, o somatório e = %.0f\n", lim_infelior, lim_superior, somatorio(lim_infelior, lim_superior, fibonacci));
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
float somatorio(int limite_inf, int limite_sup, int *fibonacci)
{
    float soma = 0;
    for (int i = limite_inf; i <= limite_sup; i++) soma += fibonacci[i];
    return soma;
}

// atualização do tamanho do vetor
void realoc_fib(int *fibonacci, int antigo_limitante, int novo_limitante)
{
    fibonacci = (int *)realloc(fibonacci, novo_limitante * sizeof(int));
    for (int i = antigo_limitante; i < novo_limitante; i++) fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]; // atualização
}