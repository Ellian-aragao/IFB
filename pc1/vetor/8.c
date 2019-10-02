#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    //alocação de matriz dinâmica
    float **temp = (float**) malloc(n * sizeof(float*));// numero de elementos da linha
    for (int i = 0; i < n; i++) temp[i] = (float*) (malloc(2 * sizeof(float))); // salvar a coluna dos dias da matriz

    float media = 0;

    // obtenção dos valores do tempo
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&temp[0][i]);
        media += temp[0][i] / n;
        temp[1][i] = i + 1; // salva o dia do elemento

        // limitador para funcionamento
        if (i > 0)
        {
            // ordenador
            for (int j = 0; j < i; j++)
            {
                // critérios de ordenação
                if (temp[0][i] < temp[0][j])
                {
                    // troca do valor da temperatura
                    float aux = temp[0][j];
                    temp[0][j] = temp[0][i];
                    temp[0][i] = aux;

                    //troca do dia em que ocorreu
                    aux = temp[1][j];
                    temp[1][j] = temp[1][i];
                    temp[1][i] = aux;
                }
            }
        }
    }


    printf("menor temperatura %.1f no dia %.0f\n",temp[0][0],temp[1][0]);
    printf("maior temperatura %.1f no dia %.0f\n",temp[0][n - 1],temp[1][n - 1]);
    printf("media datemperatura %.1f\n",media);
    printf("dias que a temperatura foi maior ou igual da media no dia: ");
    for (int i = 0; i < n; i++) if (temp[0][i] >= media) printf("%.0f, ",temp[1][i]);
    putchar('\n');

    free(temp);
    return 0;
}
