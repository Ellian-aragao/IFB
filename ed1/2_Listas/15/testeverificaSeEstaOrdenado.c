#include "../LinkedList/linkedList.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"
#include "verificaSeEstaOrdenado.h"
#include "stdio.h"

#define voidToInt(ptr) (*(int *)ptr)

int compareItens(void *i1, void *i2)
{
  if (voidToInt(i1) > voidToInt(i2))
    return 1;
  else if (voidToInt(i1) < voidToInt(i2))
    return -1;
  else
    return 0;
}

int main(int argc, char const *argv[])
{
  LinkedList *listInt = testCreateLinkedListWithItensInt(0, 10);
  swapItemIndexLinkedList(listInt, 0, 9);
  puts(verificaSeEstaOrdenado(listInt, compareItens) ? "Está ordenado" : "Não está ordenado");
  return 0;
}
