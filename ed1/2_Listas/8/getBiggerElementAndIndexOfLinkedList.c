#include "getBiggerElementAndIndexOfLinkedList.h"

int getBiggerElementAndIndexOfLinkedList(LinkedList *list, u_long *index, void **itemFromNode, int (*compare)(void *, void *))
{
  if ((*index = getTamLinkedList(list)) > 0)
  {
    sortLinkedList(list, compare);
    *itemFromNode = getItemByIndex(list, --(*index));
    return 1;
  }
  return 0;
}