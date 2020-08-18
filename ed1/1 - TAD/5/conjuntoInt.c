#include "conjuntoInt.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct conjuntoInt
{
  long *vetor;
  unsigned long tam;
};

// algoritmo copiado para auxiliar mexer com conjunto
void insertionSort(CONJUNTO *conjunto)
{
  long n = conjunto->tam;
  long *arr = conjunto->vetor;
  long i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

CONJUNTO *criaConjuntoVazio()
{
  CONJUNTO *ptr = malloc(sizeof(CONJUNTO));
  if (ptr == NULL)
  {
    fprintf(stderr, "erro na criação do conjunto");
    return NULL;
  }
  ptr->vetor = NULL;
  ptr->tam = 0;
  return ptr;
}

CONJUNTO *insere(CONJUNTO *conjunto, long valorAdicionar)
{
  if (conjunto->tam == 0)
  {
    conjunto->vetor = malloc(sizeof(long));
    if (conjunto->vetor == NULL)
    {
      fprintf(stderr, "Erro na inserção de item no conjunto vazio\n");
      return NULL;
    }
  }
  else
  {
    long *tmp = realloc(conjunto->vetor, (conjunto->tam + 1) * sizeof(long));
    if (tmp == NULL)
    {
      fprintf(stderr, "Erro na inserção de item no conjunto\n");
      return NULL;
    }
    conjunto->vetor = tmp;
  }
  conjunto->vetor[conjunto->tam++] = valorAdicionar;
  insertionSort(conjunto);
  return conjunto;
}

// CONJUNTO *uniao() {}
// CONJUNTO* remove() {}
// CONJUNTO* interseccao() {}
// CONJUNTO* diferenca() {}

// tentativa de algoritmo bisseccao baseado em calculo numérico 2ºsem 2019
int testaSePertence(CONJUNTO *conjunto, long numeroProcurado)
{
  long *vetor = conjunto->vetor;
  unsigned long
      limiteInferior = 0,
      LimiteSuperior = conjunto->tam,
      mediana = (long)1 + conjunto->tam / 2;

  while (TRUE)
  {
    if (vetor[mediana] > numeroProcurado)
      LimiteSuperior = mediana;
    else if (vetor[mediana] < numeroProcurado)
      limiteInferior = mediana;
    else if (vetor[mediana] == numeroProcurado)
      return TRUE;
    if ((limiteInferior + 1) == LimiteSuperior)
      return FALSE;
    mediana = (long)limiteInferior + (LimiteSuperior - limiteInferior) / 2;
  }
}

long menor(CONJUNTO *conjunto)
{
  return conjunto->vetor[0];
}

long maior(CONJUNTO *conjunto)
{
  return conjunto->vetor[conjunto->tam];
}

int testaSeOsConjuntosSaoIguais(CONJUNTO* conjunto1, CONJUNTO* conjunto2) {
  long tam;
  if ((tam = conjunto1->tam) == conjunto2->tam)
  {
    for (unsigned long i = 0; i < tam; i++)
    {
      if (conjunto1->vetor[i] != conjunto2->vetor[i])
        return FALSE;
    }
    return TRUE;
  }
  return FALSE;
}

unsigned long tamanho(CONJUNTO* conjunto) {
  return conjunto->tam;
}

int testaSeoConjuntoVazio(CONJUNTO* conjunto) {
  if (conjunto->tam)
  {
    return TRUE;
  }
  return FALSE;
}

int main(int argc, char const *argv[])
{
  CONJUNTO *ptr = criaConjuntoVazio();
  for (long i = 1000; i > 0; i--)
  {
    ptr = insere(ptr, i);
  }
  printf("%d\n", testaSePertence(ptr, 378));

  return 0;
}
