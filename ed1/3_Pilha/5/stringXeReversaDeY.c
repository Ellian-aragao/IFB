#include "stringXeReversaDeY.h"

bool stringXeReversaDeY(const char *x, const char *y)
{
  const size_t strLength = strlen(x);
  char *inversaX = malloc((strLength + 1) * sizeof(char));

  Stack *stackStr = createStack(sizeof(char));
  for (size_t i = 0; i < strLength; i++)
    pushStack(stackStr, (&inversaX + i));

  char inversaStr[strLength];
  for (size_t i = 0; i < strLength; i++)
  {
    inversaStr[i] = *(char *)getItemStack(stackStr);
    popStack(stackStr);
  }
  destroyStack(stackStr);
  int var = strcmp(inversaX, y);
  free(inversaX);
  return var == 0 ? true : false;
}