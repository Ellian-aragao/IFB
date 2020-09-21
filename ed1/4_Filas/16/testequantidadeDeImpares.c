#include "quantidadeDeImpares.h"

int main()
{
  Queue *q = createQueue(4);
  for (int i = 1; i < 4; i++)
    addQueue(q, &i);
  printf("%ld\n",quantidadeDeImpares(q));
  destroyQueue(q);
  return 0;
}
