#include "somaValores.h"

static int somatorio = 0;

void somatorioFunc(void *i)
{
  somatorio += *(int *)i;
}

int somaInteiros(LinkedList *list)
{
  forEachLinkedList(list, somatorioFunc);
  return somatorio;
}