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
    for (int i = 0; i < x; i++)
    {
        putchar(' ');
    }
}

int main(int argc, char *argv[])
{
    int tam = atoi(argv[1]);
    int tam_variavel = tam;
    int i;

    for (i = 1; i <= tam; i = i + 2, tam_variavel--)
    {
        espaco(tam_variavel);
        linha(i);
        putchar('\n');
    }

    return 0;
}