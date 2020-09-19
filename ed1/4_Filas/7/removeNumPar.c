#include "removeNumPar.h"

void removeNumPar(Queue *queue)
{
  Queue *qfinal = createQueue(getSizeofItensOfQueue(queue));
  
  while (getTamQueue(queue))
  {
    int *n = getItemQueue(queue);
    if ((*n % 2))
      addQueue(qfinal, n);
    removeQueue(queue);
  }
  while (getTamQueue(qfinal))
  {
    int *n = getItemQueue(qfinal);
    addQueue(queue, n);
    removeQueue(qfinal);
  }
  destroyQueue(qfinal);
}
