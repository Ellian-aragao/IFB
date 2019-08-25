#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int primo = 0;

    if (num < 0)
    {
        printf("o numero '%d' não é primo\n", num);
        primo = -1;
    }
    else if ((num % 2) == 0) printf("o numero '%d' não é primo\n", num);
    else
    {
        int i;

        for (i = 3; i <= (num / 2) + 1; i += 2)
        {
            if (num % i == 0)
            {
                printf("o numero '%d' não é primo\n", num);
                break;
            }
        }

        if (i >= num / 2)
        {
            printf("o numero '%d' é primo\n", num);
            primo = 1;
        }
    }

    if (primo == 0)
    {
        printf("'%d' e composto por: ", num);

        for (int i = 2; i <= num; i++)
        {
            while (num % i == 0)
            {
                printf("%d * ", i);
                num /= i;
            }
        }
        printf("1\n");
    }

    return 0;
}
