#ifndef TESTLINKEDLISTINTERFACE_H
#define TESTLINKEDLISTINTERFACE_H

// Cria uma LinkedList com tipo int variando do argumento minimo ao máximo
LinkedList *testCreateLinkedListWithItensInt(int minItem, int maxItem);

// Faz o teste de comparação para remoção de item 
void testRemoveItemLinkedList(LinkedList* list, int valueToRemove);

// Exibe todos os itens da Lista criada
void testForEachPrintItensInt(LinkedList* list);

// exibe o indice de um item
void testFindItemIndex(LinkedList *list, int itemToFind);

// comparador que retorna 0 se diferente e 1 se igual
int compareItensInt(void *item1, void *item2);
#endif