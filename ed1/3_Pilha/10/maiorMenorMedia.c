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
