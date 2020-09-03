#include "removeNPrimeirosItensLista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structExemplo
{
  DADO *arrayDinamico;
  u_long tam;
};

int removeNPrimeirosIntensLista(void *vetor, size_t sizeOfElement, u_long nElementsToRemove, u_long *addressTamVetor)
{
  if (nElementsToRemove < *addressTamVetor)
  {
    u_long i, j;
    for (i = 0, j = nElementsToRemove; j < *addressTamVetor; i++, j++)
    {
      void *elementInitialVector = &(vetor[sizeOfElement * i]),
           *elementToCopy = &(vetor[sizeOfElement * j]);
      memmove(elementInitialVector, elementToCopy, sizeOfElement);
    }
    *addressTamVetor -= nElementsToRemove;
    vetor = realloc(vetor, sizeOfElement * (*addressTamVetor));
    if (vetor != NULL)
      return 1;
  }
  else if (nElementsToRemove == *addressTamVetor)
  {
    *addressTamVetor = 0;
    vetor = realloc(vetor, sizeOfElement);
    if (vetor != NULL)
      return 1;
  }

  return 0;
}

ListaDinamica *createListaDinamica()
{
  ListaDinamica *lista = malloc(sizeof(ListaDinamica));
  lista->arrayDinamico = malloc(sizeof(DADO));
  if (lista == NULL && lista->arrayDinamico == NULL)
  {
    perror("Erro na criação da lista");
    exit(EXIT_FAILURE);
  }
  lista->tam = 0;
  return lista;
}

int removeNprimeirosItensListaDinamica(ListaDinamica *lista, u_long numeroDeItensParaEliminar)
{
  return removeNPrimeirosIntensLista(lista->arrayDinamico, sizeof(DADO), numeroDeItensParaEliminar, &lista->tam);
}

u_long getTamListaDinamica(ListaDinamica lista)
{
  return lista.tam;
}

void appendListaDinamica(ListaDinamica *lista, DADO dadoToAppend)
{
  lista->arrayDinamico = realloc(lista->arrayDinamico, (lista->tam + 1) * sizeof(DADO));
  if (lista->arrayDinamico == NULL)
  {
    perror("Erro na inserção de elemento");
    exit(EXIT_FAILURE);
  }
  lista->arrayDinamico[lista->tam++] = dadoToAppend;
}

/*
void exibeTeste(ListaDinamica *listinha)
{
  char strToPrint[] = "%c, ";
  for (size_t i = 0; i < listinha->tam; i++)
  {
    printf(strToPrint, listinha->arrayDinamico[i].valor);
  }
  putchar('\n');
}

int main(int argc, char const *argv[])
{
  ListaDinamica *listinha = createListaDinamica();
  for (char i = 'a'; i < 'a' + 10; i++)
  {
    DADO a = {i};
    appendListaDinamica(listinha, a);
  }
  exibeTeste(listinha);
  removeNPrimeirosIntensLista(listinha->arrayDinamico, sizeof(DADO), 9, &listinha->tam) ? puts("true") : puts("false");
  exibeTeste(listinha);
  return 0;
}
*/