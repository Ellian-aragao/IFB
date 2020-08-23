#include "removeNPrimeirosItensLista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structExemplo
{
  DADO *arrayDinamico;
  u_long tam;
};

int removeNPrimeirosIntensLista(void *vetor, size_t sizeOfElemento, u_long nElementos, u_long maxElementos)
{
  for (u_long i = nElementos; i > 0; i--)
  {
    void *destino = &(vetor[sizeOfElemento * (i - 1)]),
         *pontoCopia = &(vetor[sizeOfElemento * i]);
    memcpy(destino, pontoCopia, sizeOfElemento);
  }
  return 0;
}

int main(int argc, char const *argv[])
{
  ListaDinamica *listinha = malloc(sizeof(ListaDinamica));
  listinha->arrayDinamico = malloc(5 * sizeof(DADO));
  // listinha->arrayDinamico[0].valor = 0;
  listinha->arrayDinamico[4].valor = 'c';


  char strToPrint[] = "%c, ";
  for (size_t i = 0; i < 5; i++)
  {
    printf(strToPrint, listinha->arrayDinamico[i].valor);
  }
  putchar('\n');
  removeNPrimeirosIntensLista(listinha->arrayDinamico, sizeof(listinha->arrayDinamico->valor), 4, 5);
  for (size_t i = 0; i < 5; i++)
  {
    printf(strToPrint, listinha->arrayDinamico[i].valor);
  }
  putchar('\n');
  return 0;
}
