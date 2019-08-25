#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//compilar usando "-lm" como ultimo argumento

//deu erro para casos maiores
double pot(double x, double i);
//fatorial
double fat(double num);

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    double sinx = x;
    int j = 1;

    for (double i = 3; j <= 16; i += 2, j++)
    {
        if ((j % 2) == 0)
        {
            //printf("fat =  %lf\n",fat(i));
            //printf("pot = %lf\n",pot(x,i));
            sinx += pow(x, i) / fat(i);
        }
        else
        {
            //printf("fat =  %lf\n",fat(i));
            //printf("pot = %lf\n",pot(x,i));
            sinx -= pow(x, i) / fat(i);
        }
        printf("%lf\n", sinx);
    }

    return 0;
}

double pot(double x, double i)
{
    for (double j = 0; j <= i; j++)
    {
        x *= x;
    }
    return x;
}

double fat(double num)
{
    
    double x = 1;
    for (int i = 1; i <= num; i++)
    {
        x *= i;
    }
    return x;
    //return (num == 0 ? 1 : num * (fat(num - 1)));
}