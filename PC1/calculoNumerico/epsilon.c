#include <stdio.h>
#include <float.h>
int main(void)
{
    float epsilonF = 1;
    double epsilonD = 1;

    // código desenvolvido por mim
    while (epsilonF / 2 != 0) epsilonF /= 2;
    while (epsilonD / 2 != 0) epsilonD /= 2;

    // código desenvolvido pelo henrique e gustavo, resultado diferente e muito maior que o obtido no anterior
    //while (epsilonF + 1 != 1) epsilonF /= 2;
    //while (epsilonD + 1 != 1) epsilonD /= 2;
    
    printf("epsilon float = %e\nepsilon double = %e\n",epsilonF,epsilonD);
    //printf("%e %e\n",FLT_MIN,DBL_MIN);
    return 0;
}