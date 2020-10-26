#include <stdio.h>

static inline void printV(int *v, const int *tam)
{
  for (int i = 0; i < *tam; i++)
    printf("%d, ", v[i]);
  putchar('\n');
}

void insertionSort(int *vector, int tamVector)
{
  int contCopias = 0;
  for (int j, i = 1; i <= tamVector; i++)
  {
    printf("%02d => ", i);
    printV(vector, &tamVector);
    int tmp = vector[i];
    for (j = i - 1; j >= 0 && vector[j] > tmp; j--)
    {
      vector[j + 1] = vector[j];
      contCopias++;
    }
    vector[j + 1] = tmp;
  }
  printf("foram executadas %d cópias durante execução\n", contCopias);
}

int main()
{
  int vector[] = {26, 65, 45, 73, 10, 18, 78, 93, 70, 49, 23, 22};
  const int tam = sizeof(vector) / sizeof(vector[0]);
  insertionSort(vector, tam);
  return 0;
}
