// copy paste do exercício 18, fazendo mudança no parâmetro utilizado no comparador, invertendo o sinal e removendo proteção contra espaços
#include "sort.h"
#include <stdio.h>

int comp(void *i1, void *i2)
{
  return (
    (((char *)i2)[0] == '\0' )
    ? 0
    : ((char *)i1)[0] < ((char *)i2)[0]
  );
}

int main()
{
  char nome[] = "robertinho solto alberto";
  puts(nome);
  quickSort(nome, sizeof(nome) / sizeof(char), sizeof(char), comp);
  puts(nome);
  return 0;
}
