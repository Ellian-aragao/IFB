#include <stdio.h>
#include <stdlib.h>
#include "../linkedList.h"

void printItemInt(void *item)
{
  printf("%d,", *(int *)item);
}

static int compareItensInt(void *item1, void *item2)
{
  if (*(int *)item1 == *(int *)item2)
    return 1;
  return 0;
}

int *allocIntAndSetValue(int *value)
{
  int *item = malloc(sizeof(int));
  if (item == NULL)
  {
    perror("Erro na alocação de memória para o item inteiro do teste da linkedList");
    exit(EXIT_FAILURE);
  }
  *item = *value;
  return item;
}

void testRemoveItemLinkedList(LinkedList *list, int valueToRemove)
{
  removeItemLinkedList(list, &valueToRemove, compareItensInt);
}

void testForEachPrintItensInt(LinkedList *list)
{
  putchar('[');
  forEachItem(list, printItemInt);
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