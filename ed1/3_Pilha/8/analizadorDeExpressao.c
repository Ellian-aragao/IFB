#include "analizadorDeExpressao.h"

bool analizadorDeExpressao(char *str)
{
  Stack *s = createStack(sizeof(char));
  char *ptr_str = str;
  while (*ptr_str)
  {
      // printf("%d\n",*ptr_str);
    if (*ptr_str == '(' || ')' == *ptr_str){
      pushStack(s, ptr_str);
    }
    ptr_str++;
  }
  u_long tamStack = getTamStack(s);
  int cont = 0;
  while (tamStack)
  {
    char *var = getPopStack(s);
    printf("'%c' %ld\n", *var, tamStack);
    if (*var == '(')
      cont++;
    else if (*var == ')')
      cont--;
    else {
      cont = 1;
      break;
    }

    free(var);
    tamStack--;
  }
  destroyStack(s);
  return !cont;
}

int main()
{
  char str[] = "";
  puts(analizadorDeExpressao(str) ? "Correto" : "Incorreto");
  return 0;
}
