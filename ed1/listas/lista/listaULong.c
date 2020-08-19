#include "listaULong.h"
#include <stdio.h>
#include <stdlib.h>

struct conjuntoULong
{
  u_long *vetor;
  u_long tam;
};

listaULong *criaListaULong()
{
  listaULong *ptr = malloc(sizeof(listaULong));
  if (ptr == NULL)
  {
    fprintf(stderr, "erro na criação do conjunto");
    return NULL;
  }
  ptr->vetor = NULL;
  ptr->tam = 0;
  return ptr;
}

void liberaListaULong(listaULong *conj)
{
  free(conj->vetor);
  free(conj);
}

intzinho insereListaUlong(listaULong *conjunto, u_long valorAdicionar)
{
  if (conjunto->tam == 0)
  {
    conjunto->vetor = malloc(sizeof(u_long));
    if (conjunto->vetor == NULL)
    {
      perror("Erro na inserção do primeiro item do conjunto\n");
      return FALSE;
    }
  }
  else
  {
    u_long *tmp = realloc(conjunto->vetor, (conjunto->tam + 1) * sizeof(u_long));
    if (tmp == NULL)
    {
      perror("Erro na inserção de novo item no conjunto\n");
      return FALSE;
    }
    conjunto->vetor = tmp;
  }
  conjunto->vetor[conjunto->tam++] = valorAdicionar;
  return TRUE;
}

u_long multiplicaTodosOsTermos(listaULong *conj)
{
  u_long resultado = 1;
  for (short int i = 0; i < conj->tam; i++)
  {
    resultado *= conj->vetor[i];
  }
  return resultado;
}
