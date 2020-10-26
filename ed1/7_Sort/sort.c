#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
  int i, key, j;
  void *tmp = createTmpPointer(&SizeValuesVector);
  for (i = 1; i < tamVector; i++)
  {
    memcpy(tmp, getAddrres(vector, i, SizeValuesVector), SizeValuesVector);
    j = i - 1;
    while (j >= 0 && comparator(getAddrres(vector, j, SizeValuesVector), tmp))
    {
      memcpy(getAddrres(vector, j + 1, SizeValuesVector), getAddrres(vector, j, SizeValuesVector), SizeValuesVector);
      j--;
    }
    memcpy(getAddrres(vector, j + 1, SizeValuesVector), tmp, SizeValuesVector);
  }
  free(tmp);
}

#define voidToType(ptr) (*(int *)ptr)
int compare(void *i1, void *i2)
{
  return (voidToType(i1) > voidToType(i2)) ? 1 : 0;
}

int main(int argc, char const *argv[])
{
  int vector[] = {19, 1234, 58, 34, 17, 68, 345, 63, 234, 67, 38};
  const int tam = sizeof(vector) / sizeof(vector[0]);
  const char strPrint[] = "%d, ";

  for (size_t i = 0; i < tam; i++)
    printf(strPrint, vector[i]);
  putchar('\n');

  insertionSort(vector, tam, sizeof(vector[0]), compare);

  for (size_t i = 0; i < tam; i++)
    printf(strPrint, vector[i]);
  putchar('\n');
  return 0;
}
