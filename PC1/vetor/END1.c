#include <stdio.h>
#include <stdlib.h>

//test the numbers for search primos
void whereisprimos(int *primos, int x)
{/*
    int j = 3;
    for (int i = 2; i < x; i++)
    {
        int num = 2;
        for (; j < (primos[i] / 2) + 1; j += 2)
        {
            if (j % primos[num] == 0)
            {
                primos[i] = j;
                break;
                //printf("\nnum primo %d na posicao %d", primos[i], i);
            }
        }
    }
}*/

        for (int i = 3; i <= (x / 2) + 1; i += 2)
        {
            if (x % i == 0)
            {
                printf("o numero '%d' não é primo\n", x);
                break;
            }
        }
}

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    printf("\nargumento %d\n", x);
    if (x >= 10000)
    {
        puts("numero invalido");
    }
    else if (x > 0)
    {
        int *primos = malloc(x * sizeof(int));
        if (primos == NULL)
        {
            puts("error");
            free(primos);
            return 0;
        }
        switch (x)
        {
        case 1:
            primos[0] = 2;
            break;
        case 2:
            primos[0] = 2;
            primos[1] = 3;
            break;
        default:
            primos[0] = 2;
            primos[1] = 3;
            whereisprimos(primos, x);
            break;
        }

        for (int i = 0; i < x; i++)
            printf("'%d' ", primos[i]);
        putchar('\n');

        free(primos);
    }
    return 0;
}
