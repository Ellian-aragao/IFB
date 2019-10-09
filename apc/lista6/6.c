#include<stdio.h>
#define TAMVETOR 20
int main()
{
    int vetor[TAMVETOR],i,j,x,y;
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
            if (vetor[j] < vetor[j-1])
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
    puts("\ndigite um número a ser procurado no vetor");
    scanf("%d",&x);
    for ( i = 0; i <= TAMVETOR; i++)
    {
        if ( vetor[i] == x)
        {
            printf("o numero esta no vetor\n");
            break;
        }
        else
        {
            if (vetor[TAMVETOR] == i)
            {
                puts("o numero nao esta no vetor");
            }
            
        }
        
    }    

    /*
    não consegui implementar o algoritmo que era pra fazer a pesquisa

    for ( i = 0, j = TAMVETOR; x >= vetor[i]; y=i, i = j/2, j = j*3/4)
    for (; x <= i && y<=x ; i++)
    {
        if ( vetor[i] == x)
        {
            printf("o número está no vetor na posição '%d'",vetor[i]);
            break;
        }
    }
    */
}