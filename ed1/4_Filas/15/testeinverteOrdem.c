#include "inverteOrdem.h"

void print(void *ptr)
{
  printf("%d,", *(int *)ptr);
}

int main()
{
  Queue *q = createQueue(4);
  for (int i = 0; i < 10; i++)
    addQueue(q, &i);
  forEachLinkedList(q, print);
  putchar('\n');
  inverteFila(q);
  forEachLinkedList(q, print);
  destroyQueue(q);
  return 0;
}
