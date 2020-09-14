#include "linkedListToArray.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"

int main()
{
  LinkedList *linkedlist = testCreateLinkedListWithItensInt(0, 9);
  int *arrayList = linkedToArray(linkedlist);

  testForEachPrintItensInt(linkedlist);
  for (size_t i = 0; i < 10; i++)
    printf("%d,", arrayList[i]);
  putchar('\n');

  destroyLinkedList(linkedlist);
  free(arrayList);
  return 0;
}
