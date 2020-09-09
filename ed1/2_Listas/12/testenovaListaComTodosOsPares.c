#include "../LinkedList/linkedList.h"
#include "novaListaComTodosOsPares.h"
#include <stdio.h>

void printUlong(void *item)
{
  printf("%ld,", *(u_long *)item);
}

int main(int argc, char const *argv[])
{
  LinkedList *listaUlong = createLinkedList(sizeof(u_long));
  for (size_t i = 0; i < 10; i++)
    appendLinkedList(listaUlong, &i);
  LinkedList *quantosInteiros = novaListaComTodosOsPares(listaUlong);
  forEachItem(quantosInteiros, printUlong);
  return 0;
}
