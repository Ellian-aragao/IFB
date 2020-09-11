#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct listaDinamicaEncadeada Stack;

// aloca espaço de memória para manipulação da lista encadeada, recebe o sizeof dos itens a serem armazenados
Stack *createStack(size_t sizeofItens);

// libera todo o espaço da Lista, todos os nós
int destroyStack(Stack *stack);

// adiciona item no final da lista, enviar ponteiro para o dado que deseja guardar
// retorna o endereço onde o item foi salvo na lista caso a lista não seja nula
void *pushStack(Stack *stack, void *item);

// retorna o tamanho da
u_long getTamStack(Stack *stack);

// retorna o tamanho os itens salvos em uma lista
size_t getSizeofItensOfStack(Stack *stack);

// retorna um ponteiro para o ultimo item da lista
void *getItemStack(Stack *stack);

// remove o ultimo item da lista
void popStack(Stack *stack);