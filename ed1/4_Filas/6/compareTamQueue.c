#include "compareTamQueue.h"

int compareTamQueue(Queue *q1, Queue *q2)
{
  u_long q1Tam = getTamQueue(q1),
         q2Tam = getTamQueue(q2);
  return q1Tam < q2Tam ? -1 : q1Tam > q2Tam ? 1 : 0;
}
