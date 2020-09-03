#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct itemListaEncadeada NodeLinkedList;
struct listaDinamicaEncadeada
{
  NodeLinkedList *inicialNode;
  NodeLinkedList *finalNode;
  u_long sizeofItens;
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

u_long getTamLinkedList(LinkedList *list)
{
  return list->tam;
}

u_long getSizeofItensLinkedList(LinkedList *list)
{
  return list->sizeofItens;
}

LinkedList *createLinkedList(u_long sizeofItens)
{
  LinkedList *list = malloc(sizeof(LinkedList));
  isNull(list, "Erro na criação da LinkedList");
  list->sizeofItens = sizeofItens;
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

  node->backNode = NULL;
  node->nextNode = NULL;
}

void setNewItemNodeLinkedList(LinkedList *list, NodeLinkedList *newFinalNode)
{
  NodeLinkedList *oldFinalNode = list->finalNode;
  oldFinalNode->nextNode = newFinalNode;
  newFinalNode->backNode = oldFinalNode;
  list->finalNode = newFinalNode;
}

NodeLinkedList *createNodeLinkedList(LinkedList *list, void *itemOfNode)
{
  NodeLinkedList *node = malloc(sizeof(NodeLinkedList));
  node->item = malloc(list->sizeofItens);
  isNull(node, "Erro ao criar node ao fim da LinkedList");
  isNull(node->item, "Erro ao criar item");
  memcpy(node->item, itemOfNode, list->sizeofItens);
  return node;
}

void appendLinkedList(LinkedList *list, void *ptrAllocatedItem)
{
  NodeLinkedList *nextNode = createNodeLinkedList(list, ptrAllocatedItem);
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

bool isInitialFinalNodeLinkedListRemove(LinkedList *list, NodeLinkedList *node)
{
  bool boolean = false;
  if (list->inicialNode == node)
  {
    NodeLinkedList *nextNode = node->nextNode;
    list->inicialNode = nextNode;
    nextNode->backNode = NULL;
    boolean = true;
  }
  else if (list->finalNode == node)
  {
    NodeLinkedList *backNode = node->backNode;
    list->finalNode = backNode;
    backNode->nextNode = NULL;
    boolean = true;
  }
  return boolean;
}

void removeNodeBetweenNodesInLinkedList(NodeLinkedList *node)
{
  NodeLinkedList *backNode = node->backNode;
  NodeLinkedList *nextNode = node->nextNode;
  backNode->nextNode = nextNode;
  nextNode->backNode = backNode;
}

void removeNodeLinkedList(LinkedList *list, NodeLinkedList *node)
{
  isNull(node, "Nó nulo passado para ser removido da LinkedList");
  if (list->tam == 1)
  {
    list->inicialNode = NULL;
    list->finalNode = NULL;
  }
  else if (!isInitialFinalNodeLinkedListRemove(list, node))
  {
    removeNodeBetweenNodesInLinkedList(node);
  }
  list->tam--;
  destroyNodeLinkedList(node);
}

void *forEachReturnIfFind(
    LinkedList *list,
    bool (*returnBoolToEndSuperFunction)(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *)),
    void *item,
    int (*compareItem)(void *, void *))
{
  isNull(list, "Lista nula passada como argumento para remover item");
  NodeLinkedList *node = list->inicialNode;
  for (u_long i = 0; i < list->tam; i++)
  {
    NodeLinkedList *nextNode = node->nextNode;

    void *addressToGiveToSuperFunction = NULL;
    if (returnBoolToEndSuperFunction(list, node, &i, &addressToGiveToSuperFunction, item, compareItem))
      return addressToGiveToSuperFunction;

    node = nextNode;
  }
}

bool nodeHasItemRemoveNode(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (compareItem(node->item, item))
  {
    removeNodeLinkedList(list, node);
    return true;
  }
  return false;
}

void removeItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *))
{
  forEachReturnIfFind(list, nodeHasItemRemoveNode, item, compareItem);
}

bool indexNodeisEqualItem(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (*index == *(u_long *)item)
  {
    removeNodeLinkedList(list, node);
    return true;
  }
  return false;
}

void removeIndexLinkedList(LinkedList *list, u_long index)
{
  int (*null)(void *, void *);
  forEachReturnIfFind(list, indexNodeisEqualItem, &index, null);
}

bool setIndexToReturnFunction(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (compareItem(node->item, item))
  {
    u_long *indexAllocated = malloc(sizeof(u_long));
    *indexAllocated = *index;
    *addressToSaveArgument = indexAllocated;
    return true;
  }
  return false;
}

u_long *getIndexItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *))
{
  return forEachReturnIfFind(list, setIndexToReturnFunction, item, compareItem);
}