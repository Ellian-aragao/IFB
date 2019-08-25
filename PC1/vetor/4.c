#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int vetora[num];
    int vetorb[num];

    for (int i = 0; i <= num; i++)
    {
        vetora[i] = i * 2;
        vetorb[i] = i * 3;
    }

    float produto = 0;
    for (int i = 0; i < num; i++)   produto += vetora[i] * vetorb[i];

    printf("o produto escalar = '%0.f'\n", produto);
    return 0;
}