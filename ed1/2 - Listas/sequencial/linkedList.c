#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct itemListaEncadeada NodeLinkedList;
struct listaDinamicaEncadeada
{
  NodeLinkedList *nodeInicial;
  NodeLinkedList *nodeFinal;
  u_long tam;
};

struct itemListaEncadeada
{
  NodeLinkedList *backNode;
  void *item;
  NodeLinkedList *nextNode;
};

void isNull(void *pointer, const char *str)
{
  if (pointer == NULL)
  {
    perror(str);
    exit(EXIT_FAILURE);
  }
}

LinkedList *createLinkedList()
{
  LinkedList *list = malloc(sizeof(LinkedList));
  isNull(list, "Erro na criação da LinkedList");
  return list;
}

void destroyNodeLinkedList(NodeLinkedList *node)
{
  free(node->item);
  free(node);
  node->backNode = NULL;
  node->item = NULL;
  node->nextNode = NULL;
  node = NULL;
}

void destroyLinkedList(LinkedList *list)
{
  if (list->tam > 0)
  {
    NodeLinkedList *node = list->nodeInicial;
    while (list->tam--)
    {
      void *nextNode = node->nextNode;
      destroyNodeLinkedList(node);
      node = nextNode;
    }
    if (node != NULL)
    {
      free(node);
    }
  }
  free(list);
  list = NULL;
}

void addPrimaryNodeItemLinkedList(LinkedList *list, NodeLinkedList *node)
{
  list->nodeInicial = node;
  list->nodeFinal = node;
}

void setNewItemNodeLinkedList(NodeLinkedList *oldFinalNode, NodeLinkedList *newFinalNode)
{
  oldFinalNode->nextNode = newFinalNode;
  newFinalNode->backNode = oldFinalNode;
}

NodeLinkedList *createNodeLinkedList(void *itemOfNode)
{
  NodeLinkedList *node = malloc(sizeof(NodeLinkedList));
  isNull(node, "Erro ao criar node ao fim da LinkedList");
  node->backNode = NULL;
  node->nextNode = NULL;
  node->item = itemOfNode;
  return node;
}

void appendLinkedList(LinkedList *list, void *ptrAllocatedItem)
{
  NodeLinkedList *nextNode = createNodeLinkedList(ptrAllocatedItem);
  if (!list->tam)
    addPrimaryNodeItemLinkedList(list, nextNode);
  else
    setNewItemNodeLinkedList(list->nodeFinal, nextNode);
  list->tam++;
}

void forEach(LinkedList *list, void (*externFunction)(void *))
{
  NodeLinkedList *node = list->nodeInicial;
  for (u_long i = 0; i < list->tam; i++)
  {
    NodeLinkedList *nextNode = node->nextNode;
    externFunction(node->item);
    node = nextNode;
  }
}

void removeNodeLinkedList(LinkedList *list, NodeLinkedList *node)
{
  isNull(list, "Lista nula passada como argumento para remover nó");
  isNull(node, "Nó nulo passado para ser removido da LinkedList");
  if (list->tam > 1)
  {
    if (list->nodeInicial == node)
    {
      NodeLinkedList *nextNode = node->nextNode;
      list->nodeInicial = nextNode;
      nextNode->backNode = NULL;
    }
    else if (list->nodeFinal == node)
    {
      NodeLinkedList *backNode = node->backNode;
      list->nodeFinal = backNode;
      backNode->nextNode = NULL;
    }
  }
  else
  {
    list->nodeInicial = NULL;
    list->nodeFinal = NULL;
  }
  list->tam--;
  destroyNodeLinkedList(node);
}

void removeLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *))
{
  NodeLinkedList *node = list->nodeInicial;
  for (u_long i = 0; i < list->tam; i++)
  {
    NodeLinkedList *nextNode = node->nextNode;
    if (compareItem(node->item, item))
    {
      removeNodeLinkedList(list, node);
      return;
    }
    node = nextNode;
  }
}