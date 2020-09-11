#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "testInterface/testStackInterface.h"

int compareItensInt1Major(void *item1, void *item2)
{
  if (*(int *)item1 > *(int *)item2)
    return 1;
  return 0;
}

int main()
{
  Stack *list = testCreateLinkedListWithItensInt(10, 0);
  testForEachPrintItensInt(list);
  // swapItemIndexLinkedList(list, 0, 1);
  // testFindItemIndex(list, 10);
  sortLinkedList(list, compareItensInt1Major);
  // for (size_t i = 0; i < 4; i++)
  //   testRemoveItemLinkedList(list, i);
  testForEachPrintItensInt(list);
  destroyStack(list);
  return 0;
}
