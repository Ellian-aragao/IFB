#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Produto
{
  int matricula;
  float preco;
} Produto;

typedef struct No
{
  Produto p;
  No *left;
  No *right;
} No;

No **create_heap();
int adicionar(No **heap, int matricula, float preco);
void preco(No **heap, int matricula);
int nodes_heap(No **heap);
int num_folhas(No **heap);
int tam_heap(No **heap);
int maior_preco(No **heap);
int remove_heap(No **heap, int matricula);
int verifica_avl(No **heap);

#endif