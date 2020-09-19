#include "analizadorDeExpressao.h"

bool analizadorDeExpressao(char *str)
{
  Stack *s = createStack(sizeof(char));
  char *ptr_str = str;
  bool var = true;

  while (*ptr_str)
  {
    if (*ptr_str == '(')
      pushStack(s, ptr_str);
    if (')' == *ptr_str)
    {
      if (getTamStack(s))
        popStack(s);
      else
      {
        var = false;
        break;
      }
    }
    ptr_str++;
  }

  u_long tam = getTamStack(s);
  destroyStack(s);
  return var && !tam;
}
