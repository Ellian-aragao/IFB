#include "stringXeReversaDeY.h"

bool stringXeReversaDeY(char *x, const char *y)
{
  const size_t strLength = strlen(x);
  if (strLength != strlen(y))
    return false;

  Stack *stackStr = createStack(sizeof(char));
  for (size_t i = 0; i < strLength; i++)
    pushStack(stackStr, &x[i]);

  char inversaStr[strLength];
  for (size_t i = 0; i < strLength; i++)
  {
    inversaStr[i] = *(char *)getItemStack(stackStr);
    popStack(stackStr);
  }
  destroyStack(stackStr);

  return strncmp(inversaStr, y, strLength) == 0 ? true : false;
}
