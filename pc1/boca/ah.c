#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);

    // talvez tenha que tracar o malloc para calloc para iniciar com 0
    int **matriz = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) matriz[i] = malloc(2 * sizeof(int));

    // salva os valores e ordena
    for (int i = 0; i < n; i++)
    {
        // salva os valores e conta
        scanf("%d",&matriz[0][i]);

        // fazer algoritmo para percorrer vetor de maneira eficiente
        for (int j = 0; j <= i; j++)
        {
            if (matriz[0][i] == matriz[0][j])
            {
                matriz[1][i] += 1 ;
            }
        }

        // limitador para funcionamento da ordenação
        if (i > 0)
        {
            // ordenador
            for (int j = 0; j < i; j++)
            {
                if (matriz[0][i] < matriz[0][j])
                {
                    // troca dos valores primários comparativos
                    int aux = matriz[0][j];
                    matriz[0][j] = matriz[0][i];
                    matriz[0][i] = aux;

                    // troca dos valores segundarios de contagem
                    aux = matriz[1][j];
                    matriz[1][j] = matriz[1][i];
                    matriz[1][i] = aux;
                }
            }
        }
    }

    return 0;
}