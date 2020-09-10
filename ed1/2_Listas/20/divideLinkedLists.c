#include "divideLinkedLists.h"

LinkedList *divideLinkedListByN(LinkedList *list, u_long n)
{
  if (list)
  {
    LinkedList *list2 = createLinkedList(getSizeofItensLinkedList(list));
    for (u_long i = getTamLinkedList(list); i > n; i--)
    {
      void* addr = getLastItemLinkedList(list);
      appendLinkedList(list2, addr);
      removeLastItemLinkedList(list);
    }
    return list2;
  }
  return NULL;
}
