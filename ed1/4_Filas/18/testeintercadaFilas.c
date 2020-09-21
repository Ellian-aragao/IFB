#include "intercadaFilas.h"

void print(Queue *q)
{
  putchar('[');
  while (getTamQueue(q))
  {
    printf("%d,", *(int *)getItemQueue(q));
    removeQueue(q);
  }
  puts("]");
}

int main()
{
  Queue *q = createQueue(4);
  for (int i = 0; i < 10; i++)
    addQueue(q, &i);
  Queue *q2 = createQueue(4);
  for (int i = 10; i < 20; i++)
    addQueue(q2, &i);
  Queue *intercaladas = intercalaFilas(q, q2);
  print(intercaladas);
  destroyQueue(intercaladas);
  destroyQueue(q2);
  destroyQueue(q);
  return 0;
}
