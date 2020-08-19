#include "listaULong.h"
#include <stdio.h>
#include <stdlib.h>

struct listaULong
{
  u_long nodeValue;
  LISTAULONG *nextNode;
};

LISTAULONG *criaListaULong(u_long valor)
{
  LISTAULONG *node = malloc(sizeof(LISTAULONG));
  if (node == NULL)
  {
    perror("Erro na criação da lista u_long\n");
    return NULL;
  }

  node->nodeValue = valor;
  node->nextNode = NULL;
  return node;
}

void liberaListaULong(LISTAULONG *node)
{
  if (node->nextNode != NULL)
  {
    LISTAULONG *nextNode = node->nextNode;
    free(node);
    liberaListaULong(nextNode);
  }
  free(node);
}

void insereListaULong(LISTAULONG *nodeInicial, u_long valor)
{
  if (nodeInicial->nextNode != NULL)
  {
    insereListaULong(nodeInicial->nextNode, valor);
  }
  LISTAULONG *nextNodeToAppend = criaListaULong(valor);
  if (nextNodeToAppend == NULL)
  {
    perror("Erro na inserção da lista u_long\n");
  }
  nodeInicial->nextNode = nextNodeToAppend;
}

void mostraItemLista(LISTAULONG *nodeInicial)
{
  if (nodeInicial->nextNode != NULL)
  {
    printf("%ld,", nodeInicial->nodeValue);
    mostraItemLista(nodeInicial->nextNode);
  }
  printf("%ld.\n", nodeInicial->nodeValue);
}

u_long getTamanhoListaULong(LISTAULONG *nodeInicial)
{
  return nodeInicial->nextNode == NULL ? 1 : 1 + getTamanhoListaULong(nodeInicial->nextNode);
}

int main(int argc, char const *argv[])
{
  LISTAULONG *testeLista = criaListaULong(0);
  for (u_long i = 1; i < 5; i++)
  {
    insereListaULong(testeLista, i);
  }
  mostraItemLista(testeLista);
  printf("tamanho da lista -> %ld\n", getTamanhoListaULong(testeLista));
  return 0;
}
