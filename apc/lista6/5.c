#include<stdio.h>
#define TAMVETOR 9
/* quando estava fazendo o código, ele dava problema quando TAMVETOR=10, queria que me explicasse se possível */
int main()
{
    int vetor[TAMVETOR],i,j,x;
    for ( i = 0; i <= TAMVETOR; i++)
    {
        puts("digite os numeros do vetor");
        scanf("%d",&x);
        vetor[i]=x;
    }
    for ( i = 0; i <= TAMVETOR; i++ )
    {
        for ( j = TAMVETOR; j > 0; j-- )
        {
            if (vetor[j] > vetor[j-1])
            {
                x=vetor[j];
                vetor[j]=vetor[j-1];
                vetor[j-1]=x;
            }
        }
    }
    for ( i = 0; i <= TAMVETOR; i++)
    {
        printf("%d,",vetor[i]);
    }
    printf("\n");
}