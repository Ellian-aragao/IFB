#include "conversorDecimal.h"

int main()
{
  for (size_t i = 0; i < 16; i++)
  {
    char *str = decimalToHexadecimal(i);
    printf("%s\n",str);
    free(str);
  }
  return 0;
}
