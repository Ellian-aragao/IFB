#include "copyStack.h"
#include "../PilhaInterface/Stack.h"

static inline void *createVectorOfPointers(u_long nItens)
{
	void *vector = malloc(nItens * sizeof(void *));
	if (!vector)
	{
		perror("Erro na alocação de armazenamento dos itens da pilha");
		exit(EXIT_FAILURE);
	}
	return vector;
}

static inline void freeVectorOfPointers(void *vector[], u_long tamVector)
{
	for (u_long i = 0; i < tamVector; i++)
		free(vector[i]);
	free(vector);
}

static inline void pushVectorInStack(void *vector[], Stack *stack, u_long stackTam)
{
	for (u_long i = 0; i < stackTam; i++)
		pushStack(stack, vector[i]);
}

static inline void **saveStackInVector(Stack *stack, u_long stackTam)
{
	void **vector = createVectorOfPointers(stackTam);
	for (u_long i = 0; i < stackTam; i++)
		vector[i] = getPopStack(stack);
	
	pushVectorInStack(vector, stack, stackTam);

	return vector;
}

Stack *copyStack(Stack *stack)
{
	size_t sizeOfItens = getSizeofItensOfStack(stack);
	u_long tamStack = getTamStack(stack);
	Stack *stackCopy = createStack(sizeOfItens);

	void **vetorItens = saveStackInVector(stack, tamStack);
	pushVectorInStack(vetorItens, stackCopy, tamStack);
	freeVectorOfPointers(vetorItens, tamStack);

	return stackCopy;
}