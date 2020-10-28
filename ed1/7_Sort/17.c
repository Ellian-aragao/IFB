#include "sort.h"
#include <stdio.h>

int compare(void *i1, void *i2)
{
  // puts("comparou");
  // printf("%s %s %d\n", (char *)i1, (char *)i2, strcmp(i1, i2));
  return strcmp(i1, i2) >= 0 ? 1 : 0;
}

void print(char *listaNomes[], int tam)
{
  putchar('\n');
  for (u_long i = 0; i < tam; i++)
    puts(listaNomes[i]);
}

int main()
{
  u_long nNomes, tamNomes;
  nNomes = 4;
  tamNomes = 10;
  // puts("digite quantos nomes serão inseridos e o tamanho do maior destes, separado por virgula ','");
  // setbuf(stdin, NULL);
  // scanf("%lu, %lu", &nNomes, &tamNomes);

  char listaNomes[nNomes][tamNomes];

  for (u_long i = 0; i < nNomes; i++)
  {
    fflush(stdin);
    char tmp[tamNomes];
    scanf("%s", tmp);
    insertionSortItem(listaNomes, i, tmp, tamNomes * sizeof(char), compare);
    // puts(tmp);
  }

  print(listaNomes, nNomes);
  // putchar('\n');
  // for (u_long i = 0; i < nNomes; i++)
  //   puts(listaNomes[i]);

  return 0;
}
