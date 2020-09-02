#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct itemListaEncadeada NodeLinkedList;
struct listaDinamicaEncadeada
{
  NodeLinkedList *inicialNode;
  NodeLinkedList *finalNode;
  u_long tam;
};

struct itemListaEncadeada
{
  NodeLinkedList *backNode;
  u_long id;
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
    NodeLinkedList *node = list->inicialNode;
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
  list->inicialNode = node;
  list->finalNode = node;
}

void setNewItemNodeLinkedList(LinkedList *list, NodeLinkedList *newFinalNode)
{
  NodeLinkedList* oldFinalNode = list->finalNode;
  oldFinalNode->nextNode = newFinalNode;
  newFinalNode->backNode = oldFinalNode;
  list->finalNode = newFinalNode;
}

NodeLinkedList *createNodeLinkedList(void *itemOfNode, u_long id)
{
  NodeLinkedList *node = malloc(sizeof(NodeLinkedList));
  isNull(node, "Erro ao criar node ao fim da LinkedList");
  node->backNode = NULL;
  node->nextNode = NULL;
  node->item = itemOfNode;
  node->id = id;
  return node;
}

void appendLinkedList(LinkedList *list, void *ptrAllocatedItem)
{
  NodeLinkedList *nextNode = createNodeLinkedList(ptrAllocatedItem, list->tam);
  if (!list->tam)
    addPrimaryNodeItemLinkedList(list, nextNode);
  else
    setNewItemNodeLinkedList(list, nextNode);
  list->tam++;
}

void *getNodeLinkedList(NodeLinkedList *node)
{
  return node;
}

void *getItemNodeLinkedList(NodeLinkedList *node)
{
  return node->item;
}

void forEach(LinkedList *list, void *(*returnSomething)(NodeLinkedList *), void (*externFunction)(void *))
{
  NodeLinkedList *node = list->inicialNode;
  for (u_long i = 0; i < list->tam; i++)
  {
    NodeLinkedList *nextNode = node->nextNode;
    externFunction(returnSomething(node));
    node = nextNode;
  }
}

void forEachItem(LinkedList *list, void (*externFunction)(void *))
{
  forEach(list, getItemNodeLinkedList, externFunction);
}

void forEachNode(LinkedList *list, void (*externFunction)(void *))
{
  forEach(list, getNodeLinkedList, externFunction);
}

void removeNodeLinkedList(LinkedList *list, NodeLinkedList *node)
{
  isNull(node, "Nó nulo passado para ser removido da LinkedList");
  if (list->tam > 1)
  {
    if (list->inicialNode == node)
    {
      NodeLinkedList *nextNode = node->nextNode;
      list->inicialNode = nextNode;
      nextNode->backNode = NULL;
    }
    else if (list->finalNode == node)
    {
      NodeLinkedList *backNode = node->backNode;
      list->finalNode = backNode;
      backNode->nextNode = NULL;
    }
    else
    {
      NodeLinkedList* backNode = node->backNode;
      NodeLinkedList* nextNode = node->nextNode;
      backNode->nextNode = nextNode;
      nextNode->backNode = backNode;
    }
  }
  else
  {
    list->inicialNode = NULL;
    list->finalNode = NULL;
  }
  list->tam--;
  destroyNodeLinkedList(node);
}

void removeLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *))
{
  isNull(list, "Lista nula passada como argumento para remover item");
  NodeLinkedList *node = list->inicialNode;
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