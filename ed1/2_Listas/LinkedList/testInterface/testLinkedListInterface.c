#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"

void printItemInt(void *item)
{
  printf("%d,", *(int *)item);
}

int compareItensInt(void *item1, void *item2)
{
  if (*(int *)item1 == *(int *)item2)
    return 1;
  return 0;
}

void testRemoveItemLinkedList(LinkedList *list, int valueToRemove)
{
  removeItemLinkedList(list, &valueToRemove, compareItensInt);
}

void testForEachPrintItensInt(LinkedList *list)
{
  putchar('[');
  forEachLinkedList(list, printItemInt);
  puts("]");
}

void testFindItemIndex(LinkedList *list, int itemToFind)
{
  u_long *index = getIndexItemLinkedList(list, &itemToFind, compareItensInt);
  if (index != NULL)
    printf("item to find '%d', his index '%ld'\n", itemToFind, *index);
  else
    puts("404 item not found");
}

LinkedList *testCreateLinkedListWithItensInt(int value1, int value2)
{
  LinkedList *list = createLinkedList(sizeof(int));
  
  if (value1 <= value2)
    for (int i = value1; i <= value2; i++)
      appendLinkedList(list, &i);
  else
    for (int i = value1; i >= value2; i--)
      appendLinkedList(list, &i);

  return list;
}