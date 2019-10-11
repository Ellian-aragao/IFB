#include <stdio.h>
#include <math.h>
void linha(int x)
{
    for (int i = 1; i <= x; i++) putchar('*');
}
int main()
{
    int x;
    scanf("%d", &x);
    for (int linhas = 0; linhas < x; linhas ++)
    {
        if (linhas < x / 2) linha(linhas + 1);
        else linha(fabs(linhas - x));
        putchar('\n');
    }
    return 0;
}