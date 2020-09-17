#include "palindromo.h"

static inline bool isNotPar(size_t *n)
{
  bool valueReturn = *n % 2;
  *n = *n / 2;
  return valueReturn;
}

static inline bool compare(char *str, size_t tam)
{
  bool par = isNotPar(&tam);

  Stack *stackStr = createStack(sizeof(char));
  size_t i;
  for (i = 0; i < tam; i++)
    pushStack(stackStr, &str[i]);

  i += par;

  char metadeDireita[tam];
  for (size_t j = 0; i <= strlen(str); i++, j++)
    metadeDireita[j] = str[i];

  char strInvertida[tam];
  for (i = 0; i < tam; i++)
  {
    strInvertida[i] = *(char *)getItemStack(stackStr);
    popStack(stackStr);
  }
  strInvertida[i] = '\0';
  destroyStack(stackStr);
  // printf("par: %d\n'%s'\n'%s'\n", !par, metadeDireita, strInvertida);
  return strcmp(metadeDireita, strInvertida) ? false : true;
}

bool isPalindromo(char *x)
{
  return compare(x, strlen(x));
}
