/*********************************************************************
 * para compilar, utilize os flags:
 * - LIB: para não compilar a main implementada no sort.c
 * - DEBUG: exibir no console cada parte do algoritmo sendo exacutada
 * gcc sort.c 16.c -DLIB -DDEBUG
**********************************************************************/

#include "sort.h"
#include <stdio.h>

int compareInteger(void *i1, void *i2)
{
  return (*(int *)i1 > *(int *)i2) ? 1 : 0;
}

void printVector(const char *strPrint, const int *vector, const int tamVector)
{
  for (int i = 0; i < tamVector; i++)
    printf(strPrint, vector[i]);
  putchar('\n');
}

void printAlgSort(char *strPrint, void (*sortAlg)(void *, u_long, size_t, int (*)(void *, void *)), int (*comparadorVector)(void *, void *), u_long tamVector, size_t sizeItem, const int *vector)
{
  int vectorCopy[tamVector];
  memcpy(vectorCopy, vector, tamVector * sizeItem);
  puts(strPrint);
  // printVector("%d, ", vectorCopy, tamVector);
  sortAlg(vectorCopy, tamVector, sizeItem, comparadorVector);
  // printVector("%d, ", vectorCopy, tamVector);
}

void printAllAlgSort(int *vector, u_long tamVector, size_t sizeItem)
{
  printAlgSort("\n--------------------bubble----------------------", bubbleSort, compareInteger, tamVector, sizeof(vector[0]), vector);
  printAlgSort("\n------------------insertion---------------------", insertionSort, compareInteger, tamVector, sizeof(vector[0]), vector);
  printAlgSort("\n--------------------shell-----------------------", shellSort, compareInteger, tamVector, sizeof(vector[0]), vector);
  printAlgSort("\n------------------selection---------------------", selectionSort, compareInteger, tamVector, sizeof(vector[0]), vector);
  printAlgSort("\n--------------------merge-----------------------", mergeSort, compareInteger, tamVector, sizeof(vector[0]), vector);
  printAlgSort("\n--------------------quick-----------------------", quickSort, compareInteger, tamVector, sizeof(vector[0]), vector);
  printAlgSort("\n--------------------heap------------------------", heapSort, compareInteger, tamVector, sizeof(vector[0]), vector);
}

int main()
{
  int a[] = {2, 4, 6, 8, 10, 12};
  int b[] = {11, 9, 7, 5, 3, 1};
  int c[] = {5, 7, 2, 8, 1, 6};
  int d[] = {2, 4, 6, 8, 10, 12, 11, 9, 7, 5, 3, 1};
  int e[] = {2, 4, 6, 8, 10, 12, 1, 3, 5, 7, 9, 11};
  int f[] = {8, 9, 7, 9, 3, 2, 3, 8, 4, 6};
  int g[] = {89, 79, 32, 38, 46, 26, 43, 38, 32, 79};

  int *vector[] = {a, b, c, d, e, f, g};
  size_t tamVectors[] = {
      sizeof(a) / sizeof(*a),
      sizeof(b) / sizeof(*b),
      sizeof(c) / sizeof(*c),
      sizeof(d) / sizeof(*d),
      sizeof(e) / sizeof(*e),
      sizeof(f) / sizeof(*f),
      sizeof(g) / sizeof(*g)};

  for (u_long i = 0, lengthVector = sizeof(vector) / sizeof(*vector); i < lengthVector; i++)
  {
    printf("\n|**************************************| vector '%c' |**************************************|\n", (char)i + 'A');
    printVector("%d, ", vector[i], tamVectors[i]);
    printAllAlgSort(vector[i], tamVectors[i], sizeof(int));
    printVector("%d, ", vector[i], tamVectors[i]);
  }

  return 0;
}
