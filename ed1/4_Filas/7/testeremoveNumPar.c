#include "removeNumPar.h"

void printItemInt(void *item)
{
  printf("%d,", *(int *)item);
}

void testForEachPrintItensInt(LinkedList *list)
{
  putchar('[');
  forEachLinkedList(list, printItemInt);
  puts("]");
}

int main()
{
  Queue *q = createQueue(4);
  for (int i = 0; i < 10; i++)
    addQueue(q, &i);
  removeNumPar(q);
  testForEachPrintItensInt(q);
  destroyQueue(q);
  return 0;
}
