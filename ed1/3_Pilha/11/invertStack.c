#include "invertStack.h"

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
  return vector;
}

Stack *newInvertStack(Stack *s1)
{
  Stack *nS1 = createStack(getSizeofItensOfStack(s1));
  while (getTamStack(s1))
  {
    void *ptr = getPopStack(s1);
    pushStack(nS1, ptr);
    free(ptr);
  }
  return nS1;
}

void invertStack(Stack *s1)
{
  u_long tamStack = getTamStack(s1);
  void **vetorItens = saveStackInVector(s1, &tamStack);
  pushVectorInStack(vetorItens, s1, &tamStack);
  freeVectorOfPointers(vetorItens, &tamStack);
}
