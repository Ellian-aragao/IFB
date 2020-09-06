#ifndef GETBIGGERELEMENTANDINDEXOFLINKEDLIST_H
#define GETBIGGERELEMENTANDINDEXOFLINKEDLIST_H

// retorna 1 caso encontre o item e salva no ponteiro index o indice deste elemento e o item no ponteiro do item
// 1: quando 1º parâmetro é maior que o 2º parâmetro || param1 > param2 == true
// 0: quando for falsa a comparação a cima           || param1 > param2 == false
int getBiggerElementAndIndexOfLinkedList(LinkedList *list, u_long *index, void **item, int (*compare)(void *, void *));

#endif