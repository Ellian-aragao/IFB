#include "../LinkedList/testInterface/testLinkedListInterface.h"
#include "invertLinkedlist.h"

int main()
{
  LinkedList *l = testCreateLinkedListWithItensInt(10, 0);
  testForEachPrintItensInt(l);
  invertLinkedList(l);
  testForEachPrintItensInt(l);
  destroyLinkedList(l);
  return 0;
}
