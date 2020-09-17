#include "inversorDePalavras.h"

static inline void invertePalavra(char *str, char *strToCopy)
{
  char *strToInvert = strtok(strToCopy, " ");
  bool primeira = true;
  while (strToInvert != NULL)
  {
    Stack *stackStr = createStack(sizeof(char));
    size_t i;
    for (i = 0; strToInvert[i]; i++)
      pushStack(stackStr, &strToInvert[i]);

    char strInvertida[strlen(strToInvert)];
    for (i = 0; strToInvert[i]; i++)
    {
      strInvertida[i] = *(char *)getItemStack(stackStr);
      popStack(stackStr);
    }
    strInvertida[i] = '\0';
    destroyStack(stackStr);
    strToInvert = strtok(NULL, " ");

    strcat(primeira ? strcpy(str, strInvertida) : strcat(str, strInvertida), " ");
    primeira = false;
  }
}

static inline size_t findStrDot(const char *str)
{
  size_t i;
  for (i = 0; str[i] != '.'; i++)
    ;
  return i;
}

bool inversorDePalavras(const char *x)
{
  const size_t strLength = strlen(x);
  char inversaStr[strLength], strToCopy[strLength];
  size_t i = findStrDot(x);
  strcpy(strToCopy, x);
  strToCopy[i] = '\0';
  invertePalavra(inversaStr, strToCopy);
  inversaStr[strLength] = '\0';
  puts(inversaStr);
  return false;
}
