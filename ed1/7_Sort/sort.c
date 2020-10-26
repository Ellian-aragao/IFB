#include "sort.h"

#define getAddrres(vector, position, size) ((vector) + (position) * (size))

static inline void *createTmpPointer(size_t *size)
{
  void *tmp = malloc(*size);
  if (!tmp)
    exit(EXIT_FAILURE);
  return tmp;
}

static inline void swap(void *item1, void *item2, void *tmp, size_t *size)
{
  memcpy(tmp, item1, *size);
  memcpy(item1, item2, *size);
  memcpy(item2, tmp, *size);
}

void bubbleSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  u_long i, next = 1;
  void *tmp = createTmpPointer(&SizeValuesVector);
  while (next != 0)
  {
    for (next = 0, i = 0; i < tamVector - 1; i++)
      if (comparator(getAddrres(vector, i, SizeValuesVector), getAddrres(vector, i + 1, SizeValuesVector)))
      {
        swap(getAddrres(vector, i, SizeValuesVector), getAddrres(vector, i + 1, SizeValuesVector), tmp, &SizeValuesVector);
        next = i;
      }
    tamVector--;
  }
  free(tmp);
}

void insertionSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  void *tmp = createTmpPointer(&SizeValuesVector);
  for (int j, i = 1; i < tamVector; i++)
  {
    memcpy(tmp, getAddrres(vector, i, SizeValuesVector), SizeValuesVector);
    for (j = i - 1; j >= 0 && comparator(getAddrres(vector, j, SizeValuesVector), tmp); j--)
      memcpy(getAddrres(vector, j + 1, SizeValuesVector), getAddrres(vector, j, SizeValuesVector), SizeValuesVector);
    memcpy(getAddrres(vector, j + 1, SizeValuesVector), tmp, SizeValuesVector);
  }
  free(tmp);
}

void insertionSortItem(void *vector, u_long tamVector, void *item, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  memcpy(getAddrres(vector, tamVector - 1, SizeValuesVector), item, SizeValuesVector);
  insertionSort(vector, tamVector, SizeValuesVector, comparator);
}

static inline void quicksortRecursive(void *vector, u_long init, u_long final, size_t *SizeValuesVector, int (*comparator)(void *, void *))
{
  void *tmp = createTmpPointer(SizeValuesVector);
  void *pivo = createTmpPointer(SizeValuesVector);
  memcpy(pivo, getAddrres(vector, (init + final) / 2, *SizeValuesVector), *SizeValuesVector);
  u_long i = init;
  u_long j = final - 1;
  while (i <= j)
  {
    while (comparator(pivo, getAddrres(vector, i, *SizeValuesVector)) && i < final)
      i++;
    while (comparator(getAddrres(vector, j, *SizeValuesVector), pivo) && j > init)
      j--;
    if (i <= j)
    {
      swap(getAddrres(vector, i, *SizeValuesVector), getAddrres(vector, j, *SizeValuesVector), tmp, SizeValuesVector);
      i++;
      j--;
    }
  }
  if (j > init)
    quicksortRecursive(vector, init, j + 1, SizeValuesVector, comparator);
  if (i < final)
    quicksortRecursive(vector, i, final, SizeValuesVector, comparator);
}

void quickSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  quicksortRecursive(vector, 0, tamVector - 1, &SizeValuesVector, comparator);
}

void selectionSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  void *tmp = createTmpPointer(&SizeValuesVector);
  for (u_long min, i = 0; i < tamVector - 1; i++)
  {
    min = i;
    for (u_long j = i + 1; j < tamVector; j++)
      if (comparator(getAddrres(vector, min, SizeValuesVector), getAddrres(vector, j, SizeValuesVector)))
        min = j;

    if (memcmp(getAddrres(vector, i, SizeValuesVector), getAddrres(vector, min, SizeValuesVector), SizeValuesVector))
      swap(getAddrres(vector, i, SizeValuesVector), getAddrres(vector, min, SizeValuesVector), tmp, &SizeValuesVector);
  }
  free(tmp);
}
#ifndef LIB
  #include <stdio.h>
  #define voidToType(ptr) (*(int *)ptr)
  int compare(void *i1, void *i2)
  {
    return (voidToType(i1) > voidToType(i2)) ? 1 : 0;
  }

  int main(int argc, char const *argv[])
  {
    int vector[12] = {19, 1234, 58, 34, 17, 68, 345, 63, 234, 67, 38};
    const int tam = sizeof(vector) / sizeof(vector[0]);
    const char strPrint[] = "%d, ";

    for (size_t i = 0; i < tam; i++)
      printf(strPrint, vector[i]);
    putchar('\n');

    // insertionSort(vector, 11, sizeof(vector[0]), compare);
    int item = 65;
    insertionSortItem(vector, tam, &item, sizeof(vector[0]), compare);

    for (size_t i = 0; i < tam; i++)
      printf(strPrint, vector[i]);
    putchar('\n');
    return 0;
  }
#endif