#include "copyLinkedList.h"
#include "../LinkedList/linkedList.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"

int main()
{
  LinkedList *list1 = testCreateLinkedListWithItensInt(0, 9),
             *list2 = copyLinkedList(list1);
  testForEachPrintItensInt(list1);
  testForEachPrintItensInt(list2);
  destroyLinkedList(list1);
  destroyLinkedList(list2);
  return 0;
}
