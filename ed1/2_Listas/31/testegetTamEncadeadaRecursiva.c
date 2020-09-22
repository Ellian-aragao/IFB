#include "isEqualRecursiva.h"
int main()
{
  LinkedList *l1 = createLinkedList(4),
             *l2 = createLinkedList(4);
  int i;
  for (i = 0; i < 5; i++)
  {
    appendLinkedList(l1, &i);
    appendLinkedList(l2, &i);
  }
  appendLinkedList(l2, &i);
  printf("%d\n", isEqualRecursiva(l1, l2));
  destroyLinkedList(l1);
  destroyLinkedList(l2);
  return 0;
}
