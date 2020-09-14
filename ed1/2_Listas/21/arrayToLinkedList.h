#pragma once
#include "../LinkedList/linkedList.h"

// recebe endereço do primeiro item do array, numero de itens a copiar, e sizeof dos itens do array
LinkedList *arrayToLinked(void *initArray, u_long nItens ,size_t sizeOfItens);