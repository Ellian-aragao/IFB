#ifndef GETPRODUTOMAISBARATO_H
#define GETPRODUTOMAISBARATO_H

typedef struct produtoQuestao10
{
  int codProd;
  char nomeProd[10];
  float valor;
  int qtdEstoque;
} Produto;

int getProdutoMaisBarato(LinkedList *list, Produto *produto);

#endif