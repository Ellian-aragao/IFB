#pragma once

#include "../LinkedList/linkedList.h"

// percorre todos os itens da Lista e printa o dado conforme a função enviada
void printLinkedList(LinkedList* list, void (*printFunction)(void*));