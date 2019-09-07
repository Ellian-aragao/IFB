#include<stdio.h>
#define ERROR 1e-10

int main(void)
{
    double pi = 0;
    double piA = pi;
    for (double i = 0; 1 ; i++)
    {
        pi += 8/((4*i+1)*(4*i+3));
        if ((int) i % 1000000000 == 0) printf("%0.64lf\n",pi);
        piA = pi;
    }

    return 0; // if possible
}