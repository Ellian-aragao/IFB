#pragma once

#include "../FilaInterface/Queue.h"
#include "limits.h"

typedef struct maiorMenorMedia
{
  int menor;
  int maior;
  float media;
} MAIORMENORMEDIA;

MAIORMENORMEDIA getMinMaxMedia(Queue *s);