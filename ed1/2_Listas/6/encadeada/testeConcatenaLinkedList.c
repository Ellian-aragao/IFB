#include "concatenaLinkedList.h"
#include "../../LinkedList/linkedList.h"
#include "../../LinkedList/testInterface/testLinkedListInterface.h"

int main()
{
  LinkedList *listas[3] = {
      testCreateLinkedListWithItensInt(0, 9),
      testCreateLinkedListWithItensInt(10, 20),
      concatenaLinkedList(listas[0], listas[1])};

  for (int i = 0; i < 3; i++)
    testForEachPrintItensInt(listas[i]);

  for (int i = 0; i < 14; i++)
    testRemoveItemLinkedList(listas[2], i);

  testForEachPrintItensInt(listas[2]);

  for (int i = 0; i < 3; i++)
    destroyLinkedList(listas[i]);

  return 0;
}
