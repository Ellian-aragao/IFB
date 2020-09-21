#include "ordenaInteiros.h"

int sortInt(void *i1, void *i2)
{
  if (*(int *)i1 > *(int *)i2)
    return true;
  return false;
}

void ordenaInteiros(Queue *q)
{
  sortLinkedList(q, sortInt);
}