#include "getTamEncadeadaRecursiva.h"

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

u_long percorre(NodeLinkedList *n)
{
  if (n->nextNode != NULL)
    return 1 + percorre(n->nextNode);
  return 1;
}

u_long getTamEncadeadaRecursiva(LinkedList *list)
{
  return percorre(list->inicialNode);
}