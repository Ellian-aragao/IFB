#include<math.h>
#include<stdio.h>
#define gravidade 10
int main()
{
    int i;
    float velocidade,tempo,alfa,alcanceH,alcanceV,tempoV,alcanceD;
    printf("digite a velocidade em metros por segundo\n");
    scanf("%f",&velocidade);
    printf("digite o angulo em graus\n");
    scanf("%f",&alfa);
    tempo=(2*velocidade*sin(alfa))/gravidade;
    tempoV=tempo/2;
    printf("\ntempo total do lancamento = %.3f segundos\n",tempo);
    printf("tempo de subida do lancamento = %.3f segundos\n\n",tempoV);
    for (i=1;i<=tempo;i++)
    {
        if (i<=tempoV)
        {
            alcanceV=velocidade*sin(alfa)*i;
            alcanceH=velocidade*cos(alfa)*i;
            printf("alcance horizontal em '%d' segundos foi de '%.2f' metros\n",i,alcanceH);
            printf("alcance vertical em '%d' segundos foi de '%.2f' metros\n\n",i,alcanceV);
        }
        else
        {
            alcanceD=alcanceV-(gravidade*pow(i-tempoV,2))/2;
            alcanceH=velocidade*cos(alfa)*i;
            printf("alcance horizontal em '%d' segundos foi de '%.2f' metros\n",i,alcanceH);
            printf("alcance vertical em '%d' segundos foi de '%.2f' metros\n\n",i,alcanceD);
        }
    }
    alcanceH=(pow(velocidade,2)*sin(2*alfa))/gravidade;
    alcanceV=(pow(velocidade*sin(alfa),2))/(2*gravidade);
    printf("alcance horizontal max '%.2f' metros\nalcance vertical max '%.2f' metros\n",alcanceH,alcanceV);
}