#include "arrayToLinkedList.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"

int main()
{
  int vetor[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  LinkedList *linkedlist = arrayToLinked(&vetor, 10, sizeof(int));
  testForEachPrintItensInt(linkedlist);
  destroyLinkedList(linkedlist);
  return 0;
}
