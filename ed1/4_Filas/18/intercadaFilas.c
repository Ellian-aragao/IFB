#include "intercadaFilas.h"
#define decrementSetPtrRemoveQueue(tam, item_queue, queue, ptr_queue) \
  {                                                                   \
    tam--;                                                            \
    item_queue = getItemQueue(queue);                                 \
    ptr_queue = queue;                                                \
  }

Queue *intercalaFilas(Queue *q1, Queue *q2)
{
  Queue *queue_to_return = createQueue(getSizeofItensOfQueue(q1));
  Queue *q1Copy = copyQueue(q1);
  Queue *q2Copy = copyQueue(q2);
  u_long q1Tam = getTamQueue(q1Copy);
  u_long q2Tam = getTamQueue(q2Copy);

  Queue *ptr_queue_remove = q2Copy;
  while (q1Tam || q2Tam)
  {
    void *item = NULL;
    if (q1Tam && q2Tam)
    {
      if (ptr_queue_remove == q1Copy)
      {
        decrementSetPtrRemoveQueue(q2Tam, item, q2Copy, ptr_queue_remove);
        ptr_queue_remove = q2Copy;
      }
      else
      {
        decrementSetPtrRemoveQueue(q1Tam, item, q1Copy, ptr_queue_remove);
        ptr_queue_remove = q1Copy;
      }
    }
    else if (q1Tam)
    {
      decrementSetPtrRemoveQueue(q1Tam, item, q1Copy, ptr_queue_remove);
    }
    else
      decrementSetPtrRemoveQueue(q2Tam, item, q2Copy, ptr_queue_remove);

    addQueue(queue_to_return, item);
    removeQueue(ptr_queue_remove);
  }
  destroyQueue(q1Copy);
  destroyQueue(q2Copy);
  return queue_to_return;
}
