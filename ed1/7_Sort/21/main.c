#include "21.h"
#include "../sort.h"
#include <stdio.h>
#include <stdbool.h>
#define TAM 10

static inline void printP(Pessoa *p)
{
  printf(
      "%02d - %s - %.1f%c",
      getMatricula(p),
      getNome(p),
      getNota(p),
      '\n');
}

static inline int compareMatricula(Pessoa *p1, Pessoa *p2, const bool crescente)
{
  return crescente ? getMatricula(p1) > getMatricula(p2) : getMatricula(p1) < getMatricula(p2);
}
static inline int compareNota(Pessoa *p1, Pessoa *p2, const bool crescente)
{
  return crescente ? getNota(p1) > getNota(p2) : getNota(p1) < getNota(p2);
}
static inline int compareNome(Pessoa *p1, Pessoa *p2, const bool crescente)
{
  const int cmp = strcmp(getNome(p1), getNome(p2));
  if (crescente)
    return cmp < 0 ? 0 : 1;
  return cmp < 0 ? 1 : 0;
}

int compareP(void *p1, void *p2)
{
  return compareMatricula(p1, p2, true);
}

int main()
{
  Pessoa vectorP[TAM];
  char nome[2] = "a";
  Pessoa *p = criaPessoa();
  for (int i = 0, j = TAM; i < TAM; i++, j--)
  {
    setPessoa(p, j + 1, nome, j);
    memcpy(&vectorP[i], p, sizeof(Pessoa));
    printP(&vectorP[i]);
    nome[0] = 1 + j + 'a';
  }
  free(p);

  selectionSort(&vectorP, TAM, sizeof(Pessoa), compareP);

  putchar('\n');
  for (int i = 0; i < TAM; i++)
    printP(&vectorP[i]);

  return 0;
}
