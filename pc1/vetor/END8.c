#include <stdio.h>
#include <stdlib.h>
int main()
{
    unsigned int n;
    scanf("%d",&n);
    //alocação de matriz dinâmica
    float **temp = (float**) malloc(n * sizeof(float*));
    for (unsigned int i = 0; i < n; i++) temp[i] = (float*) (malloc(2 * sizeof(float)));

    // obtenção dos valores do tempo
    for (unsigned int i = 0; i < n; i++)
    {
        scanf("%f",&temp[0][i]);
        temp[1][i] = i + 1;

        // limitador para funcionamento
        if (i > 0)
        {
            // ordenador
            for (unsigned int j = 0; j < i; j++)
            {
                // critérios de ordenação
                if (temp[i] < temp[j])
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

    puts("dia  temperatura");
    for (unsigned int i = 0; i < n; i++) printf("%.0f\t%.1f\n",temp[1][i],temp[0][i]);


    free(temp);
    return 0;
}
