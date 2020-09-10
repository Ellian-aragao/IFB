#pragma once
#include "../LinkedList/linkedList.h"

// junta as listas ordenadas com base na função parametro enviada seguindo o critério para crescente
// 1: quando 1º parâmetro é maior que o 2º parâmetro || param1 > param2 == true
// 0: quando for falsa a comparação a cima           || param1 > param2 == false
int mergeLinkedListSort(LinkedList *list_final, LinkedList *list_to_merge, int (*compareItens)(void *, void *));

// junta as duas listas
int mergeLinkedList(LinkedList *list_final, LinkedList *list_to_merge);