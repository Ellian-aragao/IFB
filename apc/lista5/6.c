#include<stdio.h>
#define taxaDeErro 0,000005
/* o programa não está funcionando como deveria */
int main()
{
    int i,n;
    double ai,aj,pi=0;
    for(i=1;i<=10;i++)
    {
        printf("%d\t",i);
        if (i % 2 == 0)
        {
            ai=1/(1+((i-1)*2));
            pi=pi-(4*ai);
            printf("%f\n",pi);
        }
        else
        {
            aj=1/(1+((i-1)*2));
            pi=pi+(4*aj);
            printf("%f\n",pi);
        }
        if (n % 2 == 0)
        {
            if ((aj-ai) <= taxaDeErro)
            {
            //    break;
            }
        }
        else
        {
            if ((ai-aj) <= taxaDeErro)
            {
            //    break;
            }
        }
    }
    printf("%f\n",pi);
}