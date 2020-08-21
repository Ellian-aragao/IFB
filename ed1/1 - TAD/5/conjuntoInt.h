#ifndef CONJUNTOINT_H
#define CONJUNTOINT_H

#define TRUE 1
#define FALSE 0

typedef struct conjuntoInt CONJUNTO;
typedef unsigned long u_long;

int testaSePertence(CONJUNTO *conjunto, long numeroProcurado, unsigned long *index);
void insertionSort(long *vector, u_long tam);
void printConjunto(CONJUNTO *conj);
void liberaConjunto(CONJUNTO *conj);
void isNullPointer(void *ptr, const char *strError);
int testaSeoConjuntoVazio(CONJUNTO *conjunto);
u_long tamanho(CONJUNTO *conjunto);
int testaSeOsConjuntosSaoIguais(CONJUNTO *conjunto1, CONJUNTO *conjunto2);
long maior(CONJUNTO *conjunto);
long menor(CONJUNTO *conjunto);
CONJUNTO *diferenca(CONJUNTO *conj1, CONJUNTO *conj2);
CONJUNTO *interseccao(CONJUNTO *conj1, CONJUNTO *conj2);
int removeItemConjunto(CONJUNTO *conj, long itemRetirar);
CONJUNTO *uniao(CONJUNTO *conj1, CONJUNTO *conj2);
void insereItemConjunto(CONJUNTO *conjunto, long valorAdicionar);
CONJUNTO *criaConjuntoVazio();


#endif
