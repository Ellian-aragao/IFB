#pragma once
#include "../LinkedList/linkedList.h"


// retorna 0 se não está ordenado, retorna 1 se está ordenado
// função parâmetro deve funcionar da seguinte forma
//  1: quando 1º parâmetro é maior que o 2º parâmetro || item1  >  item2
//  0: quando forem iguais                            || item1 ==  item2
// -1: quando 1º parâmetro é menor que o 2º parâmetro || item1  <  item2
int verificaSeEstaOrdenado(LinkedList *list, int (*comparadorOrdenacao)(void *, void *));