#include "divideLinkedLists.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"

int main()
{
  LinkedList *list1 = testCreateLinkedListWithItensInt(0, 5);
  testForEachPrintItensInt(list1);
  LinkedList *dividida = divideLinkedListByNProblematic(list1, 2);
  testForEachPrintItensInt(list1);
  testForEachPrintItensInt(dividida);
  destroyLinkedList(list1);
  destroyLinkedList(dividida);
  return 0;
}
