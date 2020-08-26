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
  list->nodeInicial = malloc(sizeof(NodeLinkedList));
  list->nodeFinal = list->nodeInicial;
  const char error[] = "Erro na criação da LinkedList";
  isNull(list, error);
  isNull(list->nodeInicial, error);
  return list;
}

void destroyNodeLinkedList(NodeLinkedList* node)
{
  free(node->item);
  free(node);
}

void destroyLinkedList(LinkedList* list)
{
  NodeLinkedList* pointer = list->nodeInicial;
  for (u_long i = 0; i < list->tam; i++)
  {
    void* nextNode = pointer->nextNode;
    destroyNodeLinkedList(pointer);
  }
  free(list);
}



int main(int argc, char const *argv[])
{
  
  return 0;
}
