#include "maiorMenorMedia.h"

MAIORMENORMEDIA getMinMaxMedia(Stack *s)
{
  int max = INT_MIN;
  int min = INT_MAX;
  float media = 0;
  int nItens = getTamStack(s);
  for (u_long i = 0; i < (u_long)nItens; i++)
  {
    int *var = getPopStack(s);
    media += *var;
    if (*var > max)
      max = *var;
    if (*var < min)
      min = *var;
    free(var);
  }

  MAIORMENORMEDIA a = {min, max, media / nItens};
  return a;
}

int main()
{
  Stack *s = createStack(4);
  for (int i = 0; i < 10; i++)
    pushStack(s, &i);
  MAIORMENORMEDIA a = getMinMaxMedia(s);
  printf("min: %d\nmax: %d\nmedia: %f\n", a.menor, a.maior, a.media);
  destroyLinkedList(s);
  return 0;
}
