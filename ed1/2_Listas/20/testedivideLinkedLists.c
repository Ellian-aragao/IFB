#include "divideLinkedLists.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"

int main()
{
  LinkedList *list1 = testCreateLinkedListWithItensInt(0, 20);
  testForEachPrintItensInt(list1);
  LinkedList *dividida = divideLinkedListByN(list1, 9);
  testForEachPrintItensInt(list1);
  testForEachPrintItensInt(dividida);
  destroyLinkedList(list1);
  destroyLinkedList(dividida);
  return 0;
}
