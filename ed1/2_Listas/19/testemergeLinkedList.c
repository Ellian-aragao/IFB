#include "mergeLinkedList.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"

int compareItensInt1maior(void *item1, void *item2)
{
  if (*(int *)item1 > *(int *)item2)
    return 1;
  return 0;
}

int main()
{
  LinkedList *list1 = testCreateLinkedListWithItensInt(6, 10),
             *tobemerged = testCreateLinkedListWithItensInt(0, 5);
  testForEachPrintItensInt(list1);
  testForEachPrintItensInt(tobemerged);
  // mergeLinkedList(list1, tobemerged);
  mergeLinkedListSort(list1, tobemerged, compareItensInt1maior);
  testForEachPrintItensInt(list1);
  destroyLinkedList(list1);
  destroyLinkedList(tobemerged);
  return 0;
}
