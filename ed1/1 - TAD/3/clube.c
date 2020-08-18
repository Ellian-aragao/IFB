#include "clube.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct quadra
{
  unsigned long id_quadra;
  unsigned int alugar : 1;
};

void inicialisaListaQuadras(QUADRA *quadra, unsigned long tam_vetor)
{
  for (unsigned long i = 0; i < tam_vetor; i++)
  {
    quadra[i].id_quadra = i;
    quadra[i].alugar = FALSE;
  }
}

QUADRA *criaListaQuadras(unsigned long quantidadeDeQuadras)
{
  QUADRA *listaQuadras = (QUADRA *)malloc(quantidadeDeQuadras * sizeof(QUADRA));

  if (listaQuadras == NULL)
  {
    fprintf(stderr, "Erro ao gerar lista de quadras.\n");
    exit(0);
  }

  inicialisaListaQuadras(listaQuadras, quantidadeDeQuadras);
  return listaQuadras;
}

void liberaListaQuadras(QUADRA *quadra)
{
  free(quadra);
}

int alugaOuLiberaQuadra(int alugaOuLibera, QUADRA *listaQuadas, unsigned long id_quadra)
{
  if (alugaOuLibera > 1 || alugaOuLibera < 0)
  {
    fprintf(stderr, "tipo de ação indefinida, use 0 para liberar e 1 para alugar\n");
    return FALSE;
  }

  if (listaQuadas[id_quadra].alugar != alugaOuLibera)
  {
    listaQuadas[id_quadra].alugar = alugaOuLibera;
    return TRUE;
  }

  fprintf(stderr, "ação inválida, a quadra %ld já foi %s\n", id_quadra, alugaOuLibera ? "Alugada" : "Liberada");
  return FALSE;
}

void listaQuadras(QUADRA *listaDeQuadras, unsigned long quantidadeDeQuadras)
{
  for (unsigned long i = 0; i < quantidadeDeQuadras; i++)
  {
    printf("Quadra -> %ld, status -> %s\n", listaDeQuadras[i].id_quadra, listaDeQuadras[i].alugar ? "Ocupado" : "Livre");
  }
}
