#include "maiorMenorMedia.h"

MAIORMENORMEDIA getMinMaxMedia(Queue *q)
{
  int max = INT_MIN;
  int min = INT_MAX;
  float media = 0;
  int nItens = getTamQueue(q);
  for (u_long i = 0; i < (u_long)nItens; i++)
  {
    int *var = getItemQueue(q);
    media += *var;
    if (*var > max)
      max = *var;
    if (*var < min)
      min = *var;
    removeQueue(q);
  }

  MAIORMENORMEDIA a = {min, max, media / nItens};
  return a;
}