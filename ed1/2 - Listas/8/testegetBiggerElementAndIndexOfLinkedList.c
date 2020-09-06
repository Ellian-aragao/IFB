#include "../LinkedList/linkedList.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"
#include "getBiggerElementAndIndexOfLinkedList.h"
#include <stdio.h>

int compare(void *item1, void *item2)
{
  if (*(int *)item1 > *(int *)item1)
    return 1;
  return 0;
}

int main(int argc, char const *argv[])
{
  LinkedList *list = testCreateLinkedListWithItensInt(10, 20);
  testForEachPrintItensInt(list);
  u_long index;
  void *item;
  if (getBiggerElementAndIndexOfLinkedList(list, &index, &item, compare))
  {
    printf("index '%ld', item '%d'\n", index, *(int *)item);
  }
  else
  {
    puts("encontrei");
  }
  return 0;
}
