#include "copyLinkedList.h"

LinkedList *listaCopiada;

void getItensInLinkedList(void *item)
{
  appendLinkedList(listaCopiada, item);
}

LinkedList *copyLinkedList(LinkedList *listToCopy)
{
  unsigned long sizeList = getSizeofItensLinkedList(listToCopy);
  listaCopiada = createLinkedList(sizeList);
  forEachLinkedList(listToCopy, getItensInLinkedList);
  return listaCopiada;
}
