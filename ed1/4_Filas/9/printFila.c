#include "printFila.h"

void printFila(Queue *queue, void (*printer)(void *))
{
  Queue *q = copyQueue(queue);
  while (getTamQueue(q))
  {
    printer(getItemQueue(q));
    removeQueue(q);
  }
  destroyQueue(q);
}
