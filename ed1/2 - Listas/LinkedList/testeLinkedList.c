#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "testInterface/testLinkedListInterface.h"

int main()
{
  LinkedList *list = testCreateLinkedListWithItensInt(-10, 10);
  testForEachPrintItensInt(list);
  testFindItemIndex(list, 20);
  for (size_t i = 0; i < 4; i++)
    testRemoveItemLinkedList(list, i);
  testForEachPrintItensInt(list);
  destroyLinkedList(list);
  return 0;
}
