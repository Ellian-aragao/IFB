#include "pilhaDeFibonacci.h"

Stack *pilhaDeFibonacci(u_long maxTamPilha)
{
  Stack *s = createStack(sizeof(u_long));
  u_long penutimo = 0,
         ultimo = 1;
  pushStack(s, &penutimo);
  pushStack(s, &ultimo);
  for (u_long i = 2; i < maxTamPilha; i++)
  {
    penutimo = ultimo;
    ultimo = *(u_long *)getItemStack(s);
    u_long next = penutimo + ultimo; 
    pushStack(s, &next);
  }
  return s;
}