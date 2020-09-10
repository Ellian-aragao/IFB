#include "linkedList.h"

#define getBackNode(node) node->backNode
#define getNextNode(node) node->nextNode
#define getItemNode(node) node->item
#define getUlongFromVoid(index) *(u_long *)index
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
  size_t sizeofItens;
  u_long tam;
};

struct itemListaEncadeada
{
  NodeLinkedList *backNode;
  void *item;
  NodeLinkedList *nextNode;
};

static inline int isEqualIndexAndItem(void *indexList, void *indexToFind)
{
  return getUlongFromVoid(indexList) == getUlongFromVoid(indexToFind);
}

static inline void isNullExitFailure(void *pointer, const char *str)
{
  if (!pointer)
  {
    perror(str);
    exit(EXIT_FAILURE);
  }
}

static inline void destroyNodeLinkedList(NodeLinkedList *node)
{
  free(node->item);
  free(node);
  node->backNode = NULL;
  node->item = NULL;
  node->nextNode = NULL;
  node = NULL;
}

static inline void addPrimaryNodeItemLinkedList(LinkedList *list, NodeLinkedList *node)
{
  list->inicialNode = node;
  list->finalNode = node;

  node->backNode = NULL;
  node->nextNode = NULL;
}

static inline void setNewItemNodeLinkedList(LinkedList *list, NodeLinkedList *newFinalNode)
{
  NodeLinkedList *oldFinalNode = list->finalNode;
  oldFinalNode->nextNode = newFinalNode;
  newFinalNode->backNode = oldFinalNode;
  list->finalNode = newFinalNode;
}

static inline NodeLinkedList *createNodeLinkedList(LinkedList *list, void *itemOfNode)
{
  NodeLinkedList *node = malloc(sizeof(NodeLinkedList));
  node->item = malloc(list->sizeofItens);
  isNullExitFailure(node, "Erro ao criar node ao fim da LinkedList");
  isNullExitFailure(getItemNode(node), "Erro ao criar item");
  memcpy(getItemNode(node), itemOfNode, list->sizeofItens);
  return node;
}

static inline bool isInitialOrFinalNodeInLinkedListRemove(LinkedList *list, NodeLinkedList *node)
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

static inline void removeNodeBetweenNodesInLinkedList(NodeLinkedList *node)
{
  NodeLinkedList *backNode = getBackNode(node);
  NodeLinkedList *nextNode = getNextNode(node);
  backNode->nextNode = nextNode;
  nextNode->backNode = backNode;
}

static void removeNodeLinkedList(LinkedList *list, NodeLinkedList *node)
{
  isNullExitFailure(node, "Nó nulo passado para ser removido da LinkedList");
  if (list->tam == 1)
  {
    list->inicialNode = NULL;
    list->finalNode = NULL;
  }
  else if (!isInitialOrFinalNodeInLinkedListRemove(list, node))
  {
    removeNodeBetweenNodesInLinkedList(node);
  }
  list->tam--;
  destroyNodeLinkedList(node);
}

static inline bool nodeHasItemRemoveNode(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (compareItem(getItemNode(node), item))
  {
    removeNodeLinkedList(list, node);
    *addressToSaveArgument = index;
    return true;
  }
  return false;
}

static void *forEachReturnIfFind(
    LinkedList *list,
    bool (*returnTrueToEndSuperFunction)(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *genericPointer, int (*compareItem)(void *, void *)),
    void *genericItem, int (*compareItem)(void *, void *))
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

static void *forEachReturnIfFindWithoutLinkedList(
    LinkedList *list,
    bool (*returnTrueToEndSuperFunction)(NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *genericPointer, int (*compareItem)(void *, void *)),
    void *genericItem, int (*compareItem)(void *, void *))
{
  isNullExitFailure(list, "Lista nula passada como argumento para remover item");
  NodeLinkedList *node = list->inicialNode;
  for (u_long i = 0; i < list->tam; i++)
  {
    NodeLinkedList *nextNode = getNextNode(node);

    void *addressToGiveToSuperFunction = NULL;
    if (returnTrueToEndSuperFunction(node, &i, &addressToGiveToSuperFunction, genericItem, compareItem))
      return addressToGiveToSuperFunction;

    node = nextNode;
  }
  return NULL;
}

static inline bool indexNodeisEqualItemRemoveNode(LinkedList *list, NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareIndexAndItem)(void *, void *))
{
  bool findItem = false;
  if (compareIndexAndItem(index, item))
  {
    removeNodeLinkedList(list, node);
    findItem = true;
    *addressToSaveArgument = &findItem;
  }
  return findItem;
}

static inline bool findItemFromIndexToReturnFunction(NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareIndexAndItem)(void *, void *))
{
  if (compareIndexAndItem(index, item))
  {
    *addressToSaveArgument = getItemNode(node);
    return true;
  }
  return false;
}

static inline bool setIndexToReturnFunction(NodeLinkedList *node, u_long *index, void **addressToSaveArgument, void *item, int (*compareItem)(void *, void *))
{
  if (compareItem(getItemNode(node), item))
  {
    *addressToSaveArgument = index;
    return true;
  }
  return false;
}

u_long getTamLinkedList(LinkedList *list)
{
  return list->tam;
}

size_t getSizeofItensLinkedList(LinkedList *list)
{
  return list->sizeofItens;
}

LinkedList *createLinkedList(size_t sizeofItens)
{
  LinkedList *list = malloc(sizeof(LinkedList));
  isNullExitFailure(list, "Erro na criação da LinkedList");
  list->sizeofItens = sizeofItens;
  return list;
}

int destroyLinkedList(LinkedList *list)
{
  if (list)
  {
    if (list->tam > 0)
      for (NodeLinkedList *node = list->inicialNode; list->tam > 0; list->tam--)
      {
        void *nextNode = getNextNode(node);
        destroyNodeLinkedList(node);
        node = nextNode;
      }
    free(list);
    list = NULL;
    return true;
  }
  return false;
}

void *appendLinkedList(LinkedList *list, void *ptrAllocatedItem)
{
  if (list)
  {
    NodeLinkedList *lastNode = createNodeLinkedList(list, ptrAllocatedItem);
    if (!list->tam)
      addPrimaryNodeItemLinkedList(list, lastNode);
    else
      setNewItemNodeLinkedList(list, lastNode);
    list->tam++;
    return getItemNode(lastNode);
  }
  return NULL;
}

void forEachLinkedList(LinkedList *list, void (*externFunction)(void *))
{
  NodeLinkedList *node = list->inicialNode;
  for (u_long i = 0; i < list->tam; i++)
  {
    NodeLinkedList *nextNode = getNextNode(node);
    externFunction(getItemNode(node));
    node = nextNode;
  }
}

u_long removeItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *))
{
  return getUlongFromVoid(forEachReturnIfFind(list, nodeHasItemRemoveNode, item, compareItem));
}

bool removeIndexLinkedList(LinkedList *list, u_long index)
{
  return (bool *)forEachReturnIfFind(list, indexNodeisEqualItemRemoveNode, &index, isEqualIndexAndItem);
}

void *getItemByIndex(LinkedList *list, u_long index)
{
  return forEachReturnIfFindWithoutLinkedList(list, findItemFromIndexToReturnFunction, &index, isEqualIndexAndItem);
}

void removeFistLinkedList(LinkedList *list)
{
  removeNodeLinkedList(list, list->inicialNode);
}

void removeLastLinkedList(LinkedList *list)
{
  removeNodeLinkedList(list, list->finalNode);
}

u_long *getIndexItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *))
{
  return forEachReturnIfFindWithoutLinkedList(list, setIndexToReturnFunction, item, compareItem);
}

bool swapItemIndexLinkedList(LinkedList *list, u_long index1, u_long index2)
{
  if (index1 < list->tam && index2 < list->tam)
  {
    NodeLinkedList *node1 = getItemByIndex(list, index1);
    NodeLinkedList *node2 = getItemByIndex(list, index2);
    swapNodeItem(getItemNode(node1), getItemNode(node2));
    return true;
  }
  return false;
}

bool sortLinkedList(LinkedList *list, int (*compareItens)(void *, void *))
{
  if (list)
  {
    for (u_long tamList = list->tam; 0 < tamList; tamList--)
    {
      NodeLinkedList *nodei = list->inicialNode;
      NodeLinkedList *nodej = getNextNode(list->inicialNode);
      for (u_long j = 1; j < tamList; j++)
      {
        if (compareItens(getItemNode(nodei), getItemNode(nodej)))
          swapNodeItem(getItemNode(nodei), getItemNode(nodej));

        nodei = getNextNode(nodei);
        nodej = getNextNode(nodej);
      }
    }
    return true;
  }
  return false;
}

bool isItensInLinkedListSorted(LinkedList *list, int (*compareItens)(void *, void *))
{
  NodeLinkedList *nodei = list->inicialNode;
  NodeLinkedList *nodej = getNextNode(list->inicialNode);
  int crescenteOuDecresente = compareItens(getItemNode(nodei), getItemNode(nodej));
  for (u_long i = 0; i < list->tam - 1; i++)
  {
    if (compareItens(getItemNode(nodei), getItemNode(nodej)) != crescenteOuDecresente)
      return false;

    nodei = getNextNode(nodei);
    nodej = getNextNode(nodej);
  }
  return true;
}

bool removeEqualsItens(LinkedList *list, int (*compareItens)(void *, void *))
{
  if (list)
  {
    for (u_long i = 0; i < list->tam; i++)
    {
      void *itemI = getItemByIndex(list, i);
      for (u_long j = i + 1; j < list->tam; j++)
      {
        void *itemJ = getItemByIndex(list, j);
        if (compareItens(itemI, itemJ))
          removeIndexLinkedList(list, j--);
      }
    }
    return true;
  }
  return false;
}