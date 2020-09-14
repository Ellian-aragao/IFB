#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "testInterface/testLinkedListInterface.h"

int compareItensInt1Major(void *item1, void *item2)
{
  if (*(int *)item1 > *(int *)item2)
    return 1;
  return 0;
}

int main()
{
  LinkedList *list = testCreateLinkedListWithItensInt(0, 9),
             *list2 = testCreateLinkedListWithItensInt(0, 9);
  testForEachPrintItensInt(list);
  testForEachPrintItensInt(list2);
  puts(isEqualLinkedLists(list, list2) ? "igual" : "diferente");
  destroyLinkedList(list);
  destroyLinkedList(list2);
  return 0;
}
