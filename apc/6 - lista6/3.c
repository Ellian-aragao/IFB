#include<stdio.h>
#define TAMVETOR 5
int pularlinha()
{
    printf("\n");
}
int main()
{
    int vetor0[TAMVETOR],vetor1[TAMVETOR],x,i;
    for ( i = 0; i <= TAMVETOR; i++)
    {
        printf("digite um elemento vetor de tamanho 5\n");
        scanf("%d",&vetor0[i]);
    }
    pularlinha();
    for ( i = 0; i <= TAMVETOR; i++)
    {
        printf("digite um elemento vetor de tamanho 5\n");
        scanf("%d",&vetor1[i]);
    }
    printf("primeiro vetor\n");
    for ( i = 0; i <= TAMVETOR; i++)
    {
        printf("%d,",vetor0[i]);
    }
    pularlinha();
    printf("segundo vetor\n");
    for ( i = 0; i <= TAMVETOR; i++)
    {
        printf("%d,",vetor1[i]);
    }
    pularlinha(2);
    for ( i = 0; i <= TAMVETOR; i++)
    {
        x=vetor0[i];
        vetor0[i]=vetor1[i];
        vetor1[i]=x;
    }
    printf("troca de elementos\n\n");
    printf("primeiro vetor\n");
    for ( i = 0; i <= TAMVETOR; i++)
    {
        printf("%d,",vetor0[i]);
    }
    pularlinha();
    printf("segundo vetor\n");
    for ( i = 0; i <= TAMVETOR; i++)
    {
        printf("%d,",vetor1[i]);
    }
    pularlinha();
}