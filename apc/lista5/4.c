#include<stdio.h>
int main()
{
    int n,i,x=0;
    printf("digite quantos numeros triangulares deseja ver\t");
    scanf("%d",&n);
    for (i=1;n>=i;i++)
        {
            printf("número triangular '%d' é composto por '%d*%d*%d'\n",x*(x+1)*(x+2),x,x+1,x+2);
            x++;
        }
}
