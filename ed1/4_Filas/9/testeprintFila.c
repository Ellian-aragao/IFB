#include "printFila.h"

void printer(void *ptr)
{
  printf("%d,", *(int *)ptr);
}

int main()
{
  Queue *q = createQueue(4);
  for (int i = 0; i < 10; i++)
    addQueue(q, &i);
  printFila(q, printer);
  putchar('\n');
  destroyQueue(q);
  return 0;
}
