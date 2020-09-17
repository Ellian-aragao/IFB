#include "Stack.h"

u_long getTamStack(Stack *stack)
{
  return getTamLinkedList(stack);
}

size_t getSizeofItensOfStack(Stack *stack)
{
  return getSizeofItensLinkedList(stack);
}

Stack *createStack(size_t sizeofItens)
{
  return createLinkedList(sizeofItens);
}

bool destroyStack(Stack *stack)
{
  return destroyLinkedList(stack);
}

void *pushStack(Stack *stack, void *item)
{
  return appendLinkedList(stack, item);
}

void *getItemStack(Stack *stack)
{
  return getLastItemLinkedList(stack);
}

void popStack(Stack *stack)
{
  removeLastItemLinkedList(stack);
}

void *getPopStack(Stack *stack)
{
  size_t sizeItem = getSizeofItensOfStack(stack);
  void *item = malloc(sizeItem);
  if (!item)
  {
    perror("Erro na alocação do espaço de memória do item");
    exit(EXIT_FAILURE);
  }
  memcpy(item, getItemStack(stack), sizeItem);
  popStack(stack);
  return item;
}