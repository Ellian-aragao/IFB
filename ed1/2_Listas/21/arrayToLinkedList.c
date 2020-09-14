#include "arrayToLinkedList.h"

LinkedList *arrayToLinked(void *initArray, u_long nItens, size_t sizeOfItens)
{
  LinkedList *list = createLinkedList(sizeOfItens);
  for (u_long i = 0; i < nItens; i++)
    appendLinkedList(list, initArray + (i * sizeOfItens));
  return list;
}