#include "inverteLinkedList.h"
#include "../LinkedList/testInterface/testLinkedListInterface.h"

int main()
{
  LinkedList *list1 = testCreateLinkedListWithItensInt(0, 10);
  LinkedList *inversa = retornaListaInversa(list1);
  testForEachPrintItensInt(list1);
  testForEachPrintItensInt(inversa);
  destroyLinkedList(list1);
  destroyLinkedList(inversa);
  return 0;
}
