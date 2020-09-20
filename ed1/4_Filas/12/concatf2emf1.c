#include "concatf2emf1.h"

void concatQ2emQ1(Queue *q1, Queue *q2)
{
  while (getTamQueue(q2))
  {
    addQueue(q1, getItemQueue(q2));
    removeQueue(q2);
  }
}
