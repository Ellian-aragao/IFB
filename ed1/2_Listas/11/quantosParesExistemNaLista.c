#include "../LinkedList/linkedList.h"
#include "quantosParesExistemNaLista.h"

#define getModTwoU_longFromVoidPtr(number) !(*(u_long *)number % 2)

u_long quantidadeDePares = 0;

void isEvenNumber(void *number)
{
  quantidadeDePares += getModTwoU_longFromVoidPtr(number);
}

u_long quantosParesExistemNaLista(LinkedList *list)
{
  forEachLinkedList(list, isEvenNumber);
  return quantidadeDePares;
}
