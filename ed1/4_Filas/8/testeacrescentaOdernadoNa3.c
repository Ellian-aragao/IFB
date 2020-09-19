#include "acrescentaOdernadoNa3.h"

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
  Queue *vectorQueues[3] = {
      createQueue(4),
      createQueue(4),
      createQueue(4)};

  for (int i = 0; i < 10; i++)
    addQueue(vectorQueues[0], &i);
  for (int i = 10; i < 20; i++)
    addQueue(vectorQueues[1], &i);

  acrescentaOrdenadoNa3(vectorQueues[0], vectorQueues[1], vectorQueues[2]);

  for (int i = 0; i < 3; i++)
    testForEachPrintItensInt(vectorQueues[i]);

  for (int i = 0; i < 3; i++)
    destroyQueue(vectorQueues[i]);
  return 0;
}
