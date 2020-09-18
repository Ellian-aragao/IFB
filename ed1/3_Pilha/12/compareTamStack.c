#include "compareTamStack.h"

int compareTamStack(Stack *s1, Stack *s2)
{
  u_long s1Tam = getTamStack(s1),
         s2Tam = getTamStack(s2);
  return s1Tam < s2Tam ? -1 : s1Tam > s2Tam ? 1 : 0;
}
