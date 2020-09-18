#include "pilhaDeFibonacci.h"

int main()
{
  Stack *s = pilhaDeFibonacci(20);
  while (getTamStack(s))
  {
    u_long *num = getPopStack(s);
    printf("%ld,",*num);
    free(num);
  }
  destroyStack(s);
  return 0;
}
