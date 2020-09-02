#ifndef CONCATENALINKEDLIST_H
#define CONCATENALINKEDLIST_H
#ifndef LINKEDLIST_H
#include "../../LinkedList/linkedList.h"
#endif

/**
 * Recebe duas LinkedLists, verifica compatibilidade e
 * realiza concatenação retornando uma nova
*/
LinkedList *concatenaLinkedList(LinkedList *lista1, LinkedList *lista2);

#endif