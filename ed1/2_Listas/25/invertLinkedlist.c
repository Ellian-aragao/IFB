#include "invertLinkedlist.h"

void invertLinkedList(LinkedList *list)
{
  u_long tamList = getTamLinkedList(list);
  for (u_long i = 0; i < tamList / 2; i++)
  {
    swapItemIndexLinkedList(list, i, tamList - i - 1);
  }
}