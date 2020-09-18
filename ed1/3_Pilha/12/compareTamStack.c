#include "compareTamStack.h"

int compareTamStack(Stack *s1, Stack *s2)
{
  u_long s1Tam = getTamStack(s1),
         s2Tam = getTamStack(s2);
  return s1Tam < s2Tam ? -1 : s1Tam > s2Tam ? 1 : 0;
}

int main()
{
  Stack* s1 = createStack(sizeof(char));
  Stack* s2 = createStack(sizeof(char));
  char a = 'a';
  pushStack(s1, &a);
  pushStack(s2, &a);
  pushStack(s1, &a);
  printf("%d\n",compareTamStack(s1,s2));
  destroyLinkedList(s1);
  destroyLinkedList(s2);
  return 0;
}
