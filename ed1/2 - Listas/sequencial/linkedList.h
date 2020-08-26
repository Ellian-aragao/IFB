#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef unsigned long u_long;
typedef struct listaDinamicaEncadeada LinkedList;
typedef struct itemListaEncadeada NodeLinkedList;

LinkedList *createLinkedList();
void destroyLinkedList(LinkedList *list);
void appendLinkedList(LinkedList *list, void *item);
void forEach(LinkedList *list);

#endif