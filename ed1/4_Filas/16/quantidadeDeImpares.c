#include "quantidadeDeImpares.h"

u_long quantidadeDeImpares(Queue *queue)
{
  Queue *q = copyQueue(queue);
  u_long mod = 0;
  while (getTamQueue(q))
  {
    mod += *(int*)getItemQueue(q) % 2;
    removeQueue(q);
  }
  destroyQueue(q);
  return mod;
}
