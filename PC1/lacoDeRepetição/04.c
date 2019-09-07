#include<stdio.h>
#include<stdlib.h>
void linha(int x)
{
    for(int i = 1;i <= x; i++)
    {
        putchar('*');
    }

}
int main (int argc,char** argv)
{
    int x = atoi(argv[1]);

    for(int i=1; i < x; i++)
    {
        linha(i);
        putchar('\n');
    }
     for(int i=x; i > 0 ; i--)
    {
        linha(i);
        putchar('\n');
    }

    return 0;
}