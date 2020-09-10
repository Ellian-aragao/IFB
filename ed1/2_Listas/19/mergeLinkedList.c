#include "mergeLinkedList.h"

LinkedList *final_list;

static void appendToSort(void *item)
{
  appendLinkedList(final_list, item);
}

int mergeLinkedList(LinkedList *list_final, LinkedList *list_to_merge)
{
  size_t sizeitemlist1 = getSizeofItensLinkedList(list_final);
  if (sizeitemlist1 == getSizeofItensLinkedList(list_to_merge))
  {
    final_list = list_final;
    forEachLinkedList(list_to_merge, appendToSort);
    return true;
  }
  return false;
}

int mergeLinkedListSort(LinkedList *list_final, LinkedList *list_to_merge, int (*compareItens)(void *, void *))
{
  size_t sizeitemlist1 = getSizeofItensLinkedList(list_final);
  if (sizeitemlist1 == getSizeofItensLinkedList(list_to_merge))
  {
    final_list = list_final;
    forEachLinkedList(list_to_merge, appendToSort);
    return sortLinkedList(list_final, compareItens);
  }
  return false;
}
