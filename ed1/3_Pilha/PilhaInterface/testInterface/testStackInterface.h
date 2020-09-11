#pragma once
#include "../Stack.h"

// Cria uma Stack com tipo int variando do argumento minimo ao máximo
Stack *testCreateLinkedListWithItensInt(int minItem, int maxItem);

// Faz o teste de comparação para remoção de item 
void testRemoveItemLinkedList(Stack* list, int valueToRemove);

// Exibe todos os itens da Lista criada
void testForEachPrintItensInt(Stack* list);

// exibe o indice de um item
void testFindItemIndex(Stack *list, int itemToFind);

// comparador que retorna 0 se diferente e 1 se igual
int compareItensInt(void *item1, void *item2);