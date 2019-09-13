#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

//testa os números para encontrar os primos
void whereisprimos(int x);

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    printf("argumento %d\n", x);

    if (x >= 10000 || x <= 0) puts("numero invalido"); // verifica se esta dentro do espaco amostral
    else if (x >= 2) whereisprimos(x);

    return 0;
}

void whereisprimos(int x)
{
    int *primos = malloc(1 * sizeof(int));
    if (primos == NULL) //verifica se a alocação de memória foi bem sucedida
    {
        puts("ERROR");
        free(primos);
        exit(1);
    }
    else primos[0] = 2;

    int test = TRUE;
    int i = 3; // parâmetro inicial para primos
    for (int j = 1; TRUE ; j++) // posição no vetor de primos
    {
        int *primos = realloc(primos, (j + 1) * sizeof(int)); // teste de proposta de realocar memória conforme necessidade

        int primoDetect = TRUE;

        while (primoDetect) // loop para encontrar os primos
        {
            for (int t = 0; t < j; t++) // verificar se ele é primo
            {
                if (i % primos[t] == 0 && i != primos[t]) break; // testa se é divisível por algum primo
                if (j <= t + 1)  primoDetect = FALSE; // parâmetro para definir se é primo
            }

            if (primoDetect == FALSE) primos[j] = i; // salva o número primo

            i += 2; // pula numeros pares
            
            if (i > x) // saida do loop de detecção do primo
            {
                test = FALSE;
                break;
            }
        }

        if (test == FALSE) break; // saída do loop posicional do vetor de primos
    }


    for (int i = 0; i < x; i++) printf("%d ", primos[i]); // exibe os primos
    putchar('\n');

    free(primos);
}


void maneiraPreguicosa(int x)
{
    int *primos = malloc(x * sizeof(int));
    if (primos == NULL) //verifica se a alocação de memória foi bem sucedida
    {
        puts("ERROR");
        free(primos);
        exit(1);
    }

    for (int i = 2; i < x; i++) primos[i - 2] = i; // preenche o vetor

    for (int i = 2; i < x; i++) // continuar a partir da ideia de percorrendo o vetor e testando ele mesmo quando != 0
    {
        
    }
    



    free(primos);
}