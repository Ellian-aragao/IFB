#include<stdio.h>
int main()
{
    int i;
    float n,x,y=0,z=0,t;
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
    if ((y/z)<5)
    {
        printf("\t\t'aluno reprovado!'\n");
    }
    else
    {
        if ((y/z)<6)
        {
            printf("\t\t'aluno em recuperação!'\n");
        }
        else
        {
            if ((y/z)<8)
            {
                printf("\t\t'aluno aprovado!\n");
            }
            else
            {
                if ((y/z)<10)
                {
                    printf("\t\t'aluno aprovado!  Parabens!\n");
                }
                else
                {
                    printf("\t\t'aluno aprovado!  Sensacional!\n"); 
                }
            }
        }
    }
}