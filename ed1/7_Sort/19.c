#include "sort.h"
#include <stdio.h>

int compare(void *i1, void *i2)
{
  return strlen(i1) > strlen(i2);
}

int main()
{
  u_long nNomes, tamNomes;
  puts("digite quantos nomes serão inseridos e o tamanho do maior destes, separado por virgula ','");
  fflush(stdin);
  scanf("%lu, %lu", &nNomes, &tamNomes);

  char listaNomes[nNomes][tamNomes];

  for (u_long i = 0; i < nNomes; i++)
  {
    fflush(stdin);
    scanf("%s", listaNomes[i]);
  }

  putchar('\n');
  for (u_long i = 0; i < nNomes; i++)
    puts(listaNomes[i]);

  selectionSort(listaNomes, nNomes, tamNomes * sizeof(char), compare);

  putchar('\n');
  for (u_long i = 0; i < nNomes; i++)
    puts(listaNomes[i]);

  return 0;
}
