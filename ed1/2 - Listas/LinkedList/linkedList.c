#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define getBackNode(node) node->backNode
#define getNextNode(node) node->nextNode
#define getItemNode(node) node->item
#define isEqualIndexAndItem(index, item) *index == *(u_long *)item
#define swapNodeItem(item1, item2) \
  {                                \
    void *tmp;                     \
    tmp = item1;                   \
    item1 = item2;                 \
    item2 = tmp;                   \
  }

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

void isNullExitFailure(void *pointer, const char *str)
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
  isNullExitFailure(list, "Erro na criação da LinkedList");
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
      void *nextNode = getNextNode(node);
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
  isNullExitFailure(node, "Erro ao criar node ao fim da LinkedList");
  isNullExitFailure(getItemNode(node), "Erro ao criar item");
  memcpy(getItemNode(node), itemOfNode, list->sizeofItens);
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
    NodeLinkedList *nextNode = getNextNode(node);
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
    NodeLinkedList *nextNode = getNextNode(node);
    list->inicialNode = nextNode;
    nextNode->backNode = NULL;
    boolean = true;
  }
  else if (list->finalNode == node)
  {
    NodeLinkedList *backNode = getBackNode(node);
    list->finalNode = backNode;
    backNode->nextNode = NULL;
    boolean = true;
  }
  return boolean;
}

void removeNodeBetweenNodesInLinkedList(NodeLinkedList *node)
{
  NodeLinkedList *backNode = getBackNode(node);
  NodeLinkedList *nextNode = getNextNode(node);
  backNode->nextNode = nextNode;
  nextNode->backNode = backNode;
}

void removeNodeLinkedList(LinkedList *list, NodeLinkedList *node)
{
  isNullExitFailure(node, "Nó nulo passado para ser removido da LinkedList");
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
    bool (*returnTrueToEndSuperFunction)(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *genericPointer, int (*compareItem)(void *, void *)),
    void *genericItem,
    int (*compareItem)(void *, void *))
{
  isNullExitFailure(list, "Lista nula passada como argumento para remover item");
  NodeLinkedList *node = list->inicialNode;
  for (u_long i = 0; i < list->tam; i++)
  {
    NodeLinkedList *nextNode = getNextNode(node);

    void *addressToGiveToSuperFunction = NULL;
    if (returnTrueToEndSuperFunction(list, node, &i, &addressToGiveToSuperFunction, genericItem, compareItem))
      return addressToGiveToSuperFunction;

    node = nextNode;
  }
  return NULL;
}

bool nodeHasItemRemoveNode(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (compareItem(getItemNode(node), item))
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

bool indexNodeisEqualItemRemoveNode(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (isEqualIndexAndItem(index, item))
  {
    removeNodeLinkedList(list, node);
    return true;
  }
  return false;
}

void removeIndexLinkedList(LinkedList *list, u_long index)
{
  int (*null)(void *, void *);
  forEachReturnIfFind(list, indexNodeisEqualItemRemoveNode, &index, null);
}

bool findItemFromIndexToReturnFunction(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (isEqualIndexAndItem(index, item))
  {
    *addressToSaveArgument = getItemNode(node);
    return true;
  }
  return false;
}

void *getItemByIndex(LinkedList *list, u_long index)
{
  int (*null)(void *, void *);
  return forEachReturnIfFind(list, findItemFromIndexToReturnFunction, &index, null);
}

void removeFistLinkedList(LinkedList *list)
{
  removeNodeLinkedList(list, list->inicialNode);
}

void removeLastLinkedList(LinkedList *list)
{
  removeNodeLinkedList(list, list->finalNode);
}

bool setIndexToReturnFunction(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (compareItem(getItemNode(node), item))
  {
    *addressToSaveArgument = index;
    return true;
  }
  return false;
}

u_long *getIndexItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *))
{
  return forEachReturnIfFind(list, setIndexToReturnFunction, item, compareItem);
}

bool setNodeToReturnFunction(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (isEqualIndexAndItem(index, item))
  {
    *addressToSaveArgument = node;
    return true;
  }
  return false;
}

int swapItemIndexLinkedList(LinkedList *list, u_long index1, u_long index2)
{
  if (index1 <= list->tam && index2 <= list->tam)
  {
    int (*null)(void *, void *);
    NodeLinkedList *node1 = forEachReturnIfFind(list, setNodeToReturnFunction, &index1, null);
    NodeLinkedList *node2 = forEachReturnIfFind(list, setNodeToReturnFunction, &index2, null);
    swapNodeItem(getItemNode(node1), getItemNode(node2));
    return true;
  }
  return false;
}

void sortLinkedList(LinkedList *list, int (*compareItens)(void *, void *))
{
  u_long tamList = list->tam;
  while (0 < tamList--)
  {
    NodeLinkedList *nodei = list->inicialNode;
    NodeLinkedList *nodej = getNextNode(list->inicialNode);
    for (u_long j = 0; j < tamList; j++)
    {
      if (compareItens(getItemNode(nodei), getItemNode(nodej)))
        swapNodeItem(getItemNode(nodei), getItemNode(nodej));

      nodei = getNextNode(nodei);
      nodej = getNextNode(nodej);
    }
  }
}