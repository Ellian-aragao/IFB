#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void printItem(void *item)
{
  printf("%f ,", *(float *)item);
}

int compareItens(void *item1, void *item2)
{
  if (*(float*)item1 == *(float*)item2)
    return 1;
  return 0;
}

int main()
{
  LinkedList *list = createLinkedList();
  float *item = malloc(sizeof(float));
  *item = 2.7182;
  appendLinkedList(list, item);
  float *item2 = malloc(sizeof(float));
  *item2 = 3.141592;
  appendLinkedList(list, item2);
  forEach(list, printItem);
  putchar('\n');
  removeLinkedList(list, item, compareItens);
  removeLinkedList(list, item, compareItens);
  forEach(list, printItem);
  putchar('\n');
  destroyLinkedList(list);
  return 0;
}
