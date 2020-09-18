#include "../LinkedList/testInterface/testLinkedListInterface.h"
#include "printList.h"

void printItem(void* item)
{
  printf("%d,",*(int *)item);
}

int main()
{
  LinkedList *l = testCreateLinkedListWithItensInt(0,9);
  printLinkedList(l, printItem);
  destroyLinkedList(l);
  return 0;
}
