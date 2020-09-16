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
