#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    double investimento = atoi(argv[1]);
    int meses = atoi(argv[2]);
    double juros = atoi(argv[3]);
    juros /= 100;

    printf("numero de meses\t\t investimento acumulado\n");
    for (int i = 0; i < meses; i++)     printf("\t%02d\t\t\t%.2lf\n", i, (investimento * pow((1 + juros), i)));

    return 0;
}