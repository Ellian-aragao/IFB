#include<stdio.h>
int main()
{
    int x,i,idade,maior=0,menor=99999999;
    do
    {
        printf("quantas de idades que ira digitar\n");
        scanf("%d",&x);
        if (x<0.1)
        {
            printf("digite um valor maior que '0'\n");
        }
        else
        {
            for (i=1;x>=i;i++)
            {
                printf("digite a idade\n");
                scanf("%d",&idade);
                if (idade>maior)
                {
                    maior=idade;
                }
                if (idade<menor)
                {
                    menor=idade;
                }
            }
            printf("maior idade = '%d'\nmenor idade = '%d'\n",maior,menor);
        }
    }
    while (x<0.1);
}