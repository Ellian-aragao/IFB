#include "getTamEncadeadaRecursiva.h"
int main()
{
  LinkedList *l = createLinkedList(4);
  for (int i = 0; i < 10; i++)
    appendLinkedList(l, &i);
  printf("%ld\n", getTamEncadeadaRecursiva(l));
  destroyLinkedList(l);
  return 0;
}
