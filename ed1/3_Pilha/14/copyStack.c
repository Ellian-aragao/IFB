#include "copyStack.h"
#include "../PilhaInterface/Stack.h"

void *vectorOfPointers(u_long nItens)
{
	
}

Stack *copyStack(Stack *stack)
{
	size_t sizeOfItens = getSizeofItensOfStack(stack);
	u_long tamStack = getTamStack(stack);
	Stack *stackCopy = createStack(sizeOfItens);
	void *vetorItens = vectorOfPointers(tamStack, sizeOfItens);
	return stackCopy;
}