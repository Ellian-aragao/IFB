#pragma once
#include "../../LinkedList/linkedList.h"

/**
 * Recebe duas LinkedLists, lista1 e lista2, verifica compatibilidade e
 * caso seja compatível realiza concatenação retornando uma nova
 * caso não seja compatível retorna NULL
*/
LinkedList *concatenaLinkedList(LinkedList *lista1, LinkedList *lista2);