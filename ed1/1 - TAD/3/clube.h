#ifndef CLUBE_H
#define CLUBE_H

typedef struct quadra QUADRA;

QUADRA *criaListaQuadras(unsigned long quantidadeDeQuadras);
/*
 * cria uma lista básica de quadras
 */
int alugaOuLiberaQuadra(int alugaOuLibera, QUADRA *listaQuadas, unsigned long id_quadra);
/*
 * verifica um id de quadra e tenta liberar ou alugar uma quadra
 */
void listaQuadras(QUADRA *listaDeQuadras, unsigned long quantidadeDeQuadras);
/*
 * lista as quadras
 */
void liberaListaQuadras(QUADRA *quadra);
/*
 * libera a memória alocada
 */
#endif
