#include "getProdutoMaisBarato.h"

#define getValorProduto(produto) (*(Produto *)produto).valor

int ordenarPorPreco(void *item1, void *item2)
{
  if (getValorProduto(item1) > getValorProduto(item2))
    return 1;
  return 0;
}

int getProdutoMaisBarato(LinkedList *list, Produto *produto)
{
  sortLinkedList(list, ordenarPorPreco);
  produto = getItemByIndex(list, 0);
  return produto == (void *)0 ? 0 : 1;
}
