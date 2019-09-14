#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);

    int x, maior, menor, seg_maior, seg_menor;
    for (int i = 0; i < n; i++) // ordena os elementos conforme seu tamanho
    {
        scanf("%d", &x);

        if (i == 0)
        {
            maior = x;
            menor = x;
        }
        else if (i == 1)
        {
            seg_maior = x;
            seg_menor = x;
        }

        if (x > maior)
        {
            seg_maior = maior;
            maior = x;
        }
        else if (x > seg_maior)
        {
            seg_maior = x;
        }

        if (x < menor)
        {
            seg_menor = menor;
            menor = x;
        }
        else if (x < seg_menor)
        {
            seg_menor = x;
        }
    }

    if (n == 1) printf("%d\nnao definido\n%d\nnao definido",maior, menor);
    else printf("%d\n%d\n%d\n%d\n",maior,seg_maior,menor,seg_menor);

    return 0;
}