#include <stdio.h>

static inline void swapInt(int *i1, int *i2)
{
  int tmp = *i1;
  *i1 = *i2;
  *i2 = tmp;
}

void sort(int *vetor, int tam, int (*comparator)(int *, int *))
{
  for (int i = 0; i < tam; i++)
    for (int j = i + 1; j < tam; j++)
      if (comparator(&vetor[i], &vetor[j]))
        swapInt(&vetor[i], &vetor[j]);
}

int comparatorCrescente(int *i1, int *i2)
{
  if (*i1 > *i2)
    return 1;
  return 0;
}

int comparatorDecrescente(int *i1, int *i2)
{
  if (*i1 < *i2)
    return 1;
  return 0;
}

void printVetor(int *vetor, int tam)
{
  for (int i = 0; i < tam; i++)
    printf("%d, ", vetor[i]);
  putchar('\n');
}

int main()
{
  int vetor[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
  printVetor(vetor, sizeof(vetor) / sizeof(int));
  sort(vetor, sizeof(vetor) / sizeof(int), comparatorDecrescente);
  printVetor(vetor, sizeof(vetor) / sizeof(int));
  return 0;
}
