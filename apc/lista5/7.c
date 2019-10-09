#include<stdio.h>
int main()
{
    int i;
    float n,x,y=0,z=0;
    printf("digite o número de notas\n");
    scanf("%f",&n);
    for (i=1;n>=i;i++)
    {
        printf("digite a nota\t");
        scanf("%f",&x);
        if (i%2==0)
        {
            y=y+(x*3);
            z=z+3;    
        }
        else
        {
            y=y+(x*2);
            z=z+2;
        }
    }
    printf("a nota final foi '%.1f'\n",y/z);
}