#include "somaValores.h"

int main()
{
  LinkedList *l = createLinkedList(4);
  for (int i = 10; i < 12; i++)
    appendLinkedList(l, &i);
  printf("%d\n",somaInteiros(l));
  destroyLinkedList(l);
  return 0;
}
