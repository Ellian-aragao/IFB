#include "Queue.h"

u_long getTamQueue(Queue *queue)
{
  return getTamLinkedList(queue);
}

size_t getSizeofItensOfQueue(Queue *queue)
{
  return getSizeofItensLinkedList(queue);
}

Queue *createQueue(size_t sizeofItens)
{
  return createLinkedList(sizeofItens);
}

bool destroyQueue(Queue *queue)
{
  return destroyLinkedList(queue);
}

void *addQueue(Queue *queue, void *item)
{
  return appendLinkedList(queue, item);
}

void *getItemQueue(Queue *queue)
{
  return getFistItemLinkedList(queue);
}

void removeQueue(Queue *queue)
{
  removeFistItemLinkedList(queue);
}

Queue *copyQueue(Queue *queue)
{
  Queue *copySrc = createQueue(getSizeofItensOfQueue(queue));
  while (getTamQueue(queue))
  {
    addQueue(copySrc, getItemQueue(queue));
    removeQueue(queue);
  }

  for (u_long numItens = getTamQueue(copySrc); numItens; numItens--)
  {
    void *item = getItemQueue(copySrc);
    addQueue(copySrc, item);
    addQueue(queue, item);
    removeQueue(copySrc);
  }
  return copySrc;
}