#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "testInterface/testLinkedListInterface.h"

int main()
{
  LinkedList *list = testCreateLinkedListWithItensInt(0,5);
  testForEachPrintItensInt(list);
  testRemoveItemLinkedList(list, 2);
  testForEachPrintItensInt(list);
  destroyLinkedList(list);
  return 0;
}
