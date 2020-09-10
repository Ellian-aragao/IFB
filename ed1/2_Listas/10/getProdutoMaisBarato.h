#pragma once
#include "../LinkedList/linkedList.h"

typedef struct produtoQuestao10
{
  int codProd;
  char nomeProd[10];
  float valor;
  int qtdEstoque;
} Produto;

int getProdutoMaisBarato(LinkedList *list, Produto *produto);