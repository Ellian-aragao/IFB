#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("digite quantos numeros deseja digitar:\t");
        scanf("%d", &n);

        if (n == 0)
        {
            puts("digite um número válido\n\n\n");
        }

    } while (n <= 0);

    putchar('\n');

    int x, maior = 0, menor = 0, seg_maior = 0, seg_menor = 0;
    for (int i = 0; i < n; i++)
    {
        printf("digite um número:\t");
        scanf("%d", &x);

        if (i == 0)
        {
            maior = x;
            menor = x;
        }
        else
        {
            if (i == 1)
            {
                seg_maior = x;
                seg_menor = x;

                if (x > maior)
                {
                    seg_maior = maior;
                    maior = x;
                }
                if (x < menor)
                {
                    seg_menor = menor;
                    menor = x;
                }
            }
            else
            {
                if (x > maior)
                {
                    seg_maior = maior;
                    maior = x;
                }
                else if (x < maior && x > seg_maior)
                {
                    seg_maior = x;
                }

                if (x < menor)
                {
                    seg_menor = menor;
                    menor = x;
                }
                else if (x > menor && x < seg_menor)
                {
                    seg_menor = x;
                }
            }
        }
    }

    printf("\n\n\
            o maior elemento:\t%d\n\
            o segundo maior elemento:\t%d\n\
            o segundo menor elemento:\t%d\n\
            o menor elemento:\t%d\n\n",
           maior, seg_maior, seg_menor, menor);
    
    return 0;
}