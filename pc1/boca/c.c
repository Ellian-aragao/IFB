#include <stdio.h>
int main()
{
    double pi = 0;
    for (long int i = 0; i < 1e6; i++) pi += (double)2 / ((4 * i + 1) * (4 * i + 3));
    printf("%lf\n", 4 * pi);
    return 0; // if possible
}