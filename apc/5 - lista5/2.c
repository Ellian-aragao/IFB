#include<stdio.h>
int main()
{
    int l,c,i,u,x=0;
    printf("digite o numero de linhas da matriz\t");
    scanf("%d",&l);
    printf("digite o numero de colunas da matriz\t");
    scanf("%d",&c);
    printf("\n\t\t\tMatriz %d X %d\n\n",l,c);
    for (i=1;l>=i;i++)
    {
        printf("Linha--> '%d'\t\t",i);
        for (u=1;c>=u;u++)
        {
            x=x+2;
            printf(" %.2d",x);
        }
        
        printf("\n");
    }
}