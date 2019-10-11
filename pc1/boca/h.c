#include <stdio.h>
int main()
{
    int num;
    scanf("%d",&num);

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (j + 1 > num) printf(" (%d,%d)", i, j);
            else printf("(%d,%d), ", i, j);
        }
        putchar('\n');
    }

    return 0;
}