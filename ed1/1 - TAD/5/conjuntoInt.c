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

CONJUNTO *finalizaCopiaParaUniao(CONJUNTO *conjuntoUniao, CONJUNTO *aFinalizar, unsigned long indice)
{
  while (indice < aFinalizar->tam)
    conjuntoUniao = insere(conjuntoUniao, aFinalizar->vetor[indice++]);
  return conjuntoUniao;
}

void printConjunto(CONJUNTO *conj)
{
  for (unsigned long i = 0; i < conj->tam; i++)
  {
    printf("%ld,", conj->vetor[i]);
  }
}

CONJUNTO *uniao(CONJUNTO *conj1, CONJUNTO *conj2)
{
  CONJUNTO *uniaoConjuntos = criaConjuntoVazio();
  unsigned long i, tam = conj1->tam < conj2->tam ? conj1->tam : conj2->tam;
  for (i = 0; i < tam; i++)
  {
    uniaoConjuntos = insere(uniaoConjuntos, conj1->vetor[i]);
    uniaoConjuntos = insere(uniaoConjuntos, conj2->vetor[i]);
  }
  uniaoConjuntos = (conj1->tam > conj2->tam ? finalizaCopiaParaUniao(uniaoConjuntos, conj1, i) : finalizaCopiaParaUniao(uniaoConjuntos, conj2, i));
  return uniaoConjuntos;
}

CONJUNTO *removeItemConjunto(CONJUNTO *conj, long itemRetirar)
{
  unsigned long index;
  if (testaSePertence(conj, itemRetirar, &index))
  {
    while (index < conj->tam)
    {
      conj->vetor[index] = conj->vetor[index + 1];
      index++;
    }
    long *tmp = realloc(conj->vetor, (--conj->tam) * sizeof(long));
    if (tmp == NULL)
    {
      fprintf(stderr, "Erro na remoção do item '%ld' no conjunto\n", itemRetirar);
      return NULL;
    }
    conj->vetor = tmp;
    return conj;
  }
  return NULL;
}

CONJUNTO *interseccao(CONJUNTO *conj1, CONJUNTO *conj2)
{
  CONJUNTO *interseccaoConjuntos = criaConjuntoVazio();

  for (unsigned long i = 0; i < conj1->tam; i++)
  {
    if (testaSePertence(conj2, conj1->vetor[i], NULL))
      insere(interseccaoConjuntos, conj1->vetor[i]);
  }

  if (interseccaoConjuntos->tam == 0)
  {
    perror("Não existe interseccao entre os conjuntos\n");
    liberaConjunto(interseccaoConjuntos);
    return NULL;
  }
  return interseccaoConjuntos;
}

// CONJUNTO* diferenca() {}

// tentativa de algoritmo bisseccao baseado em calculo numérico 2ºsem 2019
int testaSePertence(CONJUNTO *conjunto, long numeroProcurado, unsigned long *index)
{
  unsigned long
      limiteInferior = 0,
      LimiteSuperior = conjunto->tam,
      mediana = (unsigned long)1 + conjunto->tam / 2;

  if (conjunto->vetor[0] > numeroProcurado || conjunto->vetor[conjunto->tam] < numeroProcurado)
    return FALSE;

  while (TRUE)
  {
    printf("%ld %ld %ld --> %ld\n", limiteInferior, mediana, LimiteSuperior, numeroProcurado);
    getchar();
    if (numeroProcurado < conjunto->vetor[mediana])
    {
      puts("encontrado");
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
    else if ((limiteInferior + 1) == LimiteSuperior)
      return FALSE;
    mediana = (unsigned long)limiteInferior + (LimiteSuperior - limiteInferior) / 2;
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

int testaSeOsConjuntosSaoIguais(CONJUNTO *conjunto1, CONJUNTO *conjunto2)
{
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

unsigned long tamanho(CONJUNTO *conjunto)
{
  return conjunto->tam;
}

int testaSeoConjuntoVazio(CONJUNTO *conjunto)
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

int main(int argc, char const *argv[])
{
  CONJUNTO *ptr = criaConjuntoVazio(),
           *ptr2 = criaConjuntoVazio();

  for (long i = 0; i < 5; i++)
  {
    ptr = insere(ptr, i);
    ptr2 = insere(ptr2, i + 2);
  }

  printConjunto(ptr);
  putchar('\n');

  printConjunto(ptr2);
  putchar('\n');

  printConjunto(interseccao(ptr, ptr2));
  putchar('\n');

  return 0;
}
