#include "../../LinkedList/linkedList.h"
#include "removeNPrimeirosItensLinkedList.h"

int removeNPrimeirosItensLinkedList(LinkedList *list, unsigned long quantidadeDeItensParaRemover)
{
  const unsigned long tamList = getTamLinkedList(list);
  for (unsigned long i = 0; i < quantidadeDeItensParaRemover; i++)
    removeFistLinkedList(list);
  if (getTamLinkedList(list) < tamList)
    return 1;
  return 0;
}