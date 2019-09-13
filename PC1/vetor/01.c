#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//testa os números para encontrar os primos
void whereisprimos(int *primos, int x);

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    printf("argumento %d\n", x);
    if (x >= 10000 || x <= 0) puts("numero invalido"); // verifica se esta dentro do espaco amostral
    else
    {

        int *primos = malloc(x * sizeof(int));
        if (primos == NULL) //verifica se a alocação de memória foi bem sucedida
        {
            puts("ERROR");
            free(primos);
            exit(1);
        }

        if (x == 1) primos[0] = 2; // corta caminho caso seja 1
        else
        {
            primos[0] = 2;
            whereisprimos(primos, x);
        }

        for (int i = 0; i < x; i++) printf("%d ", primos[i]); // exibe os primos
        putchar('\n');

        free(primos);
    }
    return 0;
}

void whereisprimos(int *primos, int x)
{
    int i = 3; // parâmetro inicial para primos

    for (int j = 1; j < x; j++) // posição no vetor de primos
    {
        int primoDetect = TRUE;

        while (primoDetect) // loop para encontrar os primos
        {
            for (int t = 0; t < j; t++) // verificar se ele é primo
            {
                if (i % primos[t] == 0  &&  i != primos[t]) break; // testa se é divisível por algum primo
                if (j <= t + 1) primoDetect = FALSE; // parâmetro para definir se é primo
            }

            if (primoDetect == FALSE) primos[j] = i; // salva o número primo

            i += 2; // pula numeros pares
        }
    }
}