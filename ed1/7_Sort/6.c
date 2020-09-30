#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void swapInt(int *i1, int *i2)
{
  int tmp = *i1;
  *i1 = *i2;
  *i2 = tmp;
}

// problematica nos limites superiores
static inline int getWhenNotSorted(int *vetor, int *tam, int *num)
{
  if (*num > vetor[*tam])
    return *tam;

  for (int i = 0; i < *tam; i++)
    if (vetor[i] > *num)
      return i;

  return -1;
}

static inline void isNullExit(void *ptr, const char *message)
{
  if (!ptr)
  {
    perror(message);
    exit(EXIT_FAILURE);
  }
}

void *insertSorted(int *vetor, int tam, int numToAdd)
{
  int *vetorInserted = malloc((tam + 1) * sizeof(int));
  isNullExit(vetorInserted, "erro na criação do vetor");
  int index = getWhenNotSorted(vetor, &tam, &numToAdd);
  if (index > -1)
  {
    memcpy(vetorInserted, vetor, index * sizeof(int));
    vetorInserted[index] = numToAdd;
    memcpy(&vetorInserted[index + 1], &vetor[index], (tam - index) * sizeof(int));
  }
  else
  {
    free(vetorInserted);
    vetorInserted = NULL;
  }
  return vetorInserted;
}

void printVetor(int *vetor, int tam)
{
  for (int i = 0; i < tam; i++)
    printf("%d, ", vetor[i]);
  putchar('\n');
}

int main()
{
  int vetor[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int tamVetor = sizeof(vetor) / sizeof(int);
  printVetor(vetor, tamVetor);
  int *insertedVector = insertSorted(vetor, tamVetor, 10);
  printVetor(insertedVector, 1 + tamVetor);
  free(insertedVector);
  return 0;
}
