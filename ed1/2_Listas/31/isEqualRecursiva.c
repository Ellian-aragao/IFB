#include "isEqualRecursiva.h"

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

bool isEqual(NodeLinkedList *n1, NodeLinkedList *n2, size_t *size_of_itens)
{
  if (n1->nextNode && n2->nextNode)
    return !memcmp(n1->item, n2->item, *size_of_itens) && isEqual(n1->nextNode, n2->nextNode, size_of_itens);
  else if (n1->nextNode || n2->nextNode)
    return false;
  return !memcmp(n1->item, n2->item, *size_of_itens);
}

bool isEqualRecursiva(LinkedList *l1, LinkedList *l2)
{
  return isEqual(l1->inicialNode, l2->inicialNode, &(l1->sizeofItens));
}