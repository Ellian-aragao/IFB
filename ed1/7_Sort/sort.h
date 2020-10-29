#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <string.h>

void bubbleSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *));
void insertionSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *));
void insertionSortItem(void *vector, u_long tamVector, void *item, size_t SizeValuesVector, int (*comparator)(void *, void *));
void quickSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *));
void selectionSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *));
void shellSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *));
void mergeSort(void *vector, const u_long tamVector, const size_t SizeValuesVector, int (*comparator)(void *, void *));
void heapSort(void *vector, u_long tamVector, size_t SizeValuesVector, int (*comparator)(void *, void *));

#endif