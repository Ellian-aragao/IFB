#include "divideLinkedLists.h"

LinkedList *global;
u_long indexNumber = 0;
u_long n_da_funcao;

void saveAtIndex(void *item)
{
  if (n_da_funcao < indexNumber)
  {
    appendLinkedList(global, item);
  }
  indexNumber++;
}

LinkedList *divideLinkedListByN(LinkedList *list, const u_long n)
{
  if (list)
  {
    n_da_funcao = n;
    LinkedList *list2 = createLinkedList(getSizeofItensLinkedList(list));
    global = list2;
    forEachLinkedList(list, saveAtIndex);

    for (u_long i = getTamLinkedList(list); i > n; i--)
    {
      // void* addr = getLastItemLinkedList(list);
      // appendLinkedList(list2, addr);
      removeLastItemLinkedList(list);
    }
    return list2;
  }
  return NULL;
}
