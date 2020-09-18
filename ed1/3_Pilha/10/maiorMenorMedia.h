#pragma once

#include "../PilhaInterface/Stack.h"
#include "limits.h"

typedef struct maiorMenorMedia
{
  int menor;
  int maior;
  float media;
} MAIORMENORMEDIA;

MAIORMENORMEDIA getMinMaxMedia(Stack *s);