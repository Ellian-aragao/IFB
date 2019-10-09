#include<stdio.h>
#define TAMVETOR 32
int main()
{
    int vetor[TAMVETOR],i,x,y;
    for ( i = 0; i <= TAMVETOR; i++)
    {
        puts("digite os numeros do vetor");
        scanf("%d",&x);
        vetor[i]=x;
    }
    for ( x=0, y=0, i = 0; i <= TAMVETOR; i++)
    {
        if (vetor[i] != 0)
        {
            vetor[i]=1;
            x++;
        }
        else
        {
            y++;
        }
        
    }
    printf("vetor = ");
    for ( i = 0; i <= TAMVETOR; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n\tquantidade de 0 = %d\n\tquantidade de 1 = %d\n",y,x);
}