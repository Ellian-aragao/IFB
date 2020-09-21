#include "quantidadeDePares.h"

int main()
{
  Queue *q = createQueue(4);
  for (int i = 0; i < 7; i++)
    addQueue(q, &i);
  printf("%ld\n",quantidadeDePares(q));
  destroyQueue(q);
  return 0;
}
