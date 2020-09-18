#include "equalStacks.h"

static inline void *createVectorOfPointers(u_long *nItens)
{
	void *vector = malloc(*nItens * sizeof(void *));
	if (!vector)
	{
		perror("Erro na alocação de armazenamento dos itens da pilha");
		exit(EXIT_FAILURE);
	}
	return vector;
}

static inline void freeVectorOfPointers(void *vector[], u_long *tamVector)
{
	for (u_long i = 0; i < *tamVector; i++)
		free(vector[i]);
	free(vector);
}

static inline void pushVectorInStack(void *vector[], Stack *stack, u_long *stackTam)
{
	for (u_long i = 0; i < *stackTam; i++)
		pushStack(stack, vector[i]);
}

static inline void **saveStackInVector(Stack *stack, u_long *stackTam)
{
	void **vector = createVectorOfPointers(stackTam);
	for (u_long i = 0; i < *stackTam; i++)
		vector[i] = getPopStack(stack);

	pushVectorInStack(vector, stack, stackTam);

	return vector;
}

static inline bool compareVectors(void **v1, void **v2, const u_long *tamStack, const size_t *sizeOfItens)
{
	for (u_long i = 0; i < *tamStack; i++)
	{
		if (memcmp(v1[i], v2[i], *sizeOfItens))
			return false;
	}
	return true;
}

bool isEqualStacks(Stack *s1, Stack *s2)
{
	bool returnVar = false;
	size_t sizeOfItens = getSizeofItensOfStack(s1);
	u_long tamStack = getTamStack(s1);
	if (sizeOfItens == getSizeofItensOfStack(s2) && tamStack == getTamStack(s2))
	{
		void **vetorItens[2] = {
				saveStackInVector(s1, &tamStack),
				saveStackInVector(s2, &tamStack)};

		returnVar = compareVectors(vetorItens[0], vetorItens[1], &tamStack, &sizeOfItens);

		freeVectorOfPointers(vetorItens[0], &tamStack);
		freeVectorOfPointers(vetorItens[1], &tamStack);
	}
	return returnVar;
}