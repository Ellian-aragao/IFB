#ifndef CONJUNTOINT_H
#define CONJUNTOINT_H

typedef struct conjuntoInt CONJUNTO;

void printConjunto(CONJUNTO *conj);
int testaSePertence(CONJUNTO *conjunto, long numeroProcurado, unsigned long *index);
/**
 * caso encontre, retorna 1, caso não retorna 0
*/
void liberaConjunto(CONJUNTO *conj);
#endif
