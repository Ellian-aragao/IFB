#include <stdio.h>

double pot(double x, double i)
{
    double valor = x;
    for (long int j = 1; j < i; j++)
    {
        valor *= x;
    }
    return valor;
}

double fat(double num)
{

    double x = 1;
    for (int i = 1; i <= num; i++)
    {
        x *= i;
    }
    return x;
}

int main()
{
    double x;
    scanf("%lf", &x);
    double sinx = 0;
    long int par = 0;

    for (long int i = 1, par = 0; par < 20; i += 2, par++)
    {
        if (par % 2 == 0) sinx += pot(x, i) / fat(i);
        else sinx -= pot(x, i) / fat(i);
    }

    printf("%lf\n", sinx);
    return 0;
}
