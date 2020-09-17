#pragma once

#include "../../2_Listas/LinkedList/linkedList.h"

typedef LinkedList Stack;

// aloca espaço de memória para manipulação da lista encadeada
// recebe o sizeof dos itens a serem armazenados
Stack *createStack(size_t sizeofItens);

// libera memória da pilha
bool destroyStack(Stack *stack);

// adiciona item na pilha
// retorna o endereço onde o item foi salvo na pilha
void *pushStack(Stack *stack, void *item);

// retorna o tamanho da pilha
u_long getTamStack(Stack *stack);

// retorna o tamanho dos itens salvos em uma pilha
size_t getSizeofItensOfStack(Stack *stack);

// retorna o ponteiro para o item da pilha
void *getItemStack(Stack *stack);

// remove item da pilha
void popStack(Stack *stack);

// remove item da pilha retornando uma copia do item armazenado
void *getPopStack(Stack *stack);