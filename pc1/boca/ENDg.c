#include <stdio.h>
//resolver com crivo de aristofanes
int main()
{
    int num;
    scanf("%d",&num);
    int primo = 0;

    if (num < 2)
    {
        puts("Composto!");
        primo = -1;
    }
    else if (num == 2) puts("Primo!");
    else if ((num % 2) == 0) puts("Composto!");
    else
    {
        int i;

        for (i = 3; i <= (num / 2) + 1; i += 2)
        {
            if (num % i == 0)
            {
                puts("Composto!");
                break;
            }
        }

        if (i >= num / 2)
        {
            puts("Primo!");
            primo = 1;
        }
    }

    return 0;
}
