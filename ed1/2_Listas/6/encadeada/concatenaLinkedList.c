#include "concatenaLinkedList.h"

LinkedList *listaConcatenada;

void appendToConcatenaLinkedList(void *item)
{
  appendLinkedList(listaConcatenada, item);
}

LinkedList *concatenaLinkedList(LinkedList *lista1, LinkedList *lista2)
{
  u_long sizeList = getSizeofItensLinkedList(lista1);
  if (sizeList == getSizeofItensLinkedList(lista2))
  {
    listaConcatenada = createLinkedList(sizeList);
    forEachLinkedList(lista1, appendToConcatenaLinkedList);
    forEachLinkedList(lista2, appendToConcatenaLinkedList);
    return listaConcatenada;
  }
  return NULL;
}
