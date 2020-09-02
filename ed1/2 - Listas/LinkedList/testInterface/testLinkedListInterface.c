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

void testRemoveItemLinkedList(LinkedList* list, int valueToRemove)
{
  int *item = malloc(sizeof(int));
  *item = valueToRemove;
  removeLinkedList(list, item, compareItensInt);
}

void testForEachPrintItensInt(LinkedList* list)
{
  putchar('[');
  forEachItem(list, printItemInt);
  puts("]");
}

LinkedList *testCreateLinkedListWithItensInt(int minItem, int maxItem)
{
  if (minItem > maxItem)
  {
    perror("min e max na função testCreateLinkedListWithItensInt inválidos");
    exit(EXIT_FAILURE);
  }

  LinkedList *list = createLinkedList(sizeof(int));
  int *item;
  for (int i = minItem; i <= maxItem; i++)
  {
    item = malloc(sizeof(int));
    if (item == NULL)
    {
      perror("erro na alocação do item para criar linkedlist");
      exit(EXIT_FAILURE);
    }
    *item = i;
    appendLinkedList(list, item);
    free(item);
  }
  return list;
}