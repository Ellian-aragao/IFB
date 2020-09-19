#pragma once

#include "../../2_Listas/LinkedList/linkedList.h"

typedef LinkedList Queue;

// aloca espaço de memória para manipulação da lista encadeada
// recebe o sizeof dos itens a serem armazenados
Queue *createQueue(size_t sizeofItens);

// libera memória da fila
bool destroyQueue(Queue *queue);

// adiciona item na fila
// retorna o ponteiro para o item salvo
void *addQueue(Queue *queue, void *item);

// retorna o tamanho da fila
u_long getTamQueue(Queue *queue);

// retorna o tamanho dos itens salvos em uma fila
size_t getSizeofItensOfQueue(Queue *queue);

// retorna o ponteiro para o item da fila
void *getItemQueue(Queue *queue);

// remove item da fila
void removeQueue(Queue *queue);