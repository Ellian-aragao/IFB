#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int i;

    for (i = 0; num >= 100; i++) num -= 100;
    printf("%d notas de 100\n",i);

    for (i = 0; num >= 20; i++) num -= 20;
    printf("%d notas de 20\n",i);

    for (i = 0; num >= 10; i++) num -= 10;
    printf("%d notas de 10\n",i);
    
    for (i = 0; num >= 5; i++) num -= 5;
    printf("%d notas de 5\n",i);

    for (i = 0; num >= 2; i++) num -= 2;
    printf("%d notas de 2\n",i);

    for (i = 0; num >= 1; i++) num -= 1;
    printf("%d notas de 1\n",i);

    return 0;
}