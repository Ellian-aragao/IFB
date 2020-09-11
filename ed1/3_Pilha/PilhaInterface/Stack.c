#include "Stack.h"

#define getBackNode(node) node->backNode
#define getNextNode(node) node->nextNode
#define getItemNode(node) node->item

typedef struct itemListaEncadeada NodeStack;

struct listaDinamicaEncadeada
{
  NodeStack *inicialNode;
  NodeStack *finalNode;
  size_t sizeofItens;
  u_long tam;
};

struct itemListaEncadeada
{
  NodeStack *backNode;
  void *item;
  NodeStack *nextNode;
};

static inline void isNullExitFailure(void *pointer, const char *str)
{
  if (!pointer)
  {
    perror(str);
    exit(EXIT_FAILURE);
  }
}

static inline void destroyNodeStack(NodeStack *node)
{
  free(node->item);
  free(node);
}

static inline void addPrimaryNodeItemStack(Stack *stack, NodeStack *node)
{
  stack->inicialNode = node;
  stack->finalNode = node;

  node->backNode = NULL;
  node->nextNode = NULL;
}

static inline void setNewItemNodeStack(Stack *stack, NodeStack *newFinalNode)
{
  NodeStack *oldFinalNode = stack->finalNode;
  oldFinalNode->nextNode = newFinalNode;
  newFinalNode->backNode = oldFinalNode;
  stack->finalNode = newFinalNode;
}

static inline NodeStack *createNodeStack(Stack *stack, void *itemOfNode)
{
  NodeStack *node = malloc(sizeof(NodeStack));
  node->item = malloc(stack->sizeofItens);
  isNullExitFailure(node, "Erro ao criar node da Stack");
  isNullExitFailure(getItemNode(node), "Erro ao criar item");
  memcpy(getItemNode(node), itemOfNode, stack->sizeofItens);
  return node;
}

static void removeNodeStack(Stack *stack, NodeStack *node)
{
  isNullExitFailure(node, "Nó nulo passado para ser removido da Stack");
  if (stack->tam == 1)
  {
    stack->inicialNode = NULL;
    stack->finalNode = NULL;
  }
  stack->finalNode = getBackNode(node);
  stack->finalNode->nextNode = NULL;
  stack->tam--;
  destroyNodeStack(node);
}

u_long getTamStack(Stack *stack)
{
  return stack->tam;
}

size_t getSizeofItensOfStack(Stack *stack)
{
  return stack->sizeofItens;
}

Stack *createStack(size_t sizeofItens)
{
  Stack *stack = malloc(sizeof(Stack));
  isNullExitFailure(stack, "Erro na criação da Stack");
  stack->sizeofItens = sizeofItens;
  return stack;
}

bool destroyStack(Stack *stack)
{
  if (stack)
  {
    if (stack->tam > 0)
      for (NodeStack *node = stack->inicialNode; stack->tam > 0; stack->tam--)
      {
        void *nextNode = getNextNode(node);
        destroyNodeStack(node);
        node = nextNode;
      }
    free(stack);
    stack = NULL;
    return true;
  }
  return false;
}

void *pushStack(Stack *stack, void *ptrAllocatedItem)
{
  if (stack)
  {
    NodeStack *lastNode = createNodeStack(stack, ptrAllocatedItem);
    if (!stack->tam)
      addPrimaryNodeItemStack(stack, lastNode);
    else
      setNewItemNodeStack(stack, lastNode);
    stack->tam++;
    return getItemNode(lastNode);
  }
  return NULL;
}

void *getItemStack(Stack *stack)
{
  return getItemNode(stack->finalNode);
}

void popStack(Stack *stack)
{
  removeNodeStack(stack, stack->finalNode);
}
