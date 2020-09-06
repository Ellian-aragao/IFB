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

// retorna memória alocada com valor do indice procurado, se não encontrado retorna NULL
u_long *getIndexItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *));

// remove item através do índice dado para a função
void removeIndexLinkedList(LinkedList *list, u_long index);

// remove primeiro item da lista
void removeFistLinkedList(LinkedList* list);

// remove o ultimo item da lista
void removeLastLinkedList(LinkedList* list);

// realiza a troca dos itens pelo indice, retorna 1 se obter exito e 0 se falhar
int swapItemIndexLinkedList(LinkedList *list, u_long index1, u_long index2);

// realiza a ordenação da lista com base no função passada como parâmetro
// 1: quando 1º parâmetro é maior que o 2º parâmetro || param1 > param2 == true
// 0: quando for falsa a comparação a cima           || param1 > param2 == false
void sortLinkedList(LinkedList *list, int (*compareItens)(void *, void *));

// retorna um ponteiro para o elemento correspondente ao indice enviado
void *getItemByIndex(LinkedList* list, u_long index);

#endif