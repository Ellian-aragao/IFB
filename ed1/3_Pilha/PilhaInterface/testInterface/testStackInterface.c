#include "testStackInterface.h"

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

void testRemoveItemLinkedList(Stack *list, int valueToRemove)
{
  removeItemLinkedList(list, &valueToRemove, compareItensInt);
}

void testForEachPrintItensInt(Stack *list)
{
  putchar('[');
  forEachLinkedList(list, printItemInt);
  puts("]");
}

void testFindItemIndex(Stack *list, int itemToFind)
{
  u_long *index = getIndexItemLinkedList(list, &itemToFind, compareItensInt);
  if (index != NULL)
    printf("item to find '%d', his index '%ld'\n", itemToFind, *index);
  else
    puts("404 item not found");
}

Stack *testCreateLinkedListWithItensInt(int value1, int value2)
{
  Stack *list = createStack(sizeof(int));
  
  if (value1 <= value2)
    for (int i = value1; i <= value2; i++)
      pushStack(list, &i);
  else
    for (int i = value1; i >= value2; i--)
      pushStack(list, &i);

  return list;
}