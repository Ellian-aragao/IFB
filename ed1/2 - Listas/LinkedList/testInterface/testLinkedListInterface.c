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
  int *item = allocIntAndSetValue(&valueToRemove);
  removeLinkedList(list, item, compareItensInt);
  free(item);
}

void testForEachPrintItensInt(LinkedList *list)
{
  putchar('[');
  forEachItem(list, printItemInt);
  puts("]");
}

void testFindItemIndex(LinkedList *list, int itemToFind)
{
  int *item = allocIntAndSetValue(&itemToFind);
  u_long *index = getIndexItemLinkedList(list, item, compareItensInt);
  printf("item to find '%d', his index '%ld'\n", itemToFind, *index);
  free(index);
  free(item);
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