#pragma once
#include "../LinkedList/linkedList.h"

// retorna uma nova linkedList com os itens copiados, exeto os repetidos
// função parametro deve devolver
// 1: quando os itens forem iguais
// 0: quando os itens forem diferentes
LinkedList *copySemRepeticaoLinkedList(LinkedList *listToCopy, int (*compare)(void *, void *));