#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <string.h>

#define SORT_FUNCS_ARGUMENTS void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *)

void bubbleSort(SORT_FUNCS_ARGUMENTS);
void insertionSort(SORT_FUNCS_ARGUMENTS);
void insertionSortItem(void *vector, u_long tamVector, void *item, size_t SizeValuesVector, int (*comparator)(void *, void *));
void quickSort(SORT_FUNCS_ARGUMENTS);
void selectionSort(SORT_FUNCS_ARGUMENTS);
void shellSort(SORT_FUNCS_ARGUMENTS);
void mergeSort(SORT_FUNCS_ARGUMENTS);
void heapSort(SORT_FUNCS_ARGUMENTS);

#endif