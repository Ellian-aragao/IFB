#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned long u_long;
typedef struct listaDinamicaEncadeada LinkedList;

// aloca espaço de memória para manipulação da lista encadeada, recebe o sizeof dos itens a serem armazenados
LinkedList *createLinkedList(size_t sizeofItens);

// libera todo o espaço da Lista, todos os nós
int destroyLinkedList(LinkedList *list);

// adiciona item no final da lista, enviar ponteiro para o dado que deseja guardar
// retorna o endereço onde o item foi salvo na lista caso a lista não seja nula
void *appendLinkedList(LinkedList *list, void *item);

// itera sobre todos os nós da lista passando como argumento o item guardado para função enviada
void forEachLinkedList(LinkedList *list, void (*externFunction)(void *));

// remove um nó da memória conforme o item passado e a função de comparação dos itens
u_long removeItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *));

// retorna o tamanho da
u_long getTamLinkedList(LinkedList *list);

// retorna o tamanho os itens salvos em uma lista
u_long getSizeofItensLinkedList(LinkedList *list);

// retorna memória alocada com valor do indice procurado, se não encontrado retorna NULL
u_long *getIndexItemLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *));

// remove item através do índice dado para a função
bool removeIndexLinkedList(LinkedList *list, u_long index);

// remove primeiro item da lista
void removeFistLinkedList(LinkedList *list);

// remove o ultimo item da lista
void removeLastLinkedList(LinkedList *list);

// realiza a troca dos itens pelo indice, retorna 1 se obter exito e 0 se falhar
bool swapItemIndexLinkedList(LinkedList *list, u_long index1, u_long index2);

// realiza a ordenação da lista com base no função passada como parâmetro
// 1: quando 1º parâmetro é maior que o 2º parâmetro || param1 > param2 == true
// 0: quando for falsa a comparação a cima           || param1 > param2 == false
bool sortLinkedList(LinkedList *list, int (*compareItens)(void *, void *));

// verifica se os itens estão ordenados com base na função enviada,
//  1: quando 1º parâmetro é maior que o 2º parâmetro || item1  >  item2
//  0: quando forem iguais                            || item1 ==  item2
// -1: quando 1º parâmetro é menor que o 2º parâmetro || item1  <  item2
bool isItensInLinkedListSorted(LinkedList *list, int (*compareItens)(void *, void *));

// retorna um ponteiro para o elemento correspondente ao indice enviado
void *getItemByIndex(LinkedList *list, u_long index);

// remove itens iguais na lista, com base no parametr devolvido da função
// 1: quando os itens forem iguais
// 0: quando os itens forem diferentes
bool removeEqualsItens(LinkedList *list, int (*compareItens)(void *, void *));