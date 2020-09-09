#include "../../LinkedList/linkedList.h"
#include "../../LinkedList/testInterface/testLinkedListInterface.h"
#include "removeNPrimeirosItensLinkedList.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
  LinkedList *list = testCreateLinkedListWithItensInt(0, 10);
  testForEachPrintItensInt(list);
  if (removeNPrimeirosItensLinkedList(list, 5))
    puts("removeu");
  else
    puts("erro");
  testForEachPrintItensInt(list);
  return 0;
}
