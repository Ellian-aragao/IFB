#include "inverteLinkedList.h"

LinkedList *retornaListaInversa(LinkedList *list)
{
  LinkedList *inversa = createLinkedList(getSizeofItensLinkedList(list));
  for (u_long i = getTamLinkedList(list); i > 0; i--)
  {
    appendLinkedList(inversa, getItemByIndex(list, i - 1));
  }
  return inversa;
}
