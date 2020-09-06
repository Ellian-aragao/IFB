#include "../LinkedList/linkedList.h"
#include "getProdutoMaisBarato.h"
#include <stdio.h>

void printProduto(void *ptrProduto)
{
  Produto *p = ptrProduto;
  char limiter[] = "-------------------";
  puts(limiter);
  printf("cod: %d\nnome: %s\nvalor: %f\nquantidade %d\n", p->codProd, p->nomeProd, p->valor, p->qtdEstoque);
  puts(limiter);
}

int main(int argc, char const *argv[])
{
  LinkedList *produtos = createLinkedList(sizeof(Produto));
  for (float i = 10; i > 0; i--)
  {
    Produto prod = {
        i,
        "prodTeste",
        i * 2 / 3,
        i + 5
    };
    appendLinkedList(produtos, &prod);
  }
 
  forEachItem(produtos, printProduto);
  Produto p;
  getProdutoMaisBarato(produtos, &p);
  puts("produto mais barato");
  printProduto(&p);

  return 0;
}
