#include "Heap.h"

struct heap
{
  void *data;
  Heap *left;
  Heap *right;
};

static inline void isNullPointer(void *ptr, const char *str_error_print)
{
  if (!ptr)
  {
    perror(str_error_print);
    exit(EXIT_FAILURE);
  }
}

Heap *criaHeap(void *item, Heap *left_heap, Heap *right_heap)
{
  Heap *h = malloc(sizeof(Heap));
  isNullPointer(h, "Erro ao alocar memória para nó da Heap");
  h->data = item;
  h->left = left_heap;
  h->right = right_heap;
  return h;
}

bool destroyHeap(Heap *heap)
{
  if (heap)
  {
    destroyHeap(heap->left);
    destroyHeap(heap->right);
    free(heap);
    return true;
  }
  return false;
}

void percorreHeap(Heap *heap, void (*externFunction)(void *))
{
  if (heap)
  {
    externFunction(heap->data);
    percorreHeap(heap->left, externFunction);
    percorreHeap(heap->right, externFunction);
  }
}

bool isEmptyHeap(Heap *heap)
{
  return heap ? true : false;
}

bool hasItemHeap(Heap *heap, void *item, int (*comparador)(void *, void *))
{
  if (heap)
    return comparador(heap->data, item) ? hasItemHeap(heap->left, item, comparador) : hasItemHeap(heap->right, item, comparador);
  return false;
}

u_long tamHeap(Heap *heap)
{
  if (heap)
    return 1 + tamHeap(heap->left) + tamHeap(heap->right);
  return 0;
}

u_long tamHeapLeaves(Heap *heap)
{
  if (heap)
    return heap->left && heap->right ? tamHeapLeaves(heap->left) + tamHeapLeaves(heap->right) : (heap->left ? tamHeapLeaves(heap->left) : (heap->right ? tamHeapLeaves(heap->right) : 1));
  return 0;
}

u_long tamHeapWithoutLeaves(Heap *heap)
{
  return tamHeap(heap) - tamHeapLeaves(heap);
}
