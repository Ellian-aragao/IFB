#include "getInitRemove.h"

int main()
{
  Queue *q = createQueue(4);
  for (int i = 2; i < 3; i++)
    addQueue(q, &i);
  int *x = getInitRemove(q);
  printf("%d\n", *x);
  free(x);
  destroyQueue(q);
  return 0;
}
