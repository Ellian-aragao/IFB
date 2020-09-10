#include "mediaDeTodosOsNumeros.h"

#define getNumberFromVoid(number) *(u_long *)number

float mediaDosNumeros = 0;

void isEvenNumber(void *number)
{
  mediaDosNumeros += getNumberFromVoid(number);
}

float mediaDeTodosOsNumeros(LinkedList* list)
{
  forEachLinkedList(list, isEvenNumber);
  return mediaDosNumeros / getTamLinkedList(list);
}
