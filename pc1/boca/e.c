#include <stdio.h>
#include <stdlib.h>

void linha(int x)
{
    for (int i = 1; i <= x; i++)
    {
        putchar('*');
    }
}

void espaco(int x)
{
    for (int i = 1; i < x; i++)
    {
        putchar(' ');
    }
}

int main()
{
    int linhas;
    scanf("%d",&linhas);
    int tam_variavel = linhas;

    for (int i = 1; linhas > 0; i += 2, tam_variavel--, linhas--)
    {
        espaco(tam_variavel);
        linha(i);
        putchar('\n');
    }

    return 0;
}