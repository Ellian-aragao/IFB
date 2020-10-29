#include "sort.h"
#include <stdio.h>

#ifdef STATISTICS
u_long comparations = 0;
u_long swaps = 0;
#endif

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
  {
    perror("Erro na alocação do ptr temporário");
    exit(EXIT_FAILURE);
  }
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
  u_long boolean = 1;
#ifdef STATISTICS
  comparations = 0;
  swaps = 0;
#endif
  void *tmp = createTmpPointer(&SizeValuesVector);
  while (boolean != 0)
  {
    u_long i;
    for (boolean = 0, i = 0; i < tamVector - 1; i++)
    {
#ifdef STATISTICS
      comparations++;
#endif
      if (comparator(getAddrres(vector, i + 1, SizeValuesVector), getAddrres(vector, i, SizeValuesVector)))
      {
#ifdef STATISTICS
        swaps++;
#endif
        swap(getAddrres(vector, i, SizeValuesVector), getAddrres(vector, i + 1, SizeValuesVector), tmp, &SizeValuesVector);
        boolean = i;
      }
    }
#ifdef DEBUG
    printVector(vector, tamVector);
#endif
    tamVector--;
  }
  free(tmp);
#ifdef STATISTICS
  printf("\nBubbleSort\n * comps: %ld\n * swaps: %ld\n", comparations, swaps);
#endif
}

void insertionSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
#ifdef STATISTICS
  comparations = 0;
  swaps = 0;
#endif
  void *tmp = createTmpPointer(&SizeValuesVector);
  for (long j, i = 1; i < tamVector; i++)
  {
#ifdef DEBUG
    printVector(vector, i + 1);
#endif
#ifdef STATISTICS
    comparations++;
    swaps++;
#endif
    memcpy(tmp, getAddrres(vector, i, SizeValuesVector), SizeValuesVector);
    for (j = i - 1; j >= 0 && comparator(tmp, getAddrres(vector, j, SizeValuesVector)); j--)
#ifdef STATISTICS
    {
      swaps++;
#endif
      memcpy(getAddrres(vector, j + 1, SizeValuesVector), getAddrres(vector, j, SizeValuesVector), SizeValuesVector);
#ifdef STATISTICS
    }
    swaps++;
#endif
    memcpy(getAddrres(vector, j + 1, SizeValuesVector), tmp, SizeValuesVector);
  }
  free(tmp);
#ifdef STATISTICS
  printf("\nInsertionSort\n * comps: %ld\n * swaps: %ld\n", comparations, swaps);
#endif
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
    while (comparator(getAddrres(vector, i, *SizeValuesVector), pivo) && i < *final)
    {
#ifdef STATISTICS
      comparations++;
#endif
      i++;
    }
    while (comparator(pivo, getAddrres(vector, j, *SizeValuesVector)) && j > *init)
    {
#ifdef STATISTICS
      comparations++;
#endif
      j--;
    }
#ifdef STATISTICS
    comparations += 2;
#endif
    if (i <= j)
    {
#ifdef STATISTICS
      swaps++;
#endif
      swap(getAddrres(vector, i, *SizeValuesVector), getAddrres(vector, j, *SizeValuesVector), tmp, SizeValuesVector);
      i++;
      j--;
    }
  }
#ifdef DEBUG
  printVector(vector, *final);
#endif
  if (j++ > *init)
    quicksortRecursive(vector, init, &j, SizeValuesVector, comparator, tmp, pivo);
  if (i < *final)
    quicksortRecursive(vector, &i, final, SizeValuesVector, comparator, tmp, pivo);
}

void quickSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
#ifdef STATISTICS
  comparations = 0;
  swaps = 0;
#endif

  void *tmp = createTmpPointer(&SizeValuesVector);
  void *pivo = createTmpPointer(&SizeValuesVector);
  u_long init = 0;
  quicksortRecursive(vector, &init, &tamVector, &SizeValuesVector, comparator, tmp, pivo);
  free(tmp);
  free(pivo);

#ifdef STATISTICS
  printf("\nQuickSort\n * comps: %ld\n * swaps: %ld\n", comparations, swaps);
#endif
}

void selectionSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
#ifdef STATISTICS
  comparations = 0;
  swaps = 0;
#endif
  void *tmp = createTmpPointer(&SizeValuesVector);
  for (u_long min, i = 0; i < tamVector - 1; i++)
  {
    min = i;
    for (u_long j = i + 1; j < tamVector; j++)
    {
#ifdef STATISTICS
      comparations++;
#endif
      if (comparator(getAddrres(vector, j, SizeValuesVector), getAddrres(vector, min, SizeValuesVector)))
        min = j;
    }
#ifdef DEBUG
    printVector(vector, min + 1);
#endif
    if (memcmp(getAddrres(vector, i, SizeValuesVector), getAddrres(vector, min, SizeValuesVector), SizeValuesVector))
    {
#ifdef STATISTICS
      swaps++;
#endif
      swap(getAddrres(vector, i, SizeValuesVector), getAddrres(vector, min, SizeValuesVector), tmp, &SizeValuesVector);
    }
  }
  free(tmp);
#ifdef STATISTICS
  printf("\nSelectionSort\n * comps: %ld\n * swaps: %ld\n", comparations, swaps);
#endif
}

void shellSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
#ifdef STATISTICS
  comparations = 0;
  swaps = 0;
#endif
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
      {
#ifdef STATISTICS
        comparations++;
#endif
        memcpy(getAddrres(vector, j, SizeValuesVector), getAddrres(vector, j - h, SizeValuesVector), SizeValuesVector);
      }
#ifdef STATISTICS
      comparations++;
      swaps++;
#endif

      memcpy(getAddrres(vector, j, SizeValuesVector), tmp, SizeValuesVector);
    }
    h /= NUMERO_MAGICO;
#ifdef DEBUG
    printVector(vector, tamVector);
#endif
  }
  free(tmp);
#ifdef STATISTICS
  printf("\nShellSort\n * comps: %ld\n * swaps: %ld\n", comparations, swaps);
#endif
}

static inline void mergeVectors(void *vector, const u_long *init, const u_long *mid, const u_long *end, void *tmpV, const size_t *SizeValuesVector, int (*comparator)(void *, void *))
{
  u_long left = *init;
  u_long right = *mid;
  for (u_long i = *init; i < *end; i++)
  {
#ifdef STATISTICS
    comparations++;
#endif
    if ((left < *mid) && ((right >= *end) || comparator(getAddrres(vector, left, *SizeValuesVector), getAddrres(vector, right, *SizeValuesVector))))
    {
#ifdef STATISTICS
      swaps++;
#endif
      memcpy(getAddrres(tmpV, i, *SizeValuesVector), getAddrres(vector, left, *SizeValuesVector), *SizeValuesVector);
      left++;
    }
    else
    {
#ifdef STATISTICS
      swaps++;
#endif
      memcpy(getAddrres(tmpV, i, *SizeValuesVector), getAddrres(vector, right, *SizeValuesVector), *SizeValuesVector);
      right++;
    }
  }
  for (u_long i = *init; i < *end; ++i)
  {
#ifdef STATISTICS
    swaps++;
#endif
    memcpy(getAddrres(vector, i, *SizeValuesVector), getAddrres(tmpV, i, *SizeValuesVector), *SizeValuesVector);
  }
#ifdef DEBUG
  printVector(vector, *end);
#endif
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

void mergeSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
#ifdef STATISTICS
  comparations = 0;
  swaps = 0;
#endif

  size_t var = SizeValuesVector * tamVector;
  void *tmp = createTmpPointer(&var);
  var = 0;
  mergeSortRecursive(vector, &var, &tamVector, tmp, &SizeValuesVector, comparator);
#ifdef STATISTICS
  printf("\nMergeSort\n * comps: %ld\n * swaps: %ld\n", comparations, swaps);
#endif
}

void heapSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *))
{
  #ifdef STATISTICS
    comparations = 0;
    swaps = 0;
  #endif
  
  void *tmp = createTmpPointer(&SizeValuesVector);
  u_long i = tamVector / 2;
  while (1)
  {
  
    if (i > 0)
    {
      i--;
      memcpy(tmp, getAddrres(vector, i, SizeValuesVector), SizeValuesVector);
      #ifdef STATISTICS
            swaps++;
      #endif
    }
    else
    {
      tamVector--;
      
      if (tamVector <= 0)
        goto END_HEAP_FUNCTION;

      #ifdef STATISTICS
            swaps += 2;
      #endif
      memcpy(tmp, getAddrres(vector, tamVector, SizeValuesVector), SizeValuesVector);
      memcpy(getAddrres(vector, tamVector, SizeValuesVector), getAddrres(vector, 0, SizeValuesVector), SizeValuesVector);
    }
    #ifdef DEBUG
        printVector(vector, tamVector);
    #endif

    u_long root = i;
    u_long node = i * 2 + 1;
    while (node < tamVector)
    {
      #ifdef STATISTICS
            comparations += 2;
      #endif
      if ((node + 1 < tamVector) && comparator(getAddrres(vector, node, SizeValuesVector), getAddrres(vector, node + 1, SizeValuesVector)))
        node++;
      if (comparator(tmp, getAddrres(vector, node, SizeValuesVector)))
      {
        #ifdef STATISTICS
                swaps++;
        #endif
        memcpy(getAddrres(vector, root, SizeValuesVector), getAddrres(vector, node, SizeValuesVector), SizeValuesVector);
        root = node;
        node = root * 2 + 1;
      }
      else
        break;
    }
    #ifdef STATISTICS
        swaps++;
    #endif
    memcpy(getAddrres(vector, root, SizeValuesVector), tmp, SizeValuesVector);
  }
END_HEAP_FUNCTION:
  #ifdef STATISTICS
    printf("\nHeapSort\n * comps: %ld\n * swaps: %ld\n\n", comparations, swaps);
  #endif
  return;
}

void countingSort(int *vector, const u_long tamVector, const u_long maxItemVector)
{
  int *bucketV = calloc(maxItemVector, sizeof(int));
  if (!bucketV)
    exit(EXIT_FAILURE);

  for (int i = 0; i < tamVector; i++)
    bucketV[vector[i]]++;

  for (int i = 0, j = 0; j < maxItemVector; j++)
    while (bucketV[j]--)
      vector[i++] = j;

  free(bucketV);
}

#define tam_bucket 10
#define num_bucket 10
#define max 10
typedef struct
{
  int qtd;
  int valores[tam_bucket];
} Bucket;

void bucketSort(int *vector, const u_long tamVector)
{

  int maior, menor;
  for (u_long i = 0, menor = maior = vector[i]; i < tamVector; i++)
  {
    if (vector[i] > maior)
      maior = vector[i];
    if (vector[i] < menor)
      menor = vector[i];
  }

  size_t nBuckets = ((maior - menor) / tam_bucket + 1);
  Bucket *bucket = calloc(nBuckets, sizeof(Bucket));
  if (!bucket)
    exit(EXIT_FAILURE);

  for (u_long i = 0; i < tamVector; i++)
  {
    int pos = (vector[i] - menor) / tam_bucket;
    bucket[pos].valores[bucket[pos].qtd] = vector[i];
    bucket[pos].qtd++;
  }

  for (u_long i = 0, pos = 0; i < num_bucket; i++)
  {
    quickSort(bucket[i].valores, bucket[i].qtd, sizeof(int), compareInteger);
    for (u_long j = 0; j < bucket[i].qtd; j++, pos++)
      vector[pos] = bucket[i].valores[j];
  }
  free(bucket);
}

#ifndef LIB
int main()
{
  int vector[] = {19, 1234, 58, 34, 17, 68, 345, 63, 234, 67, 38};
  const int tam = sizeof(vector) / sizeof(vector[0]);

  printVector(vector, tam);

  heapSort(vector, tam, sizeof(vector[0]), compareInteger);

  printVector(vector, tam);
  return 0;
}
#endif