#ifndef CONJUNTOINT_H
#define CONJUNTOINT_H

#define TRUE 1
#define FALSE 0


typedef struct conjuntoInt CONJUNTO;

long menor(CONJUNTO *conjunto);
long maior(CONJUNTO *conjunto);
int testaSeOsConjuntosSaoIguais(CONJUNTO *conjunto1, CONJUNTO *conjunto2);
unsigned long tamanho(CONJUNTO *conjunto);
int testaSeoConjuntoVazio(CONJUNTO *conjunto);
void liberaConjunto(CONJUNTO *conj);
void printConjunto(CONJUNTO *conj);
int testaSePertence(CONJUNTO *conjunto, long numeroProcurado, unsigned long *index);
/**
 * caso encontre, retorna 1, caso não retorna 0
*/
void liberaConjunto(CONJUNTO *conj);
#endif
