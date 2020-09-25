#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct heap Heap;

Heap *criaHeap(void *item, Heap* left_heap, Heap* right_heap);

bool destroyHeap(Heap *heap);

void *addHeap(Heap *heap, void *item);

void percorreHeap(Heap *heap, void (*externFunction)(void *));

bool isEmptyHeap(Heap *heap);

bool hasItemHeap(Heap *heap, void *item, int (*comparador)(void *, void *));

// // remove um nó da memória conforme o item passado e a função de comparação dos itens
// u_long removeItemHeap(Heap *heap, void *item, int (*compareItem)(void *, void *));

// // retorna o tamanho da heapa
// u_long getTamHeap(Heap *heap);

// // retorna o tamanho os itens salvos em uma heapa
// size_t getSizeofItensHeap(Heap *heap);

// // retorna memória alocada com valor do indice procurado, se não encontrado retorna NULL
// u_long *getIndexItemHeap(Heap *heap, void *item, int (*compareItem)(void *, void *));

// // remove item através do índice dado para a função
// bool removeIndexHeap(Heap *heap, u_long index);

// // retorna um ponteiro para o primeiro item da heapa
// void *getFistItemHeap(Heap *heap);

// // retorna um ponteiro para o ultimo item da heapa
// void *getLastItemHeap(Heap *heap);

// // remove primeiro item da heapa
// void removeFistItemHeap(Heap *heap);

// // remove o ultimo item da heapa
// void removeLastItemHeap(Heap *heap);

// // realiza a troca dos itens pelo indice, retorna 1 se obter exito e 0 se falhar
// bool swapItemIndexHeap(Heap *heap, u_long index1, u_long index2);

// // realiza a ordenação da heapa com base no função passada como parâmetro
// // 1: quando 1º parâmetro é maior que o 2º parâmetro || param1 > param2 == true
// // 0: quando for falsa a comparação a cima           || param1 > param2 == false
// bool sortHeap(Heap *heap, int (*compareItens)(void *, void *));

// // verifica se os itens estão ordenados com base na função enviada,
// //  1: quando 1º parâmetro é maior que o 2º parâmetro || item1  >  item2
// //  0: quando forem iguais                            || item1 ==  item2
// // -1: quando 1º parâmetro é menor que o 2º parâmetro || item1  <  item2
// bool isItensInHeapSorted(Heap *heap, int (*compareItens)(void *, void *));

// // retorna um ponteiro para o elemento correspondente ao indice enviado
// void *getItemByIndex(Heap *heap, u_long index);

// // remove itens iguais na heapa, com base no parametr devolvido da função
// // 1: quando os itens forem iguais
// // 0: quando os itens forem diferentes
// bool removeEqualsItens(Heap *heap, int (*compareItens)(void *, void *));

// // retorna true se os itens salvos são iguais, retorna false se são diferentes
// bool isEqualHeaps(Heap *heap1, Heap *heap2);