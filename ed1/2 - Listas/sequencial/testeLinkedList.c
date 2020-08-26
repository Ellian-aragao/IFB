#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main()
{
  LinkedList *list = createLinkedList();
  float *item = malloc(sizeof(float));
  *item = 3.141592;
  appendLinkedList(list, item);
  float *item2 = malloc(sizeof(float));
  *item2 = 2.7182;
  appendLinkedList(list, item2);
  forEach(list);
  destroyLinkedList(list);
  return 0;
}
