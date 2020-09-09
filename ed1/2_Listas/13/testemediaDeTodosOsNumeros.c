#include "../LinkedList/linkedList.h"
#include "mediaDeTodosOsNumeros.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
  LinkedList *listaUlong = createLinkedList(sizeof(u_long));
  for (size_t i = 0; i < 10; i++)
    appendLinkedList(listaUlong, &i);
  printf("%f\n", mediaDeTodosOsNumeros(listaUlong));
  return 0;
}
