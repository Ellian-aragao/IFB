#include<stdio.h>
#include<math.h>
#define TAMVETOR 9
int main()
{
    float vetor[TAMVETOR],x,media=0,variancia=0,desvioPadrao;
    int i;
    for ( i = 0; i <= TAMVETOR; i++)
    {
        puts("digite o numero");
        scanf("%f",&x);
        vetor[i]=x;
    }
    for ( i = 0; i <= TAMVETOR; i++)
    {
        media=media+vetor[i];
        variancia=variancia+pow(vetor[i],2);
    }
    media=media/TAMVETOR;
    variancia=variancia/TAMVETOR;
    desvioPadrao=sqrt((variancia-pow(media,2)));
    printf("media = %f\ndesvio padrao = %f\n",media,desvioPadrao);
}