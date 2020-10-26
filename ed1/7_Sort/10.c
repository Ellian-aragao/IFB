#include <stdio.h>

static inline void printV(int *v, const int *tam)
{
  for (int i = 0; i < *tam; i++)
    printf("%d, ", v[i]);
  putchar('\n');
}

static inline void quicksortRecursive(int *vector, int init, int final)
{
  int i, j, pivo, tmp;
  i = init;
  j = final - 1;
  pivo = vector[(init + final) / 2];
  while (i <= j)
  {
    while (vector[i] < pivo && i < final)
      i++;
    while (vector[j] > pivo && j > init)
      j--;
    if (i <= j)
    {
      tmp = vector[i];
      vector[i] = vector[j];
      vector[j] = tmp;
      i++;
      j--;
    }
  }
  if (j > init)
    quicksortRecursive(vector, init, j + 1);
  if (i < final)
    quicksortRecursive(vector, i, final);
}
void quickSort(int *vector, int tamVector)
{
  quicksortRecursive(vector, 0, tamVector);
}

int main()
{
  int vector[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
  const int tam = sizeof(vector) / sizeof(vector[0]);
  printV(vector, &tam);
  quickSort(vector, tam);
  printV(vector, &tam);
  return 0;
}
