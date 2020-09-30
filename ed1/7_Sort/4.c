#include <stdio.h>

static inline int isSorted(int *vetor, int *tam)
{
  for (int i = 0; i < *tam - 1; i++)
    if (vetor[i] > vetor[i + 1])
      return 0;
  return 1;
}

void printIfSorted(int *vetor, int tam)
{
  if (isSorted(vetor, &tam))
    for (int i = 0; i < tam; i++)
      printf("%d, ", vetor[i]);
  putchar('\n');
}

int main()
{
  int vetor[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printIfSorted(vetor, sizeof(vetor) / sizeof(int));
  return 0;
}
