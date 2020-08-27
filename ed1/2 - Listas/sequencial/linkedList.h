#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef unsigned long u_long;
typedef struct listaDinamicaEncadeada LinkedList;

// aloca espaço de memória para manipulação da lista encadeada
LinkedList *createLinkedList();

// libera todo o espaço da Lista, todos os nós
void destroyLinkedList(LinkedList *list);

// adiciona item no final da lista, enviar ponteiro para memória alocada do tipo de dado que deseja guardar
void appendLinkedList(LinkedList *list, void *item);

// itera sobre todos os nós da lista passando como argumento para função enviada
void forEach(LinkedList *list, void (*externFunction)(void *));

// remove um nó da memória conforme o item passado e a função de comparação dos itens
void removeLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *));

#endif