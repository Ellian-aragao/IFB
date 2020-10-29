/*********************************************************************
 * para compilar, utilize os flags:
 * - LIB: para não compilar a main implementada no sort.c
 * - DEBUG: exibir no console cada parte do algoritmo sendo exacutada
 * gcc sort.c 12.c -DLIB -DDEBUG
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


int main()
{
  const int vector[] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
  const int tam = sizeof(vector) / sizeof(vector[0]);
  const size_t sizeVector = tam * sizeof(int);
  int vectorToSort[tam];
  const char strPrint[] = "%d, ";


  puts("\n--------------------merge-----------------------");
  printVector(strPrint, vector, tam);
  memcpy(vectorToSort, vector, sizeVector);
  mergeSort(vectorToSort, tam, sizeof(vector[0]), compareInteger);

  puts("\n--------------------quick-----------------------");
  printVector(strPrint, vector, tam);
  memcpy(vectorToSort, vector, sizeVector);
  quickSort(vectorToSort, tam, sizeof(vector[0]), compareInteger);

  puts("\n--------------------heap------------------------");
  printVector(strPrint, vector, tam);
  memcpy(vectorToSort, vector, sizeVector);
  heapSort(vectorToSort, tam, sizeof(vector[0]), compareInteger);

  printVector(strPrint, vectorToSort, tam);
  return 0;
}
