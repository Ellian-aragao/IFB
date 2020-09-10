#include "../../LinkedList/linkedList.h"
#include "../../LinkedList/testInterface/testLinkedListInterface.h"
#include "removeNPrimeirosItensLinkedList.h"
#include <stdio.h>

int main()
{
  LinkedList *list = testCreateLinkedListWithItensInt(0, 10);
  testForEachPrintItensInt(list);
  if (removeNPrimeirosItensLinkedList(list, 5))
    puts("removeu");
  else
    puts("erro");
  testForEachPrintItensInt(list);
  destroyLinkedList(list);
  return 0;
}
