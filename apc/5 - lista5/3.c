#include<stdio.h>
int main()
{
    int n,i,j,indice=0,cont=1;
    scanf("%d",&n);
    scanf("%d",&i);
    scanf("%d",&j);
    do
    {
        if (indice % i == 0 && indice % j == 0)
        {
            printf("%d,",indice);
            cont++;
        }
        else
        {
            if (indice % i == 0)
            {
                printf("%d,",indice);
                cont++;
            }
            else
            {
                if (indice % j == 0)
                {
                    printf("%d,",indice);
                    cont++;
                }
            }
        }
        indice++;
    } while (n>=cont);
    printf("...\n");
}