#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef unsigned long u_long;
typedef struct listaDinamicaEncadeada LinkedList;

// aloca espaço de memória para manipulação da lista encadeada, recebe o sizeof dos itens a serem armazenados
LinkedList *createLinkedList(u_long sizeofItens);

// libera todo o espaço da Lista, todos os nós
void destroyLinkedList(LinkedList *list);

// adiciona item no final da lista, enviar ponteiro para memória alocada do tipo de dado que deseja guardar
void appendLinkedList(LinkedList *list, void *item);

// itera sobre todos os nós da lista passando como argumento para função enviada
void forEachItem(LinkedList *list, void (*externFunction)(void *));

// itera sobre todos os nós retornando um ponteiro para eles
void forEachNode(LinkedList *list, void (*externFunction)(void *));

// remove um nó da memória conforme o item passado e a função de comparação dos itens
void removeItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *));

// retorna o tamanho da
u_long getTamLinkedList(LinkedList *list);

// retorna o tamanho os itens salvos em uma lista
u_long getSizeofItensLinkedList(LinkedList *list);

// retorna memória alocada com valor do indice procurado
u_long *getIndexItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *));

// remove item através do índice dado para a função
void removeIndexLinkedList(LinkedList *list, u_long index);

#endif