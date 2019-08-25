#include <stdio.h>
int main(void)
{
    while (1)
    {
        printf("1 - adicao\n2 - subtracao\n3 - multiplicacao\n4 - divisao\n5 - potenciacao\n6 - sair\n\n");

        int x;
        scanf("%d", &x);
        if (x == '\n') getchar();

        if (x == 6) break;
        
        switch (x)
        {
            float num1,num2;
            case 1:
                printf("soma: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f + %.2f = %.2f\n\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("subtracao: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f - %.2f = %.2f\n\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("multiplicacao: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f * %.2f = %.2f\n\n", num1, num2, num1 * num2);
                break;
            case 4:
                printf(" divisao: ");
                scanf("%f %f", &num1, &num2);
                printf("%.2f / %.2f = %.2f\n\n", num1, num2, num1 / num2);
                break;
            case 5:
                printf("potencia: ");
                scanf("%f %f", &num1, &num2);
                float num3 = 1;
                for (int i = 0; i < num2; i++) num3 *= num1;
                printf("%.2f ^ %.2f = %.2f\n\n", num1, num2, num3);
                break;
            default:
                puts("opcao invalida");
        }
    }
    return 0;
}
