#include <stdio.h>
#include <stdlib.h>

void fib(int n)
{
    if (n > 0)
    {
        int *fibonacci = malloc(n * sizeof(int));

        fibonacci[0] = 1;
        if (n > 1)
            fibonacci[1] = 1;

        for (int i = 2; i < n; i++)
        {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }

        for (int i = 0; i < n; i++)
        {
            printf("%d,", fibonacci[i]);
        }

        putchar('\n');
        free(fibonacci);
    }
}

void somatorio()
{
    
}

int main(void)
{
    int n;
    scanf("%d", &n);

    if (n <= 0 || n > 100)
        return 0;

    fib(n);

    return 0;
}