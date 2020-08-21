#ifndef CONJUNTOINT_H
#define CONJUNTOINT_H

typedef struct conjuntoInt CONJUNTO;
typedef unsigned long u_long;

/**
 * retorna ponteiro para o conjunto vazio
 **/
CONJUNTO *newConjuntoVazio();


/**
 * retorna ponteiro para um conjunto que não possui itens em comum aos 2 passados
 **/
CONJUNTO *diferencaConjunto(CONJUNTO *conj1, CONJUNTO *conj2);


/**
 * retorna ponteiro para um conjunto que possui itens em comum aos 2 passados
 **/
CONJUNTO *interseccaoConjunto(CONJUNTO *conj1, CONJUNTO *conj2);


/**
 * retorna ponteiro para um conjunto que possui todos os itens existentes nos 2 passados
 **/
CONJUNTO *uniaoConjunto(CONJUNTO *conj1, CONJUNTO *conj2);


/**
 * retorna 1 caso encontre o número procurado, grava o indíce do numero procurado pelo index
 * retorna 0 caso não encontre o número procurado
 **/
int testaSePertence(CONJUNTO *conjunto, long numeroProcurado, unsigned long *index);


/**
 *  exibe o conjunto no terminal, todos os itens separados por virgula,
 *  em caso de conjunto vazio retorna {}
 **/
void printConjunto(CONJUNTO *conj);


/**
 * libera a memória alocada de cada conjunto criado
 **/
void freeConjunto(CONJUNTO *conj);


/**
 * retorna 1 caso conjunto seja vazio
 * retorna 0 caso contenha itens
 **/
int isConjuntoVazio(CONJUNTO *conjunto);


/**
 * retorna o tamanho do conjunto
 **/
u_long lenConjunto(CONJUNTO *conjunto);


/**
 * retorna 1 para conjuntos iguais
 * retorna 0 para conjuntos diferentes
 **/
int isEqualConjuntos(CONJUNTO *conjunto1, CONJUNTO *conjunto2);


/**
 * retorna o maior item do conjunto
 **/
long maior(CONJUNTO *conjunto);


/**
 * retorna o menor item do conjunto
 **/
long menor(CONJUNTO *conjunto);


/**
 * retorna 1 caso remova item do conjunto
 * retorna 0 caso não encontre o item
 **/
int removeItemConjunto(CONJUNTO *conj, long itemRetirar);


/**
 * retorna 1 caso insera item no conjunto
 * retorna 0 caso item já seja existente no conjunto
 **/
int insereItemConjunto(CONJUNTO *conjunto, long valorAdicionar);


#endif
