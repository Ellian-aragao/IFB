#include "printList.h"

typedef struct itemListaEncadeada NodeLinkedList;

struct listaDinamicaEncadeada
{
  NodeLinkedList *inicialNode;
  NodeLinkedList *finalNode;
  size_t sizeofItens;
  u_long tam;
};

struct itemListaEncadeada
{
  NodeLinkedList *backNode;
  void *item;
  NodeLinkedList *nextNode;
};

void percorrePrintando(NodeLinkedList *n, void (*printerFunction)(void *))
{
  if (n->nextNode != NULL)
  {
    printerFunction(n->item);
    percorrePrintando(n->nextNode, printerFunction);
  }
  else if (n != NULL)
  {
    printerFunction(n->item);
  }
}

void printLinkedList(LinkedList *list, void (*printFunction)(void *))
{
  NodeLinkedList *n = list->inicialNode;
  percorrePrintando(n,printFunction);
}