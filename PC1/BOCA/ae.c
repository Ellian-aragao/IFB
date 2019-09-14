#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    if (n < 1 || n > 1e5) exit(1);

    int *vetor = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);

    for (int i = n; i > 0; i--) printf("%d ", vetor[i - 1]);

    putchar('\n');

    return 0;
}
