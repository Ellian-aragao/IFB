#include "conversorDecimal.h"

#define BINARIO 2
#define OCTAL 8
#define HEX 16

static inline Stack *decimalToBase(u_long *n, const u_long *base)
{
  Stack *s = createStack(sizeof(u_long));
  if (*n == 0)
    pushStack(s, n);
  while (*n)
  {
    u_long binary = *n % *base;
    pushStack(s, &binary);
    *n /= *base;
  }
  return s;
}

static inline char *mallocCharPtr(u_long *tamStack)
{
  char *str = malloc(*tamStack * sizeof(char));
  if (!str)
  {
    perror("Erro na alocação de memória para conversão");
    exit(EXIT_FAILURE);
  }
  return str;
}

static inline void stackToStrConverter(Stack *s, const u_long *tamStack, char *str)
{
  const char dicToHex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
  for (u_long i = 0; i < *tamStack; i++)
  {
    int8_t *indexToDicHex = getPopStack(s);
    str[i] = dicToHex[*indexToDicHex];
    free(indexToDicHex);
  }
  str[*tamStack] = '\0';
}

static inline char *rotinasComunsDoConversor(u_long *n, u_long base)
{
  Stack *s = decimalToBase(n, &base);
  u_long tamStack = getTamStack(s);
  char *str = mallocCharPtr(&tamStack);
  stackToStrConverter(s, &tamStack, str);
  destroyStack(s);
  return str;
}

char *decimalToBinario(u_long n)
{
  return rotinasComunsDoConversor(&n, BINARIO);
}
char *decimalToOctal(u_long n)
{
  return rotinasComunsDoConversor(&n, OCTAL);
}
char *decimalToHexadecimal(u_long n)
{
  return rotinasComunsDoConversor(&n, HEX);
}