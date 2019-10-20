#include<stdio.h>
int main()
{
    int x=0;
    float y=1000,z;
    do
    {
        printf("#####################################\n#   1 - saque                       #\n#   2 - deposito                    #\n#   3 - sair do programa            #\n#####################################\n");
        scanf("%d",&x);
        if (x!=3)
        {
            if (x == 1)
            {
                printf("digite um valor a ser sacado, menor que R$ %.2f\n",y);
                scanf("%f",&z);
                if ((y-z)<0)
                {
                    printf("\n\t\tdigite um valor valido para ser sacado\n\n");
                }
                else
                {
                    y=y-z;
                    printf("\t\t\to valor na conta e de '%.2f' reais\n\n",y);
                }
            }
            else
            {
                if (x == 2)
                {
                    printf("digite um valor a ser depositado\n");
                    scanf("%f",&z);
                    y=y+z;
                    printf("\t\t\to valor na conta e de '%.2f' reais\n\n",y);
                }
                else
                {
                    printf("digite um valor valido\n\n");
                }
            }
        }
        else
        {    
            break;
        }
    }while (x != 3);
    printf("\t\t\to valor na conta e de '%.2f' reais\n\n",y);
}