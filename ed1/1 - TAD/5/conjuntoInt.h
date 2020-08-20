#ifndef CONJUNTOINT_H
#define CONJUNTOINT_H

#define TRUE 1
#define FALSE 0

typedef struct conjuntoInt CONJUNTO;

// long menor(CONJUNTO *conjunto);
// long maior(CONJUNTO *conjunto);
// int testaSeOsConjuntosSaoIguais(CONJUNTO *conjunto1, CONJUNTO *conjunto2);
// u_long tamanho(CONJUNTO *conjunto);
// int testaSeoConjuntoVazio(CONJUNTO *conjunto);
// void liberaConjunto(CONJUNTO *conj);
void printConjunto(CONJUNTO *conj);
// u_long testaSePertence(long *vetor, u_long limiteInferior, u_long limiteSuperior, long numeroProcurado);
/**
 * caso encontre, retorna 1, caso não retorna 0
*/
void liberaConjunto(CONJUNTO *conj);
#endif
