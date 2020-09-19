#include "acrescentaOdernadoNa3.h"
#define voidToInt(ptr) (*(int *)ptr)
#define decrementSetPtrRemoveQueue(tam, item_queue, queue, ptr_queue) \
  {                                                                   \
    tam--;                                                            \
    item_queue = getItemQueue(queue);                                 \
    ptr_queue = queue;                                                \
  }

void acrescentaOrdenadoNa3(Queue *q1, Queue *q2, Queue *q3)
{
  Queue *q1Copy = copyQueue(q1);
  Queue *q2Copy = copyQueue(q2);
  u_long q1Tam = getTamQueue(q1Copy);
  u_long q2Tam = getTamQueue(q2Copy);

  while (q1Tam || q2Tam)
  {
    Queue *ptr_queue_remove = NULL;
    void *num = NULL;
    if (q1Tam && q2Tam)
    {
      if (voidToInt(getItemQueue(q1Copy)) > voidToInt(getItemQueue(q2Copy)))
      {
        decrementSetPtrRemoveQueue(q2Tam, num, q2Copy, ptr_queue_remove);
      }
      else
        decrementSetPtrRemoveQueue(q1Tam, num, q1Copy, ptr_queue_remove);
    }
    else if (q1Tam)
    {
      decrementSetPtrRemoveQueue(q1Tam, num, q1Copy, ptr_queue_remove);
    }
    else
      decrementSetPtrRemoveQueue(q2Tam, num, q2Copy, ptr_queue_remove);

    addQueue(q3, num);
    removeQueue(ptr_queue_remove);
  }
  destroyQueue(q1Copy);
  destroyQueue(q2Copy);
}
