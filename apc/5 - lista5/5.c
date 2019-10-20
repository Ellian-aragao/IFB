#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,delta,raiz0,raiz1,x;
    printf("entre com os valores a,b,c da equacao de segundo grau\n");
    scanf("%f%f%f",&a,&b,&c);
    delta=pow(b,2)-4*a*c;
    x=delta;
    if (delta>0)
    {
        raiz0=(-b+sqrt(delta))/(a*2);
        raiz1=(-b-sqrt(delta))/(a*2);
        printf("a equacao tem 2 raizes sendo elas\n\tx1 = '%.0f'\t\tx2 = '%.0f'\n",raiz0,raiz1);
    }
    else
    {
        if (delta==0)
        {
            raiz0=(-b)/(a*2);
            printf("a equacao tem 1 raiz sendo ela\n\tx1 = '%.0f'\n",raiz0);
        }
        else
        {
            raiz0=(-b)/(a*2);
            raiz1=sqrt(x*(-1));
            printf("o resultado tem como parte real '%.0f' e a parte imaginaria '%.0fi'\nZ=%.0f+%.0fi\n",raiz0,raiz1,raiz0,raiz1);
        }
        
    }
}
