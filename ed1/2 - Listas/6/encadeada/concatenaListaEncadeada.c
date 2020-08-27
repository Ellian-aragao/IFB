#include "concatenaListaEncadeada.h"
#include "../../sequencial/linkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct structExemplo
{
  DADO *arrayDinamico;
  u_long tam;
};

ListaDinamica *concatenaListaDinamica(ListaDinamica *lista1, ListaDinamica *lista2)
{
  ListaDinamica *listaConcatenada = malloc(sizeof(ListaDinamica));
  listaConcatenada->arrayDinamico = malloc((lista1->tam + lista2->tam) * sizeof(DADO));
  if (listaConcatenada == NULL || listaConcatenada->arrayDinamico == NULL)
  {
    perror("Erro na criação da lista concatenada");
    exit(EXIT_FAILURE);
  }
  for (u_long i = 0; i < lista1->tam; i++)
  {
    listaConcatenada->arrayDinamico[i] = lista1->arrayDinamico[i];
  }
  for (u_long i = lista1->tam; i < lista1->tam + lista2->tam; i++)
  {
    listaConcatenada->arrayDinamico[i] = lista2->arrayDinamico[i];
  }
  return listaConcatenada;
}
