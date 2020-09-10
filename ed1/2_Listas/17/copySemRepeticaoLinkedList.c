#include "copySemRepeticaoLinkedList.h"

LinkedList *listaCopiada;

void getItensInLinkedList(void *item)
{
  appendLinkedList(listaCopiada, item);
}

LinkedList *copySemRepeticaoLinkedList(LinkedList *listToCopy, int (*compare)(void *, void *))
{
  unsigned long sizeList = getSizeofItensLinkedList(listToCopy);
  listaCopiada = createLinkedList(sizeList);
  forEachLinkedList(listToCopy, getItensInLinkedList);
  removeEqualsItens(listaCopiada, compare);
  return listaCopiada;
}
