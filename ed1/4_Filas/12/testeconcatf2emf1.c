#include "concatf2emf1.h"

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
  print(q);
  concatQ2emQ1(q, q2);
  print(q2);
  destroyQueue(q2);
  destroyQueue(q);
  return 0;
}
