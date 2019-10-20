#include<stdio.h>
#define TAMVETOR 9
int main()
{
    int vetor[TAMVETOR], x, i,maior=0,menor=999999999,imaior,imenor;
    for ( i = 0; i <= TAMVETOR ; i++)
    {
        puts("digite um numero inteiro");
        scanf("%d",&x);
        vetor[i]=x;
    }
    for ( i = 0; i <= TAMVETOR; i++)
    {
        if (vetor[i]>maior)
        {
            maior=vetor[i];
            imaior=i;
        }
        if (vetor[i]<menor)
        {
            menor=vetor[i];
            imenor=i;
        }
    }
    printf("maior = %d\t indice %d\nmenor = %d\t indice %d\n",maior,imaior,menor,imenor);
}