#include "../LinkedList/linkedList.h"
#include "novaListaComTodosOsPares.h"

#define getModTwoU_longFromVoidPtr(number) !(*(u_long *)number % 2)
LinkedList *listaDosPares;

void isEvenNumber(void *number)
{
  if (getModTwoU_longFromVoidPtr(number))
    appendLinkedList(listaDosPares, number);
}

LinkedList *novaListaComTodosOsPares(LinkedList *list)
{
  listaDosPares = createLinkedList(sizeof(u_long));
  forEachLinkedList(list, isEvenNumber);
  return listaDosPares;
}
