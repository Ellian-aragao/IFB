#include <stdio.h>
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

int main()
{
    int tam;
    scanf("%d",&tam);
    int tam_variavel = tam;
    int i;

    for (i = 1; i <= tam; i += 2, tam_variavel--)
    {
        espaco(tam_variavel);
        linha(i);
        putchar('\n');
    }


    for (i -= 4, tam_variavel += 2; i >= 0; i = i - 2, tam_variavel++)
    {
        espaco(tam_variavel);
        linha(i);
        putchar('\n');
    }

    return 0;
}