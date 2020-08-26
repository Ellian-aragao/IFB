#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef unsigned long u_long;
typedef struct listaDinamicaEncadeada LinkedList;

LinkedList *createLinkedList();
void destroyLinkedList(LinkedList *list);
void appendLinkedList(LinkedList *list, void *item);
void forEach(LinkedList *list, void (*externFunction)(void *));
void removeLinkedList(LinkedList *list, void *item, int (*compareItem)(void *, void *));

#endif