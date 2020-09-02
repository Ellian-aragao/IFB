#include "../../LinkedList/linkedList.h"
#include "concatenaLinkedList.h"
#define NULL (void*)0

LinkedList *listaConcatenada;

void appendToConcatenaLinkedList(void *item)
{
  appendLinkedList(listaConcatenada, item);
}

LinkedList *concatenaLinkedList(LinkedList *lista1, LinkedList *lista2)
{
  u_long sizeList = getSizeofItensLinkedList(lista1);
  if (!sizeList == getSizeofItensLinkedList(lista2))
  {
    return NULL;
  }
  listaConcatenada = createLinkedList(sizeList);
  forEachItem(lista1, appendToConcatenaLinkedList);
  forEachItem(lista2, appendToConcatenaLinkedList);
  return listaConcatenada;
}
