#include "stringXeReversaDeY.h"

int main()
{
  char str1[] = "macaco",
       str2[] = "ocacam",
       strPrint[11];
  if (stringXeReversaDeY(str1, str2))
    strcpy(strPrint, "É reversa");
  else
    strcpy(strPrint, "Ñ reversa");
  puts(strPrint);
  return 0;
}
