#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

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
}

void destroyLinkedList(LinkedList *list)
{
  if (list->tam > 0)
  {
    NodeLinkedList *node = list->nodeInicial;
    while (list->tam-- && node->nextNode != NULL)
    {
      void *nextNode = node->nextNode;
      destroyNodeLinkedList(node);
      node = nextNode;
    }
    free(node);
  }
  free(list);
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

void forEach(LinkedList *list)
{
  NodeLinkedList *node = list->nodeInicial;
  for (u_long i = 0; i < list->tam; i++)
  {
    NodeLinkedList *nextNode = node->nextNode;
    printf("%f ,", *(float *)node->item);
    node = nextNode;
  }
  putchar('\n');
}