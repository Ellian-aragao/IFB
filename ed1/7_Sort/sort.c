#include "sort.h"
#include <stdio.h>

#define getAddrres(vector, position, size) ((vector) + ((position) * (size)))

static inline void printVector(const int *vector, const int tamVector)
{
  putchar('[');
  for (int i = 0; i < tamVector; i++)
    printf(i == tamVector - 1 ? "%d" : "%d, ", vector[i]);
  puts("]");
}

static int compareInteger(void *i1, void *i2)
{
  return (*(int *)i1 > *(int *)i2) ? 1 : 0;
}

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
  for (long j, i = 1; i < tamVector; i++)
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

static void quicksortRecursive(void *vector, u_long *init, u_long *final, size_t *SizeValuesVector, int (*comparator)(void *, void *), void *tmp, void *pivo)
{
  memcpy(pivo, getAddrres(vector, (*init + *final) / 2, *SizeValuesVector), *SizeValuesVector);
  u_long i = *init;
  u_long j = *final - 1;
  while (i <= j)
  {
    while (comparator(pivo, getAddrres(vector, i, *SizeValuesVector)) && i < *final)
      i++;
    while (comparator(getAddrres(vector, j, *SizeValuesVector), pivo) && j > *init)
      j--;
    if (i <= j)
    {
      swap(getAddrres(vector, i, *SizeValuesVector), getAddrres(vector, j, *SizeValuesVector), tmp, SizeValuesVector);
      i++;
      j--;
    }
  }
  if (j++ > *init)
    quicksortRecursive(vector, init, &j, SizeValuesVector, comparator, tmp, pivo);
  if (i < *final)
    quicksortRecursive(vector, &i, final, SizeValuesVector, comparator, tmp, pivo);
}

void quickSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  void *tmp = createTmpPointer(&SizeValuesVector);
  void *pivo = createTmpPointer(&SizeValuesVector);
  u_long init = 0;
  quicksortRecursive(vector, &init, &tamVector, &SizeValuesVector, comparator, tmp, pivo);
  free(tmp);
  free(pivo);
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

void shellSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  const u_long NUMERO_MAGICO = 3;
  void *tmp = createTmpPointer(&SizeValuesVector);

  u_long h = 1;
  while (h < tamVector)
    h = NUMERO_MAGICO * h + 1;

  while (h > 0)
  {
    for (u_long j, i = h; i < tamVector; i++)
    {
      memcpy(tmp, getAddrres(vector, i, SizeValuesVector), SizeValuesVector);
      for (j = i; j > h - 1 && comparator(tmp, getAddrres(vector, j - h, SizeValuesVector)); j -= h)
        memcpy(getAddrres(vector, j, SizeValuesVector), getAddrres(vector, j - h, SizeValuesVector), SizeValuesVector);
      memcpy(getAddrres(vector, j, SizeValuesVector), tmp, SizeValuesVector);
    }
    h /= NUMERO_MAGICO;
  }
  free(tmp);
}

static inline void mergeVectors(void *vector, const u_long *init, const u_long *mid, const u_long *end, void *tmpV, const size_t *SizeValuesVector, int (*comparator)(void *, void *))
{
  u_long left = *init;
  u_long right = *mid;
  for (u_long i = *init; i < *end; i++)
  {
    if ((left < *mid) && ((right >= *end) || comparator(getAddrres(vector, left, *SizeValuesVector), getAddrres(vector, right, *SizeValuesVector))))
    {
      memcpy(getAddrres(tmpV, i, *SizeValuesVector), getAddrres(vector, left, *SizeValuesVector), *SizeValuesVector);
      left++;
    }
    else
    {
      memcpy(getAddrres(tmpV, i, *SizeValuesVector), getAddrres(vector, right, *SizeValuesVector), *SizeValuesVector);
      right++;
    }
  }
  for (u_long i = *init; i < *end; ++i)
    memcpy(getAddrres(vector, i, *SizeValuesVector), getAddrres(tmpV, i, *SizeValuesVector), *SizeValuesVector);
}

static void mergeSortRecursive(void *vector, const u_long *init, const u_long *end, void *tmpV, const size_t *SizeValuesVector, int (*comparator)(void *, void *))
{
  if ((*end - *init) >= 2)
  {
    const u_long mid = ((*init + *end) / 2);
    mergeSortRecursive(vector, init, &mid, tmpV, SizeValuesVector, comparator);
    mergeSortRecursive(vector, &mid, end, tmpV, SizeValuesVector, comparator);
    mergeVectors(vector, init, &mid, end, tmpV, SizeValuesVector, comparator);
  }
}

void mergeSort(void *vector, const u_long tamVector, const size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  size_t var = SizeValuesVector * tamVector;
  void *tmp = createTmpPointer(&var);
  var = 0;
  mergeSortRecursive(vector, &var, &tamVector, tmp, &SizeValuesVector, comparator);
}

void heapSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  void *tmp = createTmpPointer(&SizeValuesVector);
  u_long i = tamVector / 2;
  while (1)
  {
    if (i > 0)
    {
      i--;
      memcpy(tmp, getAddrres(vector, i, SizeValuesVector), SizeValuesVector);
    }
    else
    {
      tamVector--;
      if (tamVector <= 0)
        return;
      memcpy(tmp, getAddrres(vector, tamVector, SizeValuesVector), SizeValuesVector);
      memcpy(getAddrres(vector, tamVector, SizeValuesVector), getAddrres(vector, 0, SizeValuesVector), SizeValuesVector);
    }

    u_long root = i;
    u_long node = i * 2 + 1;
    while (node < tamVector)
    {
      if ((node + 1 < tamVector) && comparator(getAddrres(vector,node + 1,SizeValuesVector), getAddrres(vector, node, SizeValuesVector)))
        node++;
      if (comparator(getAddrres(vector, node, SizeValuesVector), tmp))
      {
        memcpy(getAddrres(vector, root, SizeValuesVector), getAddrres(vector, node, SizeValuesVector), SizeValuesVector);
        root = node;
        node = root * 2 + 1;
      }
      else
        break;
    }
    memcpy(getAddrres(vector, root, SizeValuesVector), tmp, SizeValuesVector);
  }
}

#ifndef LIB
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

  heapSort(vector, tam, sizeof(vector[0]), compare);

  for (size_t i = 0; i < tam; i++)
    printf(strPrint, vector[i]);
  putchar('\n');
  return 0;
}
#endif