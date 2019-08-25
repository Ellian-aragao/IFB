#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);

    if (n < 0) puts("valor invalido");
    else if (n > 10) puts("valor invalido");
    else
    {
        float vetor[n];
        for (int i = 0; i < n; i++)
        {
            float y;
            scanf("%f", &y);
            setbuf(stdin, NULL);
            vetor[i] = y;
        }

        float quadrado = 0;
        for (int i = 0; i < n; i++) quadrado += pow(vetor[i], 2);

        float media = 0;
        for (int i = 0; i < n; i++) media += vetor[i] / n - 1;

        float desvPadrao = sqrt(( quadrado * pow(media, 2)) / n );
        printf("media = '%f'\ndesvio padrao = '%f'\n", quadrado, desvPadrao);
    }
    return 0;
}