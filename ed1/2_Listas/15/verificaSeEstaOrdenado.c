#include "verificaSeEstaOrdenado.h"

int verificaSeEstaOrdenado(LinkedList *list, int (*comparadorOrdenacao)(void *, void *))
{
  return isItensInLinkedListSorted(list, comparadorOrdenacao);
}