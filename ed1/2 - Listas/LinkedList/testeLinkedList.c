#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void printItem(void *item)
{
  printf("%d ,", *(int *)item);
}

int compareItens(void *item1, void *item2)
{
  if (*(int *)item1 == *(int *)item2)
    return 1;
  return 0;
}

int main()
{
  LinkedList *list = createLinkedList();
  int *item;
  for (int i = 0; i < 5; i++)
  {
    item = malloc(sizeof(int));
    *item = i;
    appendLinkedList(list, item);
  }

  forEachItem(list, printItem);
  putchar('\n');

  removeLinkedList(list, item, compareItens);

  forEachItem(list, printItem);
  putchar('\n');

  destroyLinkedList(list);
  return 0;
}
