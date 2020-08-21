#include "conjuntoInt.h"
#include <stdio.h>
#include <stdlib.h>
#define DEBUG(x) printf("%ld\n", x);

struct conjuntoInt
{
  long *vetor;
  u_long tam;
};

CONJUNTO *criaConjuntoVazio()
{
  CONJUNTO *ptr = malloc(sizeof(CONJUNTO));
  ptr->vetor = malloc(sizeof(long));
  isNullPointer(ptr->vetor, "Erro na criação do conjunto");
  ptr->tam = 0;
  return ptr;
}

int insereItemConjunto(CONJUNTO *conjunto, long valorAdicionar)
{
  u_long tmp;
  if (!testaSePertence(conjunto, valorAdicionar, &tmp))
  {
    conjunto->vetor = realloc(conjunto->vetor, (conjunto->tam + 1) * sizeof(long));
    isNullPointer(conjunto->vetor, "Erro na inserção do conjunto");

    conjunto->vetor[conjunto->tam++] = valorAdicionar;
    insertionSort(conjunto->vetor, conjunto->tam);
    return TRUE;
  }
  return FALSE;
}

void finalizaCopiaParaUniao(CONJUNTO *conjuntoUniao, CONJUNTO *aFinalizar, u_long indice)
{
  while (indice < aFinalizar->tam)
    insereItemConjunto(conjuntoUniao, aFinalizar->vetor[indice++]);
}

CONJUNTO *uniao(CONJUNTO *conj1, CONJUNTO *conj2)
{
  CONJUNTO *uniaoConjuntos = criaConjuntoVazio();
  u_long i, tam = conj1->tam < conj2->tam ? conj1->tam : conj2->tam;
  for (i = 0; i < tam; i++)
  {
    insereItemConjunto(uniaoConjuntos, conj1->vetor[i]);
    insereItemConjunto(uniaoConjuntos, conj2->vetor[i]);
  }
  conj1->tam > conj2->tam ? finalizaCopiaParaUniao(uniaoConjuntos, conj1, i) : finalizaCopiaParaUniao(uniaoConjuntos, conj2, i);
  return uniaoConjuntos;
}

int removeItemConjunto(CONJUNTO *conj, long itemRetirar)
{
  u_long index;
  if (testaSePertence(conj, itemRetirar, &index))
  {
    while (index < conj->tam)
    {
      conj->vetor[index] = conj->vetor[index + 1];
      index++;
    }
    conj->vetor = realloc(conj->vetor, (--conj->tam) * sizeof(long));
      isNullPointer(conj->vetor, "Erro na remoção de item no conjunto");
    return TRUE;
  }
  return FALSE;
}

CONJUNTO *interseccao(CONJUNTO *conj1, CONJUNTO *conj2)
{
  CONJUNTO *interseccaoConjuntos = criaConjuntoVazio();
  for (u_long i = 0; i < conj1->tam; i++)
  {
    u_long tmp;
    if (testaSePertence(conj2, conj1->vetor[i], &tmp))
    {
      insereItemConjunto(interseccaoConjuntos, conj1->vetor[i]);
    }
  }
  return interseccaoConjuntos;
}

CONJUNTO *diferenca(CONJUNTO *conj1, CONJUNTO *conj2)
{
  CONJUNTO *conjDiferenca = uniao(conj1, conj2),
           *conjInterseccao = interseccao(conj1, conj2);

  for (u_long i = 0; i < conjInterseccao->tam; i++)
  {
    removeItemConjunto(conjDiferenca, conjInterseccao->vetor[i]);
  }
  liberaConjunto(conjInterseccao);
  return conjDiferenca;
}

// tentativa de algoritmo bisseccao baseado em calculo numérico 2ºsem 2019
int testaSePertence(CONJUNTO *conjunto, long numeroProcurado, u_long *index)
{
  u_long limiteInferior = 0,
         LimiteSuperior = conjunto->tam == 0 ? 0 : conjunto->tam - 1;
  if (numeroProcurado < conjunto->vetor[limiteInferior] || conjunto->vetor[LimiteSuperior] < numeroProcurado)
    return FALSE;

  if (conjunto->vetor[limiteInferior] == numeroProcurado)
  {
    *index = limiteInferior;
    return TRUE;
  }
  else if (conjunto->vetor[LimiteSuperior] == numeroProcurado)
  {
    *index = LimiteSuperior;
    return TRUE;
  }
  else
  {
    while (TRUE)
    {
      u_long mediana = limiteInferior + (LimiteSuperior - limiteInferior) / 2;
      if (numeroProcurado < conjunto->vetor[mediana])
      {
        LimiteSuperior = mediana;
      }
      else if (conjunto->vetor[mediana] < numeroProcurado)
      {
        limiteInferior = mediana;
      }
      else if (conjunto->vetor[mediana] == numeroProcurado)
      {
        *index = mediana;
        return TRUE;
      }
      if ((limiteInferior + 1) == LimiteSuperior)
        return FALSE;
    }
  }
}

int main(int argc, char const *argv[])
{
  CONJUNTO *ptr = criaConjuntoVazio(),
           *ptr2 = criaConjuntoVazio(),
           *ptrDiferenca;

  for (long i = 0; i < 11; i++)
  {
    insereItemConjunto(ptr, i);
    insereItemConjunto(ptr2, i + 10);
  }

  printConjunto(ptr);
  printConjunto(ptr2);

  ptrDiferenca = uniao(ptr, ptr2);
  printConjunto(ptrDiferenca);

  return 0;
}

long menor(CONJUNTO *conjunto)
{
  return conjunto->vetor[0];
}

long maior(CONJUNTO *conjunto)
{
  return conjunto->vetor[conjunto->tam];
}

int testaSeOsConjuntosSaoIguais(CONJUNTO *conjunto1, CONJUNTO *conjunto2)
{
  long tam;
  if ((tam = conjunto1->tam) == conjunto2->tam)
  {
    for (u_long i = 0; i < tam; i++)
    {
      if (conjunto1->vetor[i] != conjunto2->vetor[i])
        return FALSE;
    }
    return TRUE;
  }
  return FALSE;
}

u_long tamanho(CONJUNTO *conjunto)
{
  return conjunto->tam;
}

int isConjuntoVazio(CONJUNTO *conjunto)
{
  if (!conjunto->tam)
  {
    return TRUE;
  }
  return FALSE;
}

void liberaConjunto(CONJUNTO *conj)
{
  free(conj->vetor);
  free(conj);
}

void printConjunto(CONJUNTO *conj)
{
  if (isConjuntoVazio(conj))
  {
    puts("{}");
  }
  else
  {
    for (u_long i = 0; i < conj->tam; i++)
  {
      printf("%ld,", conj->vetor[i]);
    putchar('\n');
  }
  putchar('\n');
}

void isNullPointer(void *ptr, const char *strError)
{
  if (ptr == NULL)
  {
    perror(strError);
    exit(EXIT_FAILURE);
  }
}

// algoritmo copiado para auxiliar mexer com conjunto, não corrigido para tamanho u_long
void insertionSort(long *vector, u_long tam)
{
  for (u_long i = 1; i < tam; i++)
  {
    long key = vector[i];
    long j = i - 1;
    while (j >= 0 && vector[j] > key)
    {
      vector[j + 1] = vector[j];
      j--;
    }
    vector[j + 1] = key;
  }
}
