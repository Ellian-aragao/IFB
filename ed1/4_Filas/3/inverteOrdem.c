#include "inverteOrdem.h"

void reverso(Queue *queue)
{
  LinkedList *lista = copyQueue(queue);
  while (getTamQueue(queue))
    removeQueue(queue);
  while (getTamLinkedList(lista))
  {
    addQueue(queue, getLastItemLinkedList(lista));
    removeLastItemLinkedList(lista);
  }
  destroyLinkedList(lista);
}